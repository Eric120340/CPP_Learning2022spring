cmake_minimum_required(VERSION 3.21)
project(cardgame)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cardgame
        big_boss_card.cpp
        big_boss_card.h
        card.cpp
        card.h
        exchange_card.cpp
        exchange_card.h
        main.cpp
        player.cpp
        player.h)
