# walletconsole executable
file(GLOB walletconsole_sources *.cpp)
add_executable(walletconsole ${walletconsole_sources})
#target_link_libraries(tests gtest_main TrezorCrypto DakarWalletCore protobuf Boost::boost)
target_link_libraries(walletconsole walletconsolelib TrezorCrypto DakarWalletCore protobuf Boost::boost)
target_include_directories(walletconsole PRIVATE ${CMAKE_SOURCE_DIR}/walletconsole/lib ${CMAKE_SOURCE_DIR}/src)
target_compile_options(walletconsole PRIVATE "-Wall")

set_target_properties(walletconsole
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

INSTALL(TARGETS walletconsole DESTINATION ${CMAKE_INSTALL_BINDIR})