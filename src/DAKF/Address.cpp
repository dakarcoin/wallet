// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Address.h"

#include "../Base58.h"
#include "../Hash.h"
#include "../Coin.h"

#include <stdexcept>

using namespace TW;
using namespace TW::DAKF;

static const auto keyhashSize = Hash::ripemdSize;
static const auto addressDataSize = keyhashSize + 2;

bool Address::isValid(const std::string& string) noexcept {
    const auto data = Base58::bitcoin.decodeCheck(string, Hash::blake256d);
    if (data.size() != addressDataSize) {
        return false;
    }
    if (data[0] != TW::staticPrefix(TWCoinTypeDAKF)) {
        return false;
    }

    return (data[1] == TW::p2pkhPrefix(TWCoinTypeDAKF) || 
            data[1] == TW::p2shPrefix(TWCoinTypeDAKF));
}

Address::Address(const std::string& string) {
    const auto data = Base58::bitcoin.decodeCheck(string, Hash::blake256d);
    if (data.size() != addressDataSize) {
        throw std::invalid_argument("Invalid address string");
    }

    std::copy(data.begin(), data.end(), bytes.begin());
}

Address::Address(const PublicKey& publicKey) {
    if (publicKey.type != TWPublicKeyTypeSECP256k1) {
        throw std::invalid_argument("Invalid publid key type");
    }
    const auto hash = Hash::ripemd(Hash::blake256(publicKey.bytes));
    std::copy(hash.begin(), hash.end(), bytes.begin() + 2);
    bytes[0] = TW::staticPrefix(TWCoinTypeDAKF);
    bytes[1] = TW::p2pkhPrefix(TWCoinTypeDAKF);
}

std::string Address::string() const {
    return Base58::bitcoin.encodeCheck(bytes, Hash::blake256d);
}
