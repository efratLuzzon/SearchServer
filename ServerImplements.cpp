//
// Created by magshimim on 8.1.2020.
//

#include "ServerImplements.h"
/*
 * open server that accept one client every time.
 * */
void MySerialServer::open(int port,ClientHandler& clientHandler) {
    buildSocketServer(port);
    this->clientHandler = &clientHandler;
    startThread();
}
/*
 * build tcp socket.
 * */
void MySerialServer::buildSocketServer(int port) {
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        throw "Could not create a socket";
    }
    this->socketfd = socketfd;
    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    //the actual bind command

    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        // throw "Could not bind the socket to an IP";
        throw "Could not bind the socket to an IP";
    }
    this->address = address;
    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        throw "Error during listening command";
    } else {
        std::cout<<"Server is now listening ..."<<std::endl;
    }

}
/*
 * accept one client and do operation according clientHandler
 * */
void MySerialServer::startThreadOPeration() {

    while (!side_server::stop) {
        // accepting a client
        int client_socket = accept(this->socketfd, (struct sockaddr *) &this->address,
                                   (socklen_t *) &this->address);
        if (client_socket == -1) {
            throw "Error accepting client";
        }
        //TODO add input and output stream
//        clientHandler.handleClient();
    }
}
/*
 * start thread of accepting clients
 * */
void MySerialServer::startThread() {
    acceptClient = std::thread(&MySerialServer::startThreadOPeration,this); //TODO - here is the problem
}
/*
 * destractor - close the socket and the thread
 * */
MySerialServer::~MySerialServer(){
    close(this->socketfd);
    if(acceptClient.joinable()){
        this->acceptClient.join();
    }
}