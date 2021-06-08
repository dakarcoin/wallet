// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "AESParameters.h"

#include "../HexCoding.h"

#include <TrezorCrypto/rand.h>

using namespace TW;
using namespace TW::Keystore;

AESParameters::AESParameters() {
    iv = Data(blockSize, 0);
    random_buffer(iv.data(), blockSize);
}

namespace CodingKeys {
static const auto iv = "iv";
} // namespace CodingKeys

/// Initializes `AESParameters` with a JSON object.
AESParameters::AESParameters(const nlohmann::json& json) {
    iv = parse_hex(json[CodingKeys::iv].get<std::string>());
}

/// Saves `this` as a JSON object.
nlohmann::json AESParameters::json() const {
    nlohmann::json j;
    j[CodingKeys::iv] = hex(iv);
    return j;
}
