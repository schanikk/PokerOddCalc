cmake_minimum_required(VERSION 3.27)
project(PokerOddCalc C)

set(CMAKE_C_STANDARD 11)

include_directories(tests/deck)
include_directories(tests/game)
include_directories(tests/controller)
include_directories(tests/ui)
include_directories(../src/game/)

add_executable(PokerOddCalc
        main_tests.c
        game/deck_test.c
        game/game_test.c
        ../src/game/deck.c
        ../src/game/deck.h
        game/deck_test.h
        game/game_test.h
)
