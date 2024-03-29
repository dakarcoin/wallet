// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "PackedTransaction.h"

#include "../HexCoding.h"

using namespace TW;
using namespace TW::DAK;
using json = nlohmann::json;

PackedTransaction::PackedTransaction(const Transaction& transaction, CompressionType type) noexcept : compression(type) {
    transaction.serialize(packedTrx);
    const Data& cfd = transaction.contextFreeData;

    if (cfd.size()) {
        packedCFD.push_back(1);
        encodeVarInt64(cfd.size(), packedCFD);
        append(packedCFD, cfd);
    }

    signatures = transaction.signatures;
}

void PackedTransaction::serialize(Data& os) const noexcept {
    encodeCollection(signatures, os);
    os.push_back(static_cast<uint8_t>(compression));
    encodeVarInt64(packedCFD.size(), os);
    append(os, packedCFD);
    encodeVarInt64(packedTrx.size(), os);
    append(os, packedTrx);
}

json PackedTransaction::serialize() const noexcept {
    // create a json array of signatures
    json sigs = json::array();
    for (const auto& sig : signatures) {
        sigs.push_back(sig.string());
    }

    json obj;

    obj["signatures"] = sigs;
    obj["compression"] = compression;
    obj["packed_context_free_data"] = hex(packedCFD);
    obj["packed_trx"] = hex(packedTrx);

    return obj;
}