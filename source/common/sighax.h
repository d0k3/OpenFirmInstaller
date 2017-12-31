#pragma once

#include "common.h"

// see https://gist.github.com/SciresM/cdd2266efb80175d37eabbe86f9d8c52 for source
// thanks SciresM, Myria, Normmatt, TuxSH and hedgeberg for the signatures!

u8 sig_nand_firm_retail[256] = {
    0xB6, 0x72, 0x45, 0x31, 0xC4, 0x48, 0x65, 0x7A, 0x2A, 0x2E, 0xE3, 0x06, 0x45, 0x7E, 0x35, 0x0A,
    0x10, 0xD5, 0x44, 0xB4, 0x28, 0x59, 0xB0, 0xE5, 0xB0, 0xBE, 0xD2, 0x75, 0x34, 0xCC, 0xCC, 0x2A,
    0x4D, 0x47, 0xED, 0xEA, 0x60, 0xA7, 0xDD, 0x99, 0x93, 0x99, 0x50, 0xA6, 0x35, 0x7B, 0x1E, 0x35,
    0xDF, 0xC7, 0xFA, 0xC7, 0x73, 0xB7, 0xE1, 0x2E, 0x7C, 0x14, 0x81, 0x23, 0x4A, 0xF1, 0x41, 0xB3,
    0x1C, 0xF0, 0x8E, 0x9F, 0x62, 0x29, 0x3A, 0xA6, 0xBA, 0xAE, 0x24, 0x6C, 0x15, 0x09, 0x5F, 0x8B,
    0x78, 0x40, 0x2A, 0x68, 0x4D, 0x85, 0x2C, 0x68, 0x05, 0x49, 0xFA, 0x5B, 0x3F, 0x14, 0xD9, 0xE8,
    0x38, 0xA2, 0xFB, 0x9C, 0x09, 0xA1, 0x5A, 0xBB, 0x40, 0xDC, 0xA2, 0x5E, 0x40, 0xA3, 0xDD, 0xC1,
    0xF5, 0x8E, 0x79, 0xCE, 0xC9, 0x01, 0x97, 0x43, 0x63, 0xA9, 0x46, 0xE9, 0x9B, 0x43, 0x46, 0xE8,
    0xA3, 0x72, 0xB6, 0xCD, 0x55, 0xA7, 0x07, 0xE1, 0xEA, 0xB9, 0xBE, 0xC0, 0x20, 0x0B, 0x5B, 0xA0,
    0xB6, 0x61, 0x23, 0x6A, 0x87, 0x08, 0xD7, 0x04, 0x51, 0x7F, 0x43, 0xC6, 0xC3, 0x8E, 0xE9, 0x56,
    0x01, 0x11, 0xE1, 0x40, 0x5E, 0x5E, 0x8E, 0xD3, 0x56, 0xC4, 0x9C, 0x4F, 0xF6, 0x82, 0x3D, 0x12,
    0x19, 0xAF, 0xAE, 0xEB, 0x3D, 0xF3, 0xC3, 0x6B, 0x62, 0xBB, 0xA8, 0x8F, 0xC1, 0x5B, 0xA8, 0x64,
    0x8F, 0x93, 0x33, 0xFD, 0x9F, 0xC0, 0x92, 0xB8, 0x14, 0x6C, 0x3D, 0x90, 0x8F, 0x73, 0x15, 0x5D,
    0x48, 0xBE, 0x89, 0xD7, 0x26, 0x12, 0xE1, 0x8E, 0x4A, 0xA8, 0xEB, 0x9B, 0x7F, 0xD2, 0xA5, 0xF7,
    0x32, 0x8C, 0x4E, 0xCB, 0xFB, 0x00, 0x83, 0x83, 0x3C, 0xBD, 0x5C, 0x98, 0x3A, 0x25, 0xCE, 0xB8,
    0xB9, 0x41, 0xCC, 0x68, 0xEB, 0x01, 0x7C, 0xE8, 0x7F, 0x5D, 0x79, 0x3A, 0xCA, 0x09, 0xAC, 0xF7
};

