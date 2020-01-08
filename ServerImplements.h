//
// Created by magshimim on 8.1.2020.
//

#ifndef EX4_SERVERIMPLEMENTS_H
#define EX4_SERVERIMPLEMENTS_H

#include "Side_server.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>
/*
 * Implements of server - accept in loop one client each time.
 * */
class MySerialServer : side_server::Server{
public:
    virtual void open(int port, ClientHandler&);
    virtual void buildSocketServer(int port);
    virtual void startThreadOPeration();
    virtual void stop(){};
    virtual ~MySerialServer();
private:
    ClientHandler* clientHandler;
    void startThread();
    std::thread acceptClient;
};
#endif //EX4_SERVERIMPLEMENTS_H
