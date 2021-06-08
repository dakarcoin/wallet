package com.Dakarwallet.core.app.blockchains.nuls

import com.Dakarwallet.core.app.utils.Numeric
import org.junit.Assert.assertEquals
import org.junit.Test
import wallet.core.jni.*

class TestNULSAddress {

    init {
        System.loadLibrary("DakarWalletCore")
    }

    @Test
    fun testAddress() {
        val priKey = PrivateKey(Numeric.hexStringToByteArray("a1269039e4ffdf43687852d7247a295f0b5bc55e6dda031cffaa3295ca0a9d7a"))
        val pubkey = priKey.getPublicKeySecp256k1(true)
        val address = AnyAddress(pubkey, CoinType.NULS)
        val expected = AnyAddress("NULSd6HghWa4CN5qdxqMwYVikQxRZyj57Jn4L", CoinType.NULS)

        assertEquals(address.description(), expected.description())
    }
}
