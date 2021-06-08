// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "OutPoint.h"
#include "../Bitcoin/Script.h"
#include "../Data.h"

#include <limits>
#include <vector>

namespace TW::DAKF {

/// DAKF transaction input.
class TransactionInput {
  public:
    /// Reference to the previous transaction's output.
    OutPoint previousOutput;

    /// Transaction version as defined by the sender.
    ///
    /// Intended for "replacement" of transactions when information is updated
    /// before inclusion into a block.
    uint32_t sequence = std::numeric_limits<uint32_t>::max();

    int64_t valueIn;
    uint32_t blockHeight;
    uint32_t blockIndex = std::numeric_limits<uint32_t>::max();

    /// Computational Script for confirming transaction authorization.
    Bitcoin::Script script;

    /// Encodes the transaction into the provided buffer.
    void encode(Data& data) const;

    /// Encodes the transaction witness information into the provided buffer.
    void encodeWitness(Data& data) const;
};

} // namespace TW::DAKF
