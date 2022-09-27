project(cpp_otp_test)
find_package(GTest REQUIRED)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} testFiles)

add_executable(${PROJECT_NAME} ${testFiles})
target_link_libraries(${PROJECT_NAME} GTest::gtest GTest::gtest_main GTest::gmock_main GTest::gmock core)

gtest_add_tests(TARGET
    ${PROJECT_NAME}
)
