cmake_minimum_required( VERSION 3.19.1 )

project(MACIERZ)

include_directories( ./src ./include)

add_executable(test ./src/main.cpp ./src/matrix.cpp )