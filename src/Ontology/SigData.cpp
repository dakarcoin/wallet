// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <stdexcept>

#include "ParamsBuilder.h"
#include "SigData.h"

using namespace TW;
using namespace TW::Ontology;

Data SigData::serialize() {
    auto sigInfo = ParamsBuilder::fromSigs(sigs);
    if (pubKeys.empty()) {
        throw std::runtime_error("Public key is empty.");
    }
    std::vector<uint8_t> verifyInfo;
    if (pubKeys.size() == 1) {
        verifyInfo = ParamsBuilder::fromPubkey(pubKeys[0]);
    } else {
        verifyInfo = ParamsBuilder::fromMultiPubkey(m, pubKeys);
    }
    ParamsBuilder builder;
    builder.pushVar(sigInfo);
    builder.pushVar(verifyInfo);
    return builder.getBytes();
}
