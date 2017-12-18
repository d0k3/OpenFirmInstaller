#pragma once

#include "common.h"

#define FIRM_UNK    0
#define FIRM_FB3DS  1
#define FIRM_B9S    2

u32 ValidateFirm(void* firm, u8* firm_sha, u32 firm_size, char* output);
u32 ValidateFirmSignature(void* firm, const u8* pubkey);
u32 ValidateSector(void* sector);
u32 CheckFirmSigHax(void* firm);
u32 CheckFirmPayload(void* firm);
