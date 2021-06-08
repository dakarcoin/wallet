// Copyright © 2020-2021 Dakar Wallet.
//
// This file is part of Dakar. The full Dakar copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.Dakarwallet.core.app.blockchains.kusama

import com.Dakarwallet.core.app.utils.toHex
import com.Dakarwallet.core.app.utils.toHexByteArray
import org.junit.Assert.assertEquals
import org.junit.Test
import wallet.core.jni.*

class TestKusamaAddress {

    init {
        System.loadLibrary("DakarWalletCore")
    }

    @Test
    fun testAddress() {

        val key = PrivateKey("0x85fca134b3fe3fd523d8b528608d803890e26c93c86dc3d97b8d59c7b3540c97".toHexByteArray())
        val pubkey = key.publicKeyEd25519
        val address = AnyAddress(pubkey, CoinType.KUSAMA)
        val expected = AnyAddress("HewiDTQv92L2bVtkziZC8ASxrFUxr6ajQ62RXAnwQ8FDVmg", CoinType.KUSAMA)

        assertEquals(pubkey.data().toHex(), "0xe0b3fcccfe0283cc0f8c105c68b5690aab8c5c1692a868e55eaca836c8779085")
        assertEquals(address.description(), expected.description())
    }
}
