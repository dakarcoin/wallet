// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "PBKDF2Parameters.h"

#include <TrezorCrypto/rand.h>
#include <limits>

using namespace TW;
using namespace TW::Keystore;

PBKDF2Parameters::PBKDF2Parameters() : salt(32) {
    random_buffer(salt.data(), salt.size());
}

// -----------------
// Encoding/Decoding
// -----------------

namespace CodingKeys {
static const auto salt = "salt";
static const auto desiredKeyLength = "dklen";
static const auto iterations = "c";
} // namespace CodingKeys

PBKDF2Parameters::PBKDF2Parameters(const nlohmann::json& json) {
    salt = parse_hex(json[CodingKeys::salt].get<std::string>());
    desiredKeyLength = json[CodingKeys::desiredKeyLength];
    if (json.count(CodingKeys::iterations) != 0)
        iterations = json[CodingKeys::iterations];
}

/// Saves `this` as a JSON object.
nlohmann::json PBKDF2Parameters::json() const {
    nlohmann::json j;
    j[CodingKeys::salt] = hex(salt);
    j[CodingKeys::desiredKeyLength] = desiredKeyLength;
    j[CodingKeys::iterations] = iterations;
    return j;
}
