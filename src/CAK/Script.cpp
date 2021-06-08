// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
#include "Script.h"
#include "OpCode.h"

namespace TW::CAK {

Data Script::CreateSignatureRedeemScript(const Data& publicKey) {
    Data result;
    result.push_back((byte)PUSHBYTES21);
    result.insert(result.end(), publicKey.begin(), publicKey.end());
    result.push_back((byte)CHECKSIG);
    return result;
}

Data Script::CreateInvocationScript(const Data& signature) {
    Data result;
    result.push_back((byte)PUSHBYTES40);
    result.insert(result.end(), signature.begin(), signature.end());
    return result;
}

} // namespace TW::CAK
