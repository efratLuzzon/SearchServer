//
// Created by magshimim on 8.1.2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#include <istream>
#include <fstream>
#include <iostream>
#include "../Solver/Solver.h"
#include "../CacheManager/CacheManager.h"
#include "../Graph.h"
#include <unistd.h>
#include <vector>
#include <list>
#include <limits>
#include "../SerachAlgo/SearchableMatrix.h"
/*
 *
 * */
class ClientHandler {
public:

    //get stream from client and write answer by server to client
    virtual void handleClient(int soctefd, int clientSocket) = 0;
    virtual ~ClientHandler(){}
};
#endif //EX4_CLIENTHANDLER_H
