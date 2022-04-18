cmake_minimum_required(VERSION 3.21)
project(parkingsimulator C)

set(CMAKE_C_STANDARD 11)

add_executable(parkingsimulator
        main.c servidor.c veiculo.c)
