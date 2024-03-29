package types

// #cgo CFLAGS: -I../../../include
// #cgo LDFLAGS: -L../../../build -L../../../build/trezor-crypto -lDakarWalletCore -lprotobuf -lTrezorCrypto -lc++ -lm
// #include <DakarWalletCore/TWString.h>
import "C"

import (
	"unsafe"
)

// C.TWString -> Go string
func TWStringGoString(s unsafe.Pointer) string {
	return C.GoString(C.TWStringUTF8Bytes(s))
}

// Go string -> C.TWString
func TWStringCreateWithGoString(s string) unsafe.Pointer {
	cStr := C.CString(s)
	defer C.free(unsafe.Pointer(cStr))
	str := C.TWStringCreateWithUTF8Bytes(cStr)
	return str
}
