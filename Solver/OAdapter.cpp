//
// Created by magshimim on 14.1.2020.
//

#include "OAdapter.h"



string ObjectAdapterSolver::solve(vector<vector<double>> matrix) {
    Isearchable<pair<int, int>> *searchable = new SearchableMatrix(matrix);
    vector<State<pair<int, int>> *> solution = _searcher->search(searchable);
    pair<int,int> prevPair;
    pair<int,int> currPair;
    string solutionInString = "";
    double cost;
    for(int i = 1; i< solution.size(); i++){
        cost  = solution[i]->getCost();
        prevPair = solution[i - 1]->getState();
        currPair = solution[i]->getState();
        if(prevPair.first < currPair.first) {//RIGHT
            solutionInString += "DOWN (";
        } else if(prevPair.first > currPair.first) {//LEFT
            solutionInString += "UP (";
        } else if(prevPair.second < currPair.second) {//DOWN
            solutionInString += "RIGHT (";
        } else if(prevPair.second > currPair.second) {//UP
            solutionInString += "LEFT (";
        }
        solutionInString += to_string(cost) +")";
        if(i != solution.size() -1){
            solutionInString += ", ";
        }
    }

    return solutionInString;
}

/*string ObjectAdapterSolver::getName() {
    return this->_searcher->getName();
}*/
