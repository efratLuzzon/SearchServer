//
// Created by magshimim on 14.1.2020.
//

#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int soctefd, int clientSocket) {
    string problem;

    char buf[1024] = {0};
    int n = read(clientSocket, buf, 1024);
    if (n == -1) {
        cerr << "error in read line from clinet" << endl;
    }
    problem = buf;
    problem = problem.substr(0, problem.length() - 2);
    try {
        string  solution = this->cacheManager->get(problem);
        cout<<"get: "<<solution<<endl;
    } catch (const char* e) {
        string  solution = solver->solve(problem);
        this->cacheManager->insert(problem, solution);
        cout<<"solve: "<<solution<<endl;
    }
}