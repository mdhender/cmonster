cmake_minimum_required(VERSION 3.22)
project(monster C)

set(CMAKE_C_STANDARD 99)

add_executable(monster main.c monster.h portage.c portage.h prng.c prng.h)
