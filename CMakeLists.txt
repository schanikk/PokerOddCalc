cmake_minimum_required(VERSION 3.22) # 3.27
project(PokerOddCalc C)

set(CMAKE_C_STANDARD 11)

include_directories(src/deck)
include_directories(src/game)
include_directories(src/controller)
include_directories(src/ui)

add_executable(PokerOddCalc
        src/game/deck.c
        src/game/deck.h
        src/game/game.c
        src/game/game.h
        src/ui/ui.c
        src/ui/ui.h
        main.c)
