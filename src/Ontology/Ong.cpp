// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Ong.h"
#include "Data.h"
#include "ParamsBuilder.h"

#include <list>

using namespace TW;
using namespace TW::Ontology;

Transaction Ong::decimals(uint32_t nonce) {
    auto builder = ParamsBuilder();
    auto invokeCode =
        ParamsBuilder::buildNativeInvokeCode(contractAddress(), version, "decimals", Data());
    auto tx =
        Transaction(version, txType, nonce, (uint64_t)0, (uint64_t)0, (std::string) "", invokeCode);
    return tx;
}

Transaction Ong::balanceOf(const Address &address, uint32_t nonce) {
    auto builder = ParamsBuilder();
    auto invokeCode =
        ParamsBuilder::buildNativeInvokeCode(contractAddress(), version, "balanceOf", address.data);
    auto tx =
        Transaction(version, txType, nonce, (uint64_t)0, (uint64_t)0, (std::string) "", invokeCode);
    return tx;
}

Transaction Ong::transfer(const Signer &from, const Address &to, uint64_t amount,
                          const Signer &payer, uint64_t gasPrice, uint64_t gasLimit,
                          uint32_t nonce) {
    std::list<boost::any> transferParam{from.getAddress().data, to.data, amount};
    std::vector<boost::any> args{transferParam};
    auto invokeCode =
        ParamsBuilder::buildNativeInvokeCode(contractAddress(), 0x00, "transfer", args);
    auto tx = Transaction(version, txType, nonce, gasPrice, gasLimit, payer.getAddress().string(),
                          invokeCode);
    from.sign(tx);
    payer.addSign(tx);
    return tx;
}

Transaction Ong::withdraw(const Signer &claimer, const Address &receiver, uint64_t amount,
                          const Signer &payer, uint64_t gasPrice, uint64_t gasLimit,
                          uint32_t nonce) {
    auto ontContract = Address("AFmseVrdL9f9oyCzZefL9tG6UbvhUMqNMV");
    std::list<boost::any> args{claimer.getAddress().data, ontContract.data, receiver.data, amount};
    auto invokeCode =
        ParamsBuilder::buildNativeInvokeCode(contractAddress(), 0x00, "transferFrom", args);
    auto tx = Transaction(version, txType, nonce, gasPrice, gasLimit, payer.getAddress().string(),
                          invokeCode);
    claimer.sign(tx);
    payer.addSign(tx);
    return tx;
}