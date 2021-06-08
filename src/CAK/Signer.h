// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Address.h"
#include "Transaction.h"
#include "../Data.h"
#include "../PrivateKey.h"
#include "../proto/CAK.pb.h"

namespace TW::CAK {

class Signer {
  private:
    Data publicKey;
    TW::PrivateKey privateKey;
    Address address;

  public:
    explicit Signer(const TW::PrivateKey& priKey);
    PrivateKey getPrivateKey() const;
    PublicKey getPublicKey() const;
    Address getAddress() const;

    static Proto::TransactionPlan plan(const Proto::SigningInput& input);
    static Proto::SigningOutput sign(const Proto::SigningInput& input) noexcept;
    void sign(Transaction& tx) const;
    Data sign(const Data& data) const;

  private:
    static Transaction prepareUnsignedTransaction(const Proto::SigningInput& input,
                                                  const Proto::TransactionPlan& plan,
                                                  bool validate = true);
};

} // namespace TW::CAK
