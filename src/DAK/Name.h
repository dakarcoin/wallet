// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"

namespace TW::DAK {

class Name {
public:
    uint64_t value = 0;

    Name() { }
    Name(const std::string& str);
    uint64_t toSymbol(char c) const noexcept;
    std::string string() const noexcept;

    void serialize(TW::Data& o) const noexcept;
};

} // namespace TW::DAK