u8 sig_nand_firm_dev[256] = {
    0x88, 0x69, 0x7C, 0xDC, 0xA9, 0xD1, 0xEA, 0x31, 0x82, 0x56, 0xFC, 0xD9, 0xCE, 0xD4, 0x29, 0x64,
    0xC1, 0xE9, 0x8A, 0xBC, 0x64, 0x86, 0xB2, 0xF1, 0x28, 0xEC, 0x02, 0xE7, 0x1C, 0x5A, 0xE3, 0x5D,
    0x63, 0xD3, 0xBF, 0x12, 0x46, 0x13, 0x40, 0x81, 0xAF, 0x68, 0x75, 0x47, 0x87, 0xFC, 0xB9, 0x22,
    0x57, 0x1D, 0x7F, 0x61, 0xA3, 0x0D, 0xE4, 0xFC, 0xFA, 0x82, 0x93, 0xA9, 0xDA, 0x51, 0x23, 0x96,
    0xF1, 0x31, 0x9A, 0x36, 0x49, 0x68, 0x46, 0x4C, 0xA9, 0x80, 0x6E, 0x0A, 0x52, 0x56, 0x74, 0x86,
    0x75, 0x4C, 0xDD, 0xD4, 0xC3, 0xA6, 0x2B, 0xDC, 0xE2, 0x55, 0xE0, 0xDE, 0xEC, 0x23, 0x01, 0x29,
    0xC1, 0xBA, 0xE1, 0xAE, 0x95, 0xD7, 0x86, 0x86, 0x56, 0x37, 0xC1, 0xE6, 0x5F, 0xAE, 0x83, 0xED,
    0xF8, 0xE7, 0xB0, 0x7D, 0x17, 0xC0, 0xAA, 0xDA, 0x8F, 0x05, 0x5B, 0x64, 0x0D, 0x45, 0xAB, 0x0B,
    0xAC, 0x76, 0xFF, 0x7B, 0x34, 0x39, 0xF5, 0xA4, 0xBF, 0xE8, 0xF7, 0xE0, 0xE1, 0x03, 0xBC, 0xE9,
    0x95, 0xFA, 0xD9, 0x13, 0xFB, 0x72, 0x9D, 0x3D, 0x03, 0x0B, 0x26, 0x44, 0xEC, 0x48, 0x39, 0x64,
    0x24, 0xE0, 0x56, 0x3A, 0x1B, 0x3E, 0x6A, 0x1F, 0x68, 0x0B, 0x39, 0xFC, 0x14, 0x61, 0x88, 0x6F,
    0xA7, 0xA6, 0x0B, 0x6B, 0x56, 0xC5, 0xA8, 0x46, 0x55, 0x4A, 0xE6, 0x48, 0xFC, 0x46, 0xE3, 0x0E,
    0x24, 0x67, 0x8F, 0xAF, 0x1D, 0xC3, 0xCE, 0xB1, 0x0C, 0x2A, 0x95, 0x0F, 0x4F, 0xFA, 0x20, 0x83,
    0x23, 0x4E, 0xD8, 0xDC, 0xC3, 0x58, 0x7A, 0x6D, 0x75, 0x1A, 0x7E, 0x9A, 0xFA, 0x06, 0x15, 0x69,
    0x55, 0x08, 0x4F, 0xF2, 0x72, 0x5B, 0x69, 0x8E, 0xB1, 0x74, 0x54, 0xD9, 0xB0, 0x2B, 0x6B, 0x76,
    0xBE, 0x47, 0xAB, 0xBE, 0x20, 0x62, 0x94, 0x36, 0x69, 0x87, 0xA4, 0xCA, 0xB4, 0x2C, 0xBD, 0x0B
};