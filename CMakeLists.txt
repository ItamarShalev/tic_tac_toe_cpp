cmake_minimum_required(VERSION 3.10)
project(TicTacToeCPP)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

file(GLOB HEADERS "include/*.h")

file(GLOB TESTS_SOURCES "tests/*.cpp")

add_executable(tic_tac_toe_game
        main.cpp
        ${SOURCES}
        ${HEADERS}
)


# Google Tests

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.15.2
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(test_tic_tac_toe
        ${TESTS_SOURCES}
        ${SOURCES}
        ${HEADERS}
)

target_link_libraries(test_tic_tac_toe gtest gtest_main)

add_test(NAME TicTacToeTest COMMAND test_tic_tac_toe)