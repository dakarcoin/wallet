// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <string>

namespace TW::NEAR {

class Account {
  public:
    /// Determines whether a string makes a valid NEAR account id.
    static bool isValid(const std::string& string);
};
} // namespace TW::NEAR
