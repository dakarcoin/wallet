// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <jni.h>
#include "TWJNI.h"

TW_EXTERN_C_BEGIN

/// Converts a TWString (will be deleted within this call) to a Java string.
jstring TWStringJString(TWString *string, JNIEnv *env);

/// Converts a Java string to a TWString, caller must delete it after use.
TWString * TWStringCreateWithJString(JNIEnv *env, jstring string);

TW_EXTERN_C_END
