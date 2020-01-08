//
// Created by magshimim on 8.1.2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#include <istream>
#include <fstream>
#include <iostream>
#include "Solver.h"
#include "CacheManager.h"

/*
 * This interface determines the type of conversation between the server and the client.
 * ofstream: Stream class to write on files.
 * ifstream: Stream class to read from files
 * */
class ClientHandler{
public:
    //get stream from client and write answer by server to client
    virtual void handleClient(std::ifstream, std::ofstream) = 0;
    virtual ~ClientHandler();
};
/*
 * Class to test the code
 * */
class MyTestClientHandler : ClientHandler {
    Solver<class Problem, class Solution>* solver;
    CacheManager<class Problem, class Solution>* cacheManager;
    virtual void handleClient(std::ifstream, std::ofstream){};
    virtual ~MyTestClientHandler(){};
};
#endif //EX4_CLIENTHANDLER_H
