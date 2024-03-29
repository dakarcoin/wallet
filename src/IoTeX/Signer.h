// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Data.h"

#include "proto/IoTeX.pb.h"

namespace TW::IoTeX {

/// Helper class that performs IoTeX transaction signing
class Signer {
  public:
    /// Signs a Proto::SigningInput transaction
    static Proto::SigningOutput sign(const Proto::SigningInput& input) noexcept;
  public:
    Proto::SigningInput input;
    Proto::ActionCore action;

    /// Initializes a transaction signer
    Signer(const Proto::SigningInput& input) : input(input) { toActionCore(); }

    /// Signs the transaction
    ///
    /// \returns the transaction signature or an empty vector if there is an error
    Data sign() const;

    /// Builds the signed transaction
    ///
    /// \returns the signed transaction
    Proto::SigningOutput build() const;

    /// Computes the transaction hash
    Data hash() const;

  protected:
    /// Converts to proto ActionCore from transaction input
    void toActionCore();
};

} // namespace TW::IoTeX
