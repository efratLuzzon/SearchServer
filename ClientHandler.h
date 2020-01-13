//
// Created by magshimim on 8.1.2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#include <istream>
#include <fstream>
#include <iostream>
#include "Solver.h"
#include "CacheManager.h"
#include "Graph.h"
#include <unistd.h>
#include <vector>
#include <list>

/*
 * This interface determines the type of conversation between the server and the client.
 * ofstream: Stream class to write on files.
 * ifstream: Stream class to read from files
 * */
class ClientHandler {
public:
//    ClientHandler(){}
    //get stream from client and write answer by server to client
    virtual void handleClient(int soctefd, int clientSocket) = 0;
    virtual ~ClientHandler(){}
};


template <class Problem, class Solution>
class GetMatrix : public ClientHandler{
private:
    Solver<Problem, Solution>* solver;
    CacheManager<Solution>* cacheManager;
public:
    virtual void handleClient(int soctefd, int clientSocket);
    virtual ~GetMatrix(){}
};

template <class Problem, class Solution>
void GetMatrix<Problem, Solution>::handleClient(int soctefd, int clientSocket) {
    bool endRead = false;
    Problem problem;
    Problem weight;
    vector<Problem> oneLineMatrix;
    vector<vector<Problem>> linesMatrix;

    while (!endRead) {
        char buf[1024] = {0};
        int n = read(clientSocket, buf, 1024);
        if (n == -1) {
            cerr << "error in read line from clinet" << endl;
        }
        problem = buf;
        for (int i = 0; i < problem.length(); i++) {
            if (problem[i] == 'e') {
                endRead = true;
                break;
            }
            if (problem[i] == '@') {
                break;
            } else if (problem[i] == '\n') {
                oneLineMatrix.push_back(weight);
                weight.clear();
                linesMatrix.push_back(oneLineMatrix);
                oneLineMatrix.clear();
            } else if (problem[i] == ',') {
                oneLineMatrix.push_back(weight);
                weight.clear();
            } else {
                weight += problem[i];
            }
        }
    }


    cout << "finish" << endl;
    Graph<int>* g = new Graph<int>;
    list<State<int>> nodes;
    int numNode = linesMatrix.front().size() - 2; //for goal and start
    for(int k = 0; k < numNode; k++){
          const State<int> node(k);
//        g->setVertexs(node);
//        nodes.push_back(node);
    }



    int i = 0, j = 0;
    for (vector<Problem> oneLine: linesMatrix) {
        for (Problem weigth : oneLine) {
            if (i == 0) { //first time - create Node
//                State<int> *node = new State<int>(j);
//                j++;
//                g.setVertexs(*node);
////                g.
            }
        }
//        i++;
    }



    //    try{
//        Solution  solution = this->cacheManager->get(problem);
//        cout<<"get: "<<solution<<endl;
//    }
//    catch (const char* e) {
//        Solution  solution = solver->solve(problem);
//        this->cacheManager->insert(problem, solution);
//        cout<<"solve: "<<solution<<endl;
//    }

}





/*
 * Class to test the code
 * */
template <class Problem, class Solution>
class MyTestClientHandler : public ClientHandler {
private:
    Solver<Problem, Solution>* solver;
    CacheManager<Solution>* cacheManager;
public:
    MyTestClientHandler(){
        this->cacheManager = new FileCacheManger<Solution>(2);
        this->solver = new StringReverser<Problem, Solution>();
    }
    virtual void handleClient(int soctefd, int clientSocket);
    virtual ~MyTestClientHandler(){}
};
template <class Problem, class Solution>
void MyTestClientHandler<Problem, Solution>::handleClient(int soctefd, int clientSocket) {
    Problem problem;

    char buf[1024] = {0};
    int n = read(clientSocket, buf, 1024);
    if (n == -1) {
        cerr << "error in read line from clinet" << endl;
    }
     problem = buf;
     problem = problem.substr(0, problem.length() - 2);
    try{
        Solution  solution = this->cacheManager->get(problem);
        cout<<"get: "<<solution<<endl;
    }
    catch (const char* e) {
        Solution  solution = solver->solve(problem);
        this->cacheManager->insert(problem, solution);
        cout<<"solve: "<<solution<<endl;
    }


}
#endif //EX4_CLIENTHANDLER_H
