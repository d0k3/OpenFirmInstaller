/*
 *   This file is part of fastboot 3DS
 *   Copyright (C) 2017 derrek, profi200
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "common.h"
#include "rsa.h"



//////////////////////////////////
//             SHA              //
//////////////////////////////////

#define SHA_REGS_BASE   (0x10000000 + 0xA000)
#define REG_SHA_CNT     *((vu32*)(SHA_REGS_BASE + 0x00))
#define REG_SHA_BLKCNT  *((vu32*)(SHA_REGS_BASE + 0x04))
#define REG_SHA_HASH     ((u32* )(SHA_REGS_BASE + 0x40))
#define REG_SHA_INFIFO   (       (SHA_REGS_BASE + 0x80))


void SHA_start(u8 params)
{
	REG_SHA_CNT = (u32)params | SHA_ENABLE;
}

void SHA_update(const u32 *data, u32 size)
{
	while(size >= 0x40)
	{
		for(u32 i = 0; i < 4; i++)
		{
			((vu32*)REG_SHA_INFIFO)[0 + i] = *data++;
			((vu32*)REG_SHA_INFIFO)[1 + i] = *data++;
			((vu32*)REG_SHA_INFIFO)[2 + i] = *data++;
			((vu32*)REG_SHA_INFIFO)[3 + i] = *data++;
		}
		while(REG_SHA_CNT & SHA_ENABLE);

		size -= 0x40;
	}

	if(size) memcpy((void*)REG_SHA_INFIFO, data, size);
}

void SHA_finish(u32 *const hash, u8 endianess)
{
	REG_SHA_CNT = (REG_SHA_CNT & (SHA_MODE_1 | SHA_MODE_224 | SHA_MODE_256)) | (u32)endianess | SHA_PAD_INPUT;
	while(REG_SHA_CNT & SHA_ENABLE);

	u32 hashSize;
	switch(REG_SHA_CNT & (SHA_MODE_1 | SHA_MODE_224 | SHA_MODE_256))
	{
		case SHA_MODE_256:
			hashSize = 8; // 32;
			break;
		case SHA_MODE_224:
			hashSize = 7; // 28;
			break;
		case SHA_MODE_1:
			hashSize = 5; // 20;
			break;
		default:
			return;
	}

	for(u32 i = 0; i < hashSize; i++) hash[i] = REG_SHA_HASH[i];
}

void sha(const u32 *data, u32 size, u32 *const hash, u8 params, u8 hashEndianess)
{
	SHA_start(params);
	SHA_update(data, size);
	SHA_finish(hash, hashEndianess);
}



//////////////////////////////////
//             RSA              //
//////////////////////////////////

#define RSA_REGS_BASE   (0x10000000 + 0xB000)
#define REG_RSA_CNT     *((vu32*)(RSA_REGS_BASE + 0x000))
#define REG_RSA_UNK_F0  *((vu32*)(RSA_REGS_BASE + 0x0F0))
#define REGs_RSA_SLOT0   ((vu32*)(RSA_REGS_BASE + 0x100))
#define REGs_RSA_SLOT1   ((vu32*)(RSA_REGS_BASE + 0x110))
#define REGs_RSA_SLOT2   ((vu32*)(RSA_REGS_BASE + 0x120))
#define REGs_RSA_SLOT3   ((vu32*)(RSA_REGS_BASE + 0x130))
#define rsaSlots         ((RsaSlot*)(RSA_REGS_BASE + 0x100))
#define REG_RSA_EXP      ((vu32*)(RSA_REGS_BASE + 0x200))
#define REG_RSA_MOD      (       (RSA_REGS_BASE + 0x400))
#define REG_RSA_TXT      (       (RSA_REGS_BASE + 0x800))

typedef struct
{
	vu32 REG_RSA_SLOTCNT;
	vu32 REG_RSA_SLOTSIZE;
	vu32 REG_RSA_SLOT_UNK_0x8;
	vu32 REG_RSA_SLOT_UNK_0xC;
} RsaSlot;


void RSA_init(void)
{
	REG_RSA_UNK_F0 = 0;
}

static void rsaWaitBusy(void)
{
	while(REG_RSA_CNT & RSA_ENABLE);
}

void RSA_selectKeyslot(u8 keyslot)
{
	rsaWaitBusy();
	REG_RSA_CNT = (REG_RSA_CNT & ~RSA_KEYSLOT(0xFu)) | RSA_KEYSLOT(keyslot);
}

bool RSA_setKey2048(u8 keyslot, const u8 *const mod, u32 exp)
{
	RsaSlot *slot = &rsaSlots[keyslot];
	rsaWaitBusy();
	if(slot->REG_RSA_SLOTCNT & RSA_KEY_WR_PROT) return false;
	// Unset key if bit 31 is not set. No idea why but boot9 does this.
	if(!(slot->REG_RSA_SLOTCNT & RSA_KEY_UNK_BIT31)) slot->REG_RSA_SLOTCNT &= ~RSA_KEY_STAT_SET;

	REG_RSA_CNT = RSA_INPUT_NORMAL | RSA_INPUT_BIG | RSA_KEYSLOT(keyslot);
	memset((void*)REG_RSA_EXP, 0, 0x100 - 4);
	REG_RSA_EXP[(0x100>>2) - 1] = exp;

	if(slot->REG_RSA_SLOTSIZE != RSA_SLOTSIZE_2048) return false;
	memcpy((void*)REG_RSA_MOD, mod, 0x100);

	return true;
}

bool RSA_decrypt2048(void *const decSig, const void *const encSig)
{
	const u8 keyslot = RSA_GET_KEYSLOT;
	rsaWaitBusy();
	if(!(rsaSlots[keyslot].REG_RSA_SLOTCNT & RSA_KEY_STAT_SET)) return false;

	REG_RSA_CNT |= RSA_INPUT_NORMAL | RSA_INPUT_BIG;
	memcpy((void*)REG_RSA_TXT, encSig, 0x100);

	REG_RSA_CNT |= RSA_ENABLE;
	rsaWaitBusy();
	memcpy(decSig, (void*)REG_RSA_TXT, 0x100);

	return true;
}

bool RSA_verify2048(const u32 *const encSig, const u32 *const data, u32 size)
{
	u8 decSig[0x100];
	if(!RSA_decrypt2048(decSig, encSig)) return false;

	if(decSig[0] != 0x00 || decSig[1] != 0x01) return false;

	u32 read = 2;
	while(read < 0x100)
	{
		if(decSig[read] != 0xFF) break;
		read++;
	}
	if(read != 0xCC || decSig[read] != 0x00) return false;

	// ASN.1 is a clusterfuck so we skip parsing the remaining headers
	// and hardcode the hash location.

	u8 __attribute__((aligned(4))) hash[32];
	sha(data, size, (u32*)(void*)hash, SHA_INPUT_BIG | SHA_MODE_256, SHA_OUTPUT_BIG);

	// Compare hash
	u8 res = 0;
	for(u32 i = 0; i < 32; i++)
	{
		u8 tmp;
		if(decSig[0xE0 + i] == hash[i]) tmp = 0;
		else tmp = 1;

		res |= tmp;
	}

	return res == 0;
}
