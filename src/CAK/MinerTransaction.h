// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"
#include "Transaction.h"

namespace TW::CAK {

class MinerTransaction : public Transaction {
  public:
    uint32_t nonce;

     virtual int deserializeExclusiveData(const Data& data, int initial_pos = 0) {
        nonce = decode32LE(data.data() + initial_pos);
        return initial_pos + 4;
    }

    virtual Data serializeExclusiveData() const {
        auto resp = Data();
        encode32LE(nonce, resp);
        return resp;
    }

    bool operator==(const MinerTransaction &other) const {
        return this->nonce == other.nonce && Transaction::operator==(other);
    }
};

} // namespace TW::CAK
