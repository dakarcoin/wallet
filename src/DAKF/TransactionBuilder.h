// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Transaction.h"
#include "../Bitcoin/TransactionPlan.h"
#include "../Bitcoin/TransactionBuilder.h"
#include "../proto/Bitcoin.pb.h"
#include "../proto/DAKF.pb.h"

#include <DakarWalletCore/TWCoinType.h>

#include <algorithm>

namespace TW::DAKF {

struct TransactionBuilder {
    /// Plans a transaction by selecting UTXOs and calculating fees.
    static Bitcoin::TransactionPlan plan(const Bitcoin::Proto::SigningInput& input) {
        return Bitcoin::TransactionBuilder::plan(input);
    }

    /// Builds a transaction by selecting UTXOs and calculating fees.
    static Transaction build(const Bitcoin::TransactionPlan& plan, const std::string& toAddress,
                             const std::string& changeAddress) {
        auto coin = TWCoinTypeDAKF;                                 
        auto lockingScriptTo = Bitcoin::Script::lockScriptForAddress(toAddress, coin);
        if (lockingScriptTo.empty()) {
            return {};
        }

        Transaction tx;
        tx.outputs.emplace_back(TransactionOutput(plan.amount, /* version: */ 0, lockingScriptTo));

        if (plan.change > 0) {
            auto lockingScriptChange = Bitcoin::Script::lockScriptForAddress(changeAddress, coin);
            tx.outputs.emplace_back(
                TransactionOutput(plan.change, /* version: */ 0, lockingScriptChange));
        }

        const auto emptyScript = Bitcoin::Script();
        for (auto& utxo : plan.utxos) {
            auto input = TransactionInput();
            input.previousOutput = utxo.out_point();
            input.sequence = utxo.out_point().sequence();
            tx.inputs.push_back(std::move(input));
        }

        return tx;
    }
};

} // namespace TW::DAKF
