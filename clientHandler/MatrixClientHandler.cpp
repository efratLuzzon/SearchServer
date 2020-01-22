//
// Created by magshimim on 14.1.2020.
//

#include "MatrixClientHandler.h"

void GetMatrix::handleClient(int clientSocket) {
    bool endRead = false;
    string problem;
    string weight;
    string solution;
    string allProblem = "";
    vector<double > oneLineMatrix;
    vector<vector<double >> linesMatrix;

    if (clientSocket < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    while (!endRead) {
        char buf[1024] = {0};
        int n = read(clientSocket, buf, 1024);
        if (n == -1) {
            cerr << "error in read line from clinet" << endl;
        }
        problem = buf;
        for(int i = 0; (unsigned int) i < problem.length(); i++) {
            if (problem[i] == 'e') {
                endRead = true;
                break;
            }
            if (problem[i] == '@' || problem[i] == 'A') {
                break;
            } else if (problem[i] == '\n' || problem[i] == '!') {
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
    for(int i = 0; (unsigned int) i < linesMatrix.size(); i++){
        for(int j = 0; (unsigned int) j < linesMatrix[i].size(); j++){
            allProblem +=to_string(linesMatrix[i][j]) + ",";
        }
        allProblem +=";";
    }
    allProblem +=";";

    //get num hash
    std::size_t str_hash =  std::hash<std::string>{}(allProblem);
    allProblem = to_string(str_hash);
    std::ifstream file(allProblem);
    if(_cacheManager->isExsist(allProblem) || file.good()){
        solution = this->_cacheManager->get(allProblem);
    } else {
        solution = _solver->solve(linesMatrix);
        if(solution == ""){
            solution = "no solution";
        }
        this->_cacheManager->insert(allProblem, solution);
    }
    int isSend = write(clientSocket, solution.c_str(),solution.length());
    if(isSend == -1){
        std::cout << "Error sending message" << std::endl;
    }
    oneLineMatrix.clear();
    linesMatrix.clear();
}