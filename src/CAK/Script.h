// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
#pragma once

#include "../Data.h"

namespace TW::CAK {

class Script {
  public:
    static Data CreateSignatureRedeemScript(const Data& publicKey);
    static Data CreateInvocationScript(const Data& signature);
};

} // namespace TW::CAK
