cmake_minimum_required(VERSION 3.8)
project(NJ-NS-Project4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")

add_executable(NJ-NS-Project4 fifaPlayer.h fifaPlayer.cpp playerTemplate.h)