cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_executable(ex4 main.cpp Server/Side_server.h Server/MySerialServer.cpp Server/MySerialServer.h clientHandler/ClientHandler.h Solver/Solver.h CacheManager/CacheManager.h Algo/BestFirstSearch.h State.h SerachAlgo/SearchableMatrix.h SerachAlgo/Isearcher.h SerachAlgo/Isearchable.h Algo/BFS.h clientHandler/MyTestClientHandler.cpp clientHandler/MyTestClientHandler.h Solver/StringReverse.cpp Solver/StringReverse.h Solver/OAdapter.cpp Solver/OAdapter.h clientHandler/MatrixClientHandler.cpp clientHandler/MatrixClientHandler.h SerachAlgo/SearchableMatrix.cpp SerachAlgo/SearcherAbstract.h CacheManager/FileCacheManager.cpp CacheManager/FileCacheManager.h MyStruct/MyQueqe.h Algo/DFS.h Server/MyParallelServer.cpp Server/MyParallelServer.h)