// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <assert.h>
#include <string.h>
#include "TWJNIString.h"

jstring _Nonnull TWStringJString(TWString *_Nonnull string, JNIEnv *env) {
    jstring result = env->NewStringUTF(TWStringUTF8Bytes(string));
    TWStringDelete(string);
    return result;
}

TWString *_Nonnull TWStringCreateWithJString(JNIEnv *env, jstring _Nonnull string) {
    auto chars = env->GetStringUTFChars(string, nullptr);
    auto twstring = TWStringCreateWithUTF8Bytes(chars);
    env->ReleaseStringUTFChars(string, chars);
    return twstring;
}
