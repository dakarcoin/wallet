// Copyright © 2017-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.Dakarwallet.core.app.blockchains.thorchain

import com.Dakarwallet.core.app.utils.toHex
import com.Dakarwallet.core.app.utils.toHexByteArray
import org.junit.Assert.assertEquals
import org.junit.Test
import wallet.core.jni.*
import wallet.core.jni.CoinType.THORCHAIN

class TestTHORChainAddress {

    init {
        System.loadLibrary("DakarWalletCore")
    }

    @Test
    fun testAddressValidation() {
        var addr = listOf(
            "thor1z53wwe7md6cewz9sqwqzn0aavpaun0gw0exn2r",
            "thor1c8jd7ad9pcw4k3wkuqlkz4auv95mldr2kyhc65"
        )
        addr.forEach {
            assert(CoinType.THORCHAIN.validate(it))
            assertEquals(it, AnyAddress(it, CoinType.THORCHAIN).description())
        }
    }
}
