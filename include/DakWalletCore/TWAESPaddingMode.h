// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_ENUM(uint32_t)
enum TWAESPaddingMode {
    TWAESPaddingModeZero = 0,   // padding value is zero
    TWAESPaddingModePKCS7 = 1,  // padding value is the number of padding bytes; for even size add an extra block
};

TW_EXTERN_C_END
