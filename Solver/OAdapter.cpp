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
    int cost;
    for(int i = 1; (unsigned int)i< solution.size(); i++){
        cost  = int (solution[i]->getCost());
        prevPair = solution[i - 1]->getState();
        currPair = solution[i]->getState();
        if(prevPair.first < currPair.first) {//RIGHT
            solutionInString += "Down (";
        } else if(prevPair.first > currPair.first) {//LEFT
            solutionInString += "Up (";
        } else if(prevPair.second < currPair.second) {//DOWN
            solutionInString += "Right (";
        } else if(prevPair.second > currPair.second) {//UP
            solutionInString += "Left (";
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
