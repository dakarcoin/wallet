// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Account.h"

#include <regex>

using namespace TW;
using namespace TW::NEAR;

static auto pattern = std::regex(R"(^(([a-z\d]+[\-_])*[a-z\d]+\.)*([a-z\d]+[\-_])*[a-z\d]+$)");
bool Account::isValid(const std::string& string) {
    // https://docs.near.org/docs/concepts/account#account-id-rules
    if (string.size() < 2 || string.size() > 64) {
        return false;
    }
    std::smatch match;
    return regex_search(string, match, pattern);
}
