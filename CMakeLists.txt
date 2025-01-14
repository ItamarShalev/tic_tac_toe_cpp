cmake_minimum_required(VERSION 3.10)
project(TicTacToeCPP)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

file(GLOB HEADERS "include/*.h")

add_executable(tic_tac_toe_game
        main.cpp
        ${SOURCES}
        ${HEADERS}
)
