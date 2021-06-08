// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "TransactionOutput.h"

#include "../BinaryCoding.h"

using namespace TW::Bitcoin;

void TransactionOutput::encode(std::vector<uint8_t>& data) const {
    encode64LE(value, data);
    script.encode(data);
}
