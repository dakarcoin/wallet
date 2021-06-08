// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_ENUM(uint16_t)
enum TWStellarVersionByte {
    TWStellarVersionByteAccountID = 0x30, // G
    TWStellarVersionByteSeed = 0xc0, // S
    TWStellarVersionBytePreAuthTX = 0xc8, // T
    TWStellarVersionByteSHA256Hash = 0x118, // X
};

TW_EXTERN_C_END
