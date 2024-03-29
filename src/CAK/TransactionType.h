// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

namespace TW::CAK {

enum TransactionType // int, not byte
{
    TT_MinerTransaction = 0x00,
    TT_IssueTransaction = 0x01,
    TT_ClaimTransaction = 0x02,
    TT_EnrollmentTransaction = 0x20,
    TT_RegisterTransaction = 0x40,
    TT_ContractTransaction = 0x80,
    TT_StateTransaction = 0x90,
    TT_PublishTransaction = 0xd0,
    TT_InvocationTransaction = 0xd1
};

}
