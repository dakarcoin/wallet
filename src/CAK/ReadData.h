// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <cctype>

#include "../Data.h"
#include "../BinaryCoding.h"

namespace TW {

Data readBytes(const Data& from, int max, int initial_pos = 0);
Data readVarBytes(const Data& from, int initial_pos = 0, uint32_t* dataRead = nullptr);

template<class T> T readVar(const TW::Data& from, int initial_pos = 0, const T& max = INT_MAX);
template<> int64_t readVar(const TW::Data& from, int initial_pos, const int64_t& max);
template<> uint64_t readVar(const TW::Data& from, int initial_pos, const uint64_t& max);

Data writeVarBytes(const Data& from, int initial_pos = 0);

template<class T>
static std::vector<T> concat(const std::vector<T>& v1, const std::vector<T>& v2) {
    std::vector<T> v(v1);
    v.insert(v.end(), v2.begin(), v2.end());
    return std::move(v);
}

} // namespace TW
