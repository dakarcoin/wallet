// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWString.h"
#include "TWCoinType.h"

TW_EXTERN_C_BEGIN

/// Account for a particular coin within a wallet.
TW_EXPORT_CLASS
struct TWAccount;

TW_EXPORT_STATIC_METHOD
struct TWAccount *_Nonnull TWAccountCreate(TWString *_Nonnull address, enum TWCoinType coin, TWString *_Nonnull derivationPath, TWString *_Nonnull extendedPublicKey);

TW_EXPORT_METHOD
void TWAccountDelete(struct TWAccount *_Nonnull account);

TW_EXPORT_PROPERTY
TWString *_Nonnull TWAccountAddress(struct TWAccount *_Nonnull account);

TW_EXPORT_PROPERTY
TWString *_Nonnull TWAccountDerivationPath(struct TWAccount *_Nonnull account);

TW_EXPORT_PROPERTY
TWString *_Nonnull TWAccountExtendedPublicKey(struct TWAccount *_Nonnull account);

TW_EXPORT_PROPERTY
enum TWCoinType TWAccountCoin(struct TWAccount *_Nonnull account);

TW_EXTERN_C_END
