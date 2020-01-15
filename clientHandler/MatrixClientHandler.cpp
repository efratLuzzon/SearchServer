//
// Created by magshimim on 14.1.2020.
//

#include "MatrixClientHandler.h"

void GetMatrix::handleClient(int soctefd, int clientSocket) {
    bool endRead = false;
    string problem;
    string weight;
    vector<double > oneLineMatrix;
    vector<vector<double >> linesMatrix;

    while (!endRead) {
        char buf[1024] = {0};
        int n = read(clientSocket, buf, 1024);
        if (n == -1) {
            cerr << "error in read line from clinet" << endl;
        }
        problem = buf;
        for(int i = 0; i < problem.length(); i++) {
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
    //TODO try - catch


//    vector<vector<State<T>>> matrix;
//    int i = 0, j = 0;
//    for(i = 0; i < linesMatrix.size() -2 ; i++){
//        vector<T> line = linesMatrix[0];
//        vector<State<T>> lineState;
//        for(j = 0; j < line.size(); j++){
//            State<int> s(i, j);
//            s.setCost(line[j]);
//            lineState.push_back(s);
//        }
//        matrix.push_back(lineState);
//    }
//    int sizeMatrix = linesMatrix.size();
//    State<T> initalizeState(linesMatrix[sizeMatrix - 2][0], linesMatrix[sizeMatrix - 2][1]);
//    State<T> goalState(linesMatrix[sizeMatrix - 1][0], linesMatrix[sizeMatrix - 1][1]);
//    Isearchable<T>* matrixSearchable = new SearchableMatrix<T>(&initalizeState, &goalState, matrix);
//    matrixSearchable->setMatrixSize(i*j);
//    cout<<"end"<<endl;
//    _solver->solve(matrixSearchable);

}