// Copyright © 2017-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Mnemonic.h"

#include <TrezorCrypto/bip39_english.h>
#include <TrezorCrypto/bip39.h>

#include <string.h>
#include <string>
#include <vector>
#include <cassert>

namespace TW {

const int Mnemonic::SuggestMaxCount = 10;

bool Mnemonic::isValid(const std::string& mnemonic) {
    return mnemonic_check(mnemonic.c_str()) != 0;
}

inline const char* const* mnemonicWordlist() { return wordlist; }

bool Mnemonic::isValidWord(const std::string& word) {
    const char* wordC = word.c_str();
    for (const char* const* w = mnemonicWordlist(); *w != nullptr; ++w) {
        if (strncmp(*w, wordC, word.length()) == 0) {
            return true;
        }
    }
    // not found
    return false;
}

std::string Mnemonic::suggest(const std::string& prefix) {
    if (prefix.size() == 0) {
        return "";
    }
    assert(prefix.size() >= 1);
    // lowercase prefix
    std::string prefixLo = prefix;
    std::transform(prefixLo.begin(), prefixLo.end(), prefixLo.begin(),
        [](unsigned char c){ return std::tolower(c); });
    const char* prefixLoC = prefixLo.c_str();

    std::vector<std::string> result;
    for (const char* const* word = mnemonicWordlist(); *word != nullptr; ++word) {
        // check first letter match (optimization)
        if ((*word)[0] == prefixLo[0]) {
            if (strncmp(*word, prefixLoC, prefixLo.length()) == 0) {
                // we have a match
                result.push_back(*word);
                if (result.size() >= SuggestMaxCount) {
                    break; // enough results
                }
            }
        }
    }

    // convert results to one string
    std::string resultString;
    for (auto& word: result) {
        if (resultString.length() > 0) {
            resultString += " ";
        }
        resultString += word;
    }
    return resultString;
}

}
