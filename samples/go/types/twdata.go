package types

// #cgo CFLAGS: -I../../../include
// #cgo LDFLAGS: -L../../../build -L../../../build/trezor-crypto -lDakarWalletCore -lprotobuf -lTrezorCrypto -lc++ -lm
// #include <DakarWalletCore/TWData.h>
import "C"

import (
	"unsafe"
	"encoding/hex"
)

// C.TWData -> Go byte[]
func TWDataGoBytes(d unsafe.Pointer) []byte {
	cBytes := C.TWDataBytes(d)
	cSize := C.TWDataSize(d)
	return C.GoBytes(unsafe.Pointer(cBytes), C.int(cSize))
}

// Go byte[] -> C.TWData
func TWDataCreateWithGoBytes(d []byte) unsafe.Pointer {
	cBytes := C.CBytes(d)
	defer C.free(unsafe.Pointer(cBytes))
	data := C.TWDataCreateWithBytes((*C.uchar)(cBytes), C.ulong(len(d)))
	return data
}

// C.TWData -> Go hex string
func TWDataHexString(d unsafe.Pointer) string {
	return hex.EncodeToString(TWDataGoBytes(d))
}
