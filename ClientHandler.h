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
#include "SerachAlgo/SearchableMatrix.h"
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


template <class Problem, class Solution, class T>
class GetMatrix : public ClientHandler {
private:
    Solver<Problem, Solution>* _solver;
    CacheManager<Solution>* _cacheManager;
public:
    GetMatrix(Solver<Problem, Solution>*, CacheManager<Solution>*);
    virtual void handleClient(int soctefd, int clientSocket);
    virtual ~GetMatrix(){}
};
template <class Problem, class Solution, class T>
GetMatrix<Problem, Solution, T>::GetMatrix(Solver<Problem, Solution>* solver, CacheManager<Solution>* cacheManager) {
    _solver = solver;
    _cacheManager = cacheManager;
}

template <class Problem, class Solution, class T>
void GetMatrix<Problem, Solution, T>::handleClient(int soctefd, int clientSocket) {
    bool endRead = false;
    string problem;
    string weight;
    vector<T> oneLineMatrix;
    vector<vector
    <T>> linesMatrix;

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
                //convert string to double
                std::string::size_type sz;
                double cost = std::stod (weight,&sz);
                oneLineMatrix.push_back(cost);
                weight.clear();
                linesMatrix.push_back(oneLineMatrix);
                oneLineMatrix.clear();
            } else if (problem[i] == ',') {
                //convert string to double
                std::string::size_type sz;
                double cost = std::stod (weight,&sz);
                oneLineMatrix.push_back(cost);
                weight.clear();
            } else {
                weight += problem[i];
            }
        }
    }
    vector<vector<State<T>>> matrix;
    for(int i = 0; i < linesMatrix.size() -2 ; i++){
        vector<T> line = linesMatrix[0];
        vector<State<T>> lineState;
        for(int j = 0; j < line.size(); j++){
            State<int> s(i, j);
            s.setCost(line[j]);
            lineState.push_back(s);
        }
        matrix.push_back(lineState);
    }
    int sizeMatrix = linesMatrix.size();
    State<T> initalizeState(linesMatrix[sizeMatrix - 2][0], linesMatrix[sizeMatrix - 2][1]);
    State<T> goalState(linesMatrix[sizeMatrix - 1][0], linesMatrix[sizeMatrix - 1][1]);
    Isearchable<T>* matrixSearchable = new SearchableMatrix<T>(&initalizeState, &goalState, matrix);
    cout<<"end"<<endl;


}


/*
 * Class to test the code
 * */
template <class Problem, class Solution, class T>
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
template <class Problem, class Solution, class T>
void MyTestClientHandler<Problem, Solution, T>::handleClient(int soctefd, int clientSocket) {
    Problem problem;

    char buf[1024] = {0};
    int n = read(clientSocket, buf, 1024);
    if (n == -1) {
        cerr << "error in read line from clinet" << endl;
    }
     problem = buf;
     problem = problem.substr(0, problem.length() - 2);
    try {
        Solution  solution = this->cacheManager->get(problem);
        cout<<"get: "<<solution<<endl;
    } catch (const char* e) {
        Solution  solution = solver->solve(problem);
        this->cacheManager->insert(problem, solution);
        cout<<"solve: "<<solution<<endl;
    }
}
#endif //EX4_CLIENTHANDLER_H
