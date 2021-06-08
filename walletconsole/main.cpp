// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "WalletConsole.h"
#include <iostream>

int main() {
    TW::WalletConsole::WalletConsole console(std::cin, std::cout);
    console.loop();
}