import com.Dakarwallet.core.app.utils.Numeric
import com.Dakarwallet.core.app.utils.toHexBytes
import com.Dakarwallet.core.app.utils.toHex
import org.junit.Assert.assertEquals
import org.junit.Test

class TestData {
    init {
        System.loadLibrary("DakarWalletCore");
    }

    @Test
    fun testUsingNumeric() {
        val data = Numeric.hexStringToByteArray("01020304")
        assertEquals(Numeric.toHexString(data), "0x01020304")
    }

    fun testUsingExtensions() {
        {
            val data = "01020304".toHexBytes()
            assertEquals(data.toHex(), "0x01020304")
        }
        {   // with prefix
            val data = "0x01020304".toHexBytes()
            assertEquals(data.toHex(), "0x01020304")
        }
    }

    fun testOddLength() {
        {
            val data = "0x0".toHexBytes()
            assertEquals(data.toHex(), "0x00")
        }
        {
            val data = "0x28fa6ae00".toHexBytes()
            assertEquals(data.toHex(), "0x28fa6ae00")
        }
    }
}
