// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Bitcoin/Amount.h"
#include "../Bitcoin/Script.h"
#include "../Data.h"

namespace TW::DAKF {

/// DAKF transaction output.
struct TransactionOutput {
    /// Transaction amount.
    Bitcoin::Amount value;

    /// Transaction output version.
    uint16_t version;

    /// Ppublic key script setting up conditions to claim this output.
    Bitcoin::Script script;

    /// Initializes an empty transaction output.
    TransactionOutput() = default;

    /// Initializes a transaction output with a value and a script.
    TransactionOutput(Bitcoin::Amount value, uint16_t version, Bitcoin::Script script)
        : value(value), version(version), script(std::move(script)) {}

    /// Encodes the output into the provided buffer.
    void encode(Data& data) const;
};

} // namespace TW::DAKF
