set(tests_files
        mainTests.cc
)

add_executable(ant_tests
        ${tests_files}
)

target_link_libraries(
        ant_tests
        ant_simulator_lib
        GTest::gtest_main
        gtest
        gmock
)

include(GoogleTest)
gtest_discover_tests(ant_tests)

