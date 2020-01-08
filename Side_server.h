//
// Created by magshimim on 8.1.2020.
//

#ifndef EX4_SIDE_SERVER_H
#define EX4_SIDE_SERVER_H
/*
 * Server interface - has two methods: open server socket and stop server opertion.
 * */
#include <netinet/in.h>
#include "ClientHandler.h"

namespace side_server {
    bool stop = false; // to close the thread server
    /*
     * Server interface.
     * */
    class Server {
    public:
        virtual void open(int port, ClientHandler&) = 0;
        virtual void buildSocketServer(int port) = 0;
        virtual void startThreadOPeration() = 0;
        virtual void stop() = 0;
        virtual ~Server(){}

    protected:
        int socketfd;
        sockaddr_in address;
    };


}
#endif //EX4_SIDE_SERVER_H
