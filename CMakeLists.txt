cmake_minimum_required(VERSION 3.22)
project(PokerOddCalc C)

set(CMAKE_C_STANDARD 11)

include_directories(src/game)
include_directories(src/request)
include_directories(src/ui)

add_executable(PokerOddCalc
        src/game/deck.c
        src/game/deck.h
        src/game/game.c
        src/game/game.h
        src/request/request.c
        src/request/request.h
        src/ui/ui.c
        src/ui/ui.h
        main.c
        src/simulation/monte_carlo.c
        src/simulation/monte_carlo.h)
