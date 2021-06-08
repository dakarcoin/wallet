// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Base58Address.h"
#include "../Data.h"
#include "../PublicKey.h"

#include <string>

namespace TW::Bitcoin {

class Address : public TW::Base58Address<21> {
  public:
    /// Initializes a  address with a string representation.
    explicit Address(const std::string& string) : TW::Base58Address<21>(string) {}

    /// Initializes a  address with a collection of bytes.
    explicit Address(const Data& data) : TW::Base58Address<21>(data) {}

    /// Initializes a  address with a public key and a prefix.
    Address(const PublicKey& publicKey, byte prefix) : TW::Base58Address<21>(publicKey, {prefix}) {}
};

} // namespace TW::Bitcoin

/// Wrapper for C interface.
struct TWBitcoinAddress {
    TW::Bitcoin::Address impl;
};
