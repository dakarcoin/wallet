// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"
#include "ISerializable.h"
#include "Serializable.h"

namespace TW::CAK {

class Witness : public Serializable {
  public:
    Data invocationScript;
    Data verificationScript;

    virtual ~Witness() {}

    int64_t size() const override {
        return invocationScript.size() + verificationScript.size();
    }

    void deserialize(const Data& data, int initial_pos = 0) override {
        uint32_t size;
        invocationScript = readVarBytes(data, initial_pos, &size);
        verificationScript = readVarBytes(data, initial_pos + size);
    }

    Data serialize() const override {
        return concat(writeVarBytes(invocationScript), writeVarBytes(verificationScript));
    }

    bool operator==(const Witness &other) const {
        return this->invocationScript.size() == other.invocationScript.size()
            && this->verificationScript.size() == other.verificationScript.size()
            && this->invocationScript == other.invocationScript
            && this->verificationScript == other.verificationScript;
    }
};

}