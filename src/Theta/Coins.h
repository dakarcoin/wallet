// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../uint256.h"

namespace TW::Theta {

class Coins {
  public:
    uint256_t thetaWei;
    uint256_t tfuelWei;

    Coins() = default;
    Coins(uint256_t thetaWei, uint256_t tfuelWei)
        : thetaWei(std::move(thetaWei)), tfuelWei(std::move(tfuelWei)) {}
};

} // namespace TW::Theta
