//
// Created by magshimim on 16.1.2020.
//


#include "MyParallelServer.h"
/*void MyParallelServer::open(int port, ClientHandler & clientHandler) {
    _port = port;

    _clientHandler = &clientHandler;
    int socetfd;

    struct sockaddr_in address;
    socetfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socetfd == -1) {
        //error
        throw "Could not create a socket";
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);

    int n = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &n, sizeof(int));
    //the actual bind command

    if (bind(socetfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        // throw "Could not bind the socket to an IP";
        throw "Could not bind the socket to an IP";
    }


    //making socket listen to the port
    if (listen(socetfd, 10) == -1) { //can also set to SOMAXCON (max connections)
        throw "Error during listening command";
    } else {
        std::cout<<"Server is now listening ..."<<std::endl;
    }
    start();
}
void MyParallelServer::start() {

    sockaddr_in address{};
    int addrlen = sizeof(address);

    timeval timeout;
    int newClient;

    while (true) {
        newClient = accept(sockfd,(struct sockaddr *) &address,(socklen_t *) &addrlen);
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));
        if(newClient == -1){
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
                stop();
                break;
            }
            perror("accept");
            exit(EXIT_FAILURE);
        }
        setsockopt(newClient, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        auto dataSocket = new Data();
        dataSocket->clientHandler = _clientHandler;
        dataSocket->client = newClient;

        pthread_t pthread;
        if (pthread_create(&pthread, nullptr, startThreadClient, dataSocket) < 0) {
            perror("error on creating thread to client");
            exit(1);
        }
        threads.push_back(pthread);
    }
//    stop();
}
void * MyParallelServer::startThreadClient(void * data) {
    auto dataClient = (Data *) data;
    dataClient->clientHandler->handleClient(dataClient->client);
    delete dataClient;
}
void MyParallelServer::stop() {
    for(auto &t: this->threads){
        pthread_join(t, nullptr);
    }
    close(this->sockfd);
}
MyParallelServer::~MyParallelServer() {
//    for(auto &t: this->threads){
//        if(t.joinable()){
//            t->join();
//        }
//    }
}*/
struct info {
    int sock;
    ClientHandler *clientHandler;
};

void MyParallelServer::open(int port, ClientHandler* clientHandler) {
    this->port = port;
    this->clientHandler = clientHandler;
    int server_fd;
    struct sockaddr_in address{};
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    int n = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &n, sizeof(int));
    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        perror("socket bind");
        exit(1);
    }

    if (listen(sockfd, 5) == -1) {
        perror("socket listen");
        exit(1);
    }
    start();
}

void MyParallelServer::stop() {
    while (!this->threads.empty()) {
        pthread_join(this->threads.top(), nullptr);
        this->threads.pop();
    }
    toStop = true;
}

void *MyParallelServer::startThreadClient(void *params) {
    auto data = (info *) params;
    data->clientHandler->handleClient(data->sock);
}

void MyParallelServer::start() {
    sockaddr_in address{};
    int addrlen = sizeof(address);

    timeval timeout;
    int newSocket;
    while (!this->toStop) {
        timeout.tv_sec = 120;
        timeout.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        newSocket = accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &addrlen);
        if (newSocket < 0) {
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
                cout << "Timeout" << endl;
                stop();
                break;
            }
            perror("accept");
            exit(EXIT_FAILURE);
        }
        cout << "Accepted client" << endl;
        setsockopt(newSocket, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        auto data = new info;
        data->clientHandler = this->clientHandler;
        data->sock = newSocket;
        pthread_t trid;
        if (pthread_create(&trid, nullptr, startThreadClient, data) < 0) {
            perror("error on creating thread");
            exit(1);
        }
        this->threads.push(trid);
    }
    close(this->sockfd);
}