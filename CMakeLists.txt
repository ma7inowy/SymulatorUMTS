cmake_minimum_required(VERSION 3.17)
project(SymulatorUmts)

set(CMAKE_CXX_STANDARD 14)

add_executable(SymulatorUmts main.cpp src/RadioNetworkController.cpp include/RadioNetworkController.h)