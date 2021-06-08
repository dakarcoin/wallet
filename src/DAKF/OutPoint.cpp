// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "OutPoint.h"

#include "../BinaryCoding.h"

using namespace TW::DAKF;

void OutPoint::encode(Data& data) const {
    std::copy(std::begin(hash), std::end(hash), std::back_inserter(data));
    encode32LE(index, data);
    data.push_back(static_cast<byte>(tree));
}
