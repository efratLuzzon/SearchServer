//
// Created by magshimim on 16.1.2020.
//
#pragma once
#ifndef SERVERSPROJECT_MYPARALLELSERVER_H
#define SERVERSPROJECT_MYPARALLELSERVER_H

#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <thread>
#include <stack>
#include "Side_server.h"
#include "../clientHandler/ClientHandler.h"


class MyParallelServer : public side_server::Server {
    std::stack<pthread_t> threads;
    int sockfd{};
    int port{};
    ClientHandler* clientHandler{};
    bool toStop = false;
public:
    void open(int port, ClientHandler *cH);
    virtual void startThreadOPeration(){}
    void stop();

    static void *startThreadClient(void *data);

    void start();

    virtual ~MyParallelServer() = default;
};

#endif //
