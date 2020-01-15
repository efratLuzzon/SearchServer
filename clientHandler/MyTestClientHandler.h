//
// Created by magshimim on 14.1.2020.
//
#pragma once
#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H

#include "../Solver/Solver.h"
#include "../CacheManager/CacheManager.h"
#include "ClientHandler.h"
#include "../Solver/StringReverse.h"
#include "../CacheManager/FileCacheManager.h"

/*
 * Class to test the code
 * */

class MyTestClientHandler : public ClientHandler {
private:
    Solver<string, string>* solver;
    CacheManager<string>* cacheManager;
public:
    MyTestClientHandler(){
        this->cacheManager = new FileCacheManger(2);
        this->solver = new StringReverser();
    }
    virtual void handleClient(int soctefd, int clientSocket);
    virtual ~MyTestClientHandler(){}
};
#endif //EX4_MYTESTCLIENTHANDLER_H
