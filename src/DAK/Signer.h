// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Prefixes.h"
#include "Transaction.h"
#include "../Data.h"
#include "../Hash.h"
#include "../PrivateKey.h"
#include "../proto/DAK.pb.h"

#include <stdexcept>

namespace TW::DAK {

/// Helper class that performs DAK transaction signing.
class Signer {
  public:
    /// Signs a Proto::SigningInput transaction
    static Proto::SigningOutput sign(const Proto::SigningInput& input) noexcept;

  public:
    const Data chainID;

    /// Initializes a signer with a chain identifier.
    Signer(const Data& chainID) : chainID(chainID) {}

    /// Signs the given transaction.
    void sign(const PrivateKey& privateKey, Type type, Transaction& transaction) const;

    /// Computes the transaction hash.
    Data hash(const Transaction& transaction) const noexcept;

    static int isCanonical(uint8_t by, uint8_t sig[64]);
};

} // namespace TW::DAK
