cmake_minimum_required(VERSION 3.2)


project(game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
  game
  main.cpp
  misc.cpp misc.h
  gamelogic.cpp gamelogic.h
  high_scores.hpp)

