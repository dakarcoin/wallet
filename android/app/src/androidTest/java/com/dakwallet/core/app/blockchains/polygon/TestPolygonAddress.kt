// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.Dakarwallet.core.app.blockchains.polygon

import com.Dakarwallet.core.app.utils.toHex
import com.Dakarwallet.core.app.utils.toHexByteArray
import org.junit.Assert.assertEquals
import org.junit.Test
import wallet.core.jni.*

class TestPolygonAddress {

    init {
        System.loadLibrary("DakarWalletCore")
    }

    @Test
    fun testAddress() {
        val key = PrivateKey("828c4c48c2cef521f0251920891ed79e871faa24f64f43cde83d07bc99f8dbf0".toHexByteArray())
        val pubkey = key.getPublicKeySecp256k1(false)
        val address = AnyAddress(pubkey, CoinType.POLYGON)
        val expected = AnyAddress("0xe32DC46bfBF78D1eada7b0a68C96903e01418D64", CoinType.POLYGON)

        assertEquals(address.description(), expected.description())
    }
}