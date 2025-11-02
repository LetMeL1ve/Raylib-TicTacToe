cmake_minimum_required(VERSION 3.10.0)
project(TicTacToe VERSION 0.1.0 LANGUAGES C CXX)

find_package(raylib REQUIRED)
add_executable(TicTacToe src/main.cpp
                         src/field.cpp
                         src/game_logic.cpp)
target_link_libraries(TicTacToe raylib)

