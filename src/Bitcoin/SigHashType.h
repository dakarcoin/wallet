// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <DakarWalletCore/TWBitcoinSigHashType.h>
#include <DakarWalletCore/TWCoinType.h>

namespace TW::Bitcoin {

// Defines the number of bits of the hash type which is used to identify which
// outputs are signed.
static const uint8_t SigHashMask = 0x1f;

// Return the default HashType for the given coin, such as TWBitcoinSigHashTypeAll.
inline uint32_t hashTypeForCoin(enum TWCoinType coinType) {
    // set fork hash type for BCH
    switch (coinType) {
        case TWCoinTypeBitcoinCash:
            return (uint32_t)TWBitcoinSigHashTypeAll | (uint32_t)TWBitcoinSigHashTypeFork;
        case TWCoinTypeBitcoinGold:
            return (uint32_t)TWBitcoinSigHashTypeAll | (uint32_t)TWBitcoinSigHashTypeForkBTG;
        default:
            return TWBitcoinSigHashTypeAll;
    }
}

inline bool hashTypeIsSingle(enum TWBitcoinSigHashType type) { return (type & SigHashMask) == TWBitcoinSigHashTypeSingle; }

inline bool hashTypeIsNone(enum TWBitcoinSigHashType type) { return (type & SigHashMask) == TWBitcoinSigHashTypeNone; }

} // namespace TW::Bitcoin
