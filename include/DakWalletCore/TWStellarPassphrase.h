// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_ENUM()
enum TWStellarPassphrase {
    TWStellarPassphraseStellar     /* "Public Global Stellar Network ; September 2015" */,
    TWStellarPassphraseKin         /* "Kin Mainnet ; December 2018" */,
};

static const char *_Nonnull TWStellarPassphrase_Stellar = "Public Global Stellar Network ; September 2015";
static const char *_Nonnull TWStellarPassphrase_Kin = "Kin Mainnet ; December 2018";

TW_EXTERN_C_END
