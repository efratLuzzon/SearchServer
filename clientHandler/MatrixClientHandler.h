//
// Created by magshimim on 14.1.2020.
//
#pragma once
#ifndef EX4_MATRIXCLIENTHANDLER_H
#define EX4_MATRIXCLIENTHANDLER_H

#include "ClientHandler.h"

class GetMatrix : public ClientHandler {
private:
    Solver<vector<vector<double>>,string> * _solver;
    CacheManager<string>* _cacheManager;
public:
    GetMatrix(Solver<vector<vector<double>>,string> * solver, CacheManager<string>* cacheManager):
    _solver(solver), _cacheManager(cacheManager){}

    virtual void handleClient(int soctefd, int clientSocket);
    virtual ~GetMatrix(){}
};
#endif //EX4_MATRIXCLIENTHANDLER_H
