// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Action.h"
#include "../HexCoding.h"
#include "../DAK/Serialization.h"

using namespace TW;
using namespace TW::DAK;
using json = nlohmann::json;

void PermissionLevel::serialize(Data& o) const {
    actor.serialize(o);
    permission.serialize(o);
}

json PermissionLevel::serialize() const noexcept {
    json obj;
    obj["actor"] = actor.string();
    obj["permission"] = permission.string();
    return obj;
}

void Action::serialize(Data& o) const {
    account.serialize(o);
    name.serialize(o);
    encodeCollection(authorization, o);
    encodeVarInt64(data.size(), o);
    append(o, data);
}

json Action::serialize() const noexcept {
    json obj;
    obj["account"] = account.string();
    obj["name"] = name.string();
    obj["authorizations"] = encodeCollection(authorization);
    obj["data"] = hex(data);
    return obj;
}

TransferAction::TransferAction( const std::string& currency,
                                const std::string& from, 
                                const std::string& to, 
                                const Asset& asset, 
                                const std::string& memo) {
    account = Name(currency);
    name = Name("transfer");
    authorization.push_back(PermissionLevel(Name(from), Name("active")));

    setData(from, to, asset, memo);
}

void TransferAction::setData(const std::string& from, const std::string& to, const Asset& asset, const std::string& memo) {
    if (asset.amount <= 0) {
        throw std::invalid_argument("Amount in a transfer action must be greater than zero.");
    }

    Name(from).serialize(data);
    Name(to).serialize(data);
    asset.serialize(data);
    encodeString(memo, data);
}
