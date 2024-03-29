// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.Dakarwallet.core.app.blockchains.binancesmartchain

import com.Dakarwallet.core.app.utils.toHex
import com.Dakarwallet.core.app.utils.toHexByteArray
import org.junit.Assert.assertEquals
import org.junit.Test
import wallet.core.jni.*

class TestBinanceSmartChainAddress {

    init {
        System.loadLibrary("DakarWalletCore")
    }

    @Test
    fun testAddress() {
        val key = PrivateKey("727f677b390c151caf9c206fd77f77918f56904b5504243db9b21e51182c4c06".toHexByteArray())
        val pubkey = key.getPublicKeySecp256k1(false)
        val address = AnyAddress(pubkey, CoinType.SMARTCHAIN)
        val expected = AnyAddress("0xf3d468DBb386aaD46E92FF222adDdf872C8CC064", CoinType.SMARTCHAIN)

        assertEquals(address.description(), expected.description())
    }
}
