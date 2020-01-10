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
class ClientHandler {
public:
//    ClientHandler(){}
    //get stream from client and write answer by server to client
    virtual void handleClient(int read, int write) = 0;
    virtual ~ClientHandler(){}
};
/*
 * Class to test the code
 * */
template <class Problem, class Solution>
class MyTestClientHandler : public ClientHandler {
    Solver<Problem, Solution>* solver;
    CacheManager<Solution>* cacheManager;
    virtual void handleClient(int read, int write){};
    virtual ~MyTestClientHandler(){};
};
#endif //EX4_CLIENTHANDLER_H
