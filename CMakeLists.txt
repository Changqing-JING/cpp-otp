cmake_minimum_required(VERSION 3.20)
project(cpp_otp)
enable_testing()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 14)

if(ENABLE_COVERAGE)
    if(UNIX AND(NOT CMAKE_CXX_COMPILER_ID STREQUAL "QCC"))
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
    endif()

    if(CMAKE_GENERATOR STREQUAL "Unix Makefiles")
        if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
            set(CovExecutable "llvm-cov gcov")
        elseif((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang"))
            set(CovExecutable "gcov")
        endif()

        add_custom_target(run_ctest
            COMMAND ctest "--verbose"
            ARG
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
        )

        if(DEFINED CovExecutable)
            set(gcovr_options_basic --exclude-throw-branches --exclude-unreachable-branches --gcov-executable ${CovExecutable} -r ${CMAKE_CURRENT_SOURCE_DIR}/main .)
            set(gcovr_options_xml ${gcovr_options_basic} -d -s -x coverage.xml)
            add_custom_target(coverage_basic VERBATIM
                COMMAND gcovr ${gcovr_options_basic}
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                DEPENDS run_ctest
            )
            add_custom_target(
                coverage VERBATIM
                COMMAND gcovr ${gcovr_options_xml}
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                DEPENDS coverage_basic
            )
        endif()
    endif()
endif()

add_subdirectory(main)
add_subdirectory(test)
