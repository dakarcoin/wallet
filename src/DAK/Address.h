// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"
#include "../PublicKey.h"
#include "Prefixes.h"

#include <string>

namespace TW::DAK {

class Address {
public:

    /// Determines whether a string makes a valid DAK address.
    static bool isValid(const std::string& string);

    /// Determines whether the given byte array is a valid keyBuffer
    static bool isValid(const  Data& bytes, Type type = Type::Legacy);

    /// Initializes a DAK address from a string representation.
    Address(const std::string& string);

    /// Initializes a DAK address from a public key.
    Address(const PublicKey& publicKey, Type type = Type::Legacy);

    /// Initializes a DAK address from a byte array.
    Address(const Data& data, Type type = Type::Legacy);

    /// Returns a string representation of the DAK address.
    std::string string() const;

    friend bool operator==(const Address& lhs, const Address& rhs);

    inline std::string prefix() const { return pubPrefixForType(type); }

protected:
    // Class constants
    static const size_t PublicKeyDataSize = 33;
    static const size_t ChecksumSize = 4;
    static const size_t KeyDataSize = PublicKeyDataSize + ChecksumSize;

    Data keyData;
    Type type;

    static uint32_t createChecksum(const Data& bytes, Type type);
    static bool extractKeyData(const std::string& string, Address *address = nullptr);
};


inline bool operator==(const Address& lhs, const Address& rhs) {
    return lhs.keyData == rhs.keyData
             && lhs.type == rhs.type;
}

} // namespace TW::DAK
