cmake_minimum_required(VERSION 3.7)
project(SimulationsAndTechniques)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TransmitMessage.h TransmitMessage.cpp)
add_executable(SimulationsAndTechniques ${SOURCE_FILES})