// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"
#include "../PrivateKey.h"
#include "../proto/Tron.pb.h"

namespace TW::Tron {

/// Helper class that performs Tron transaction signing.
class Signer {
  public:
    Signer() = delete;

    /// Signs the given transaction.
    static Proto::SigningOutput sign(const Proto::SigningInput& input) noexcept;
};

} // namespace TW::Tron
