//
// Created by magshimim on 8.1.2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include "Side_server.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>
#include <sys/time.h>
#include <sys/types.h>

/*
 * Implements of server - accept in loop one client each time.
 * */
class MySerialServer : side_server::Server{
public:
    virtual void open(int port, ClientHandler*);
    virtual void startThreadOPeration();
    virtual void stop(){};
    virtual ~MySerialServer();
private:
    sockaddr_in address;
    int socketfd;
    ClientHandler* clientHandler; //TODO - try to remove
    void startThread();
    std::thread acceptClient;
};
#endif //EX4_MYSERIALSERVER_H
