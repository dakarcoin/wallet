// Copyright © 2017-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <DakarWalletCore/TWCoinType.h>

namespace TW::Bitcoin {

/// Interface for transaction fee calculator.
class FeeCalculator {
public:
    virtual int64_t calculate(int64_t inputs, int64_t outputs = 2, int64_t byteFee = 1) const = 0;
    virtual int64_t calculateSingleInput(int64_t byteFee) const = 0;
};

/// Default Bitcoin transaction fee calculator, non-segwit.
class DefaultFeeCalculator : public FeeCalculator {
public:
    int64_t calculate(int64_t inputs, int64_t outputs = 2, int64_t byteFee = 1) const override;
    int64_t calculateSingleInput(int64_t byteFee) const override;
};

/// Bitcoin Segwit transaction fee calculator
class SegwitFeeCalculator : public FeeCalculator {
public:
    int64_t calculate(int64_t inputs, int64_t outputs = 2, int64_t byteFee = 1) const override;
    int64_t calculateSingleInput(int64_t byteFee) const override;
};

/// Return the fee calculator for the given coin.
FeeCalculator& getFeeCalculator(TWCoinType coinType);

} // namespace TW::Bitcoin
