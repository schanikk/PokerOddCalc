cmake_minimum_required(VERSION 3.28)
project(PokerOddCalc C)

set(CMAKE_C_STANDARD 11)

include_directories(src/calculator)
include_directories(src/controller)
include_directories(src/game)
include_directories(src/ui)
include_directories(tests/game)

add_executable(PokerOddCalc
        src/calculator/calculator.c
        src/calculator/calculator.h
        src/controller/controller.c
        src/controller/controller.h
        src/game/deck.c
        src/game/deck.h
        src/game/game.c
        src/game/game.h
        src/ui/ui.c
        src/ui/ui.h
        src/utils/datastructures.c
        tests/game/deck_test.c
        tests/game/deck_test.h
        tests/game/game_test.c
        tests/game/game_test.h
        tests/main_tests.c)
