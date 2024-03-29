// Copyright © 2017-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <tuple>
#include "PrivateKey.h"
#include "PublicKey.h"

namespace TW {

typedef std::tuple<PrivateKey, PublicKey> KeyPair;

} // namespace
