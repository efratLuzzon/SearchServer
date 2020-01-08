cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_executable(ex4 main.cpp Side_server.h ServerImplements.cpp ServerImplements.h ClientHandler.h Solver.h CacheManager.cpp CacheManager.h)