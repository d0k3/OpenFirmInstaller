#pragma once

#include <inttypes.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

#define vu8 volatile u8
#define vu16 volatile u16
#define vu32 volatile u32
#define vu64 volatile u64

#define max(a,b) \
    (((a) > (b)) ? (a) : (b))
#define min(a,b) \
    (((a) < (b)) ? (a) : (b))
#define getbe16(d) \
    (((d)[0]<<8) | (d)[1])
#define getbe32(d) \
    ((((u32) getbe16(d))<<16) | ((u32) getbe16(d+2)))
#define getbe64(d) \
    ((((u64) getbe32(d))<<32) | ((u64) getbe32(d+4)))
#define getle16(d) \
    (((d)[1]<<8) | (d)[0])
#define getle32(d) \
    ((((u32) getle16(d+2))<<16) | ((u32) getle16(d)))
#define getle64(d) \
    ((((u64) getle32(d+4))<<32) | ((u64) getle32(d)))
#define align(v,a) \
    (((v) % (a)) ? ((v) + (a) - ((v) % (a))) : (v))

// OpenFirmInstaller version
#define VERSION     "0.0.9"

// names of the installable FIRMs
#define NAME_B9S    "boot9strap"
#define NAME_FB3DS  "fastboot3ds"

// input / output paths
#define INPUT_PATH  "0:/" "OFI"

// cosmetic stuff (for installer status)
#define APP_TITLE   "OpenFirmInstaller" " v" VERSION
#define APP_URL     "https://github.com/d0k3/OpenFirmInstaller"
#define APP_USAGE   "Based on SafeB9SInstaller by d0k3"

// buffer area defines (big buffer for firm)
#define WORK_BUFFER         ((u8*) 0x21000000)
#define WORK_BUFFER_SIZE    (0x400000)
#define FIRM_BUFFER         ((u8*) 0x21400000)
#define FIRM_BUFFER_SIZE    (0x400000)
#define NAND_BUFFER         ((u8*) 0x21800000)
#define NAND_BUFFER_SIZE    (0x100000)

// testing flags, only useful to devs
// #define NO_WRITE     // disables all NAND writes, just for testing
// #define FAIL_TEST    // to test the emergency screen, only works with NO_TRANSFER defined

inline u32 strchrcount(const char* str, char symbol) {
    u32 count = 0;
    for (u32 i = 0; str[i] != '\0'; i++) {
        if (str[i] == symbol)
            count++;
    }
    return count;
}
