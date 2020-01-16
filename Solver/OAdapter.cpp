//
// Created by magshimim on 14.1.2020.
//

#include "OAdapter.h"



string ObjectAdapterSolver::solve(vector<vector<double>> matrix) {
    Isearchable<pair<int, int>> *searchable = new SearchableMatrix(matrix);
    vector<State<pair<int, int>> *> solution = _searcher->search(searchable);
    pair<int,int> prevPair;
    pair<int,int> currPair;
    for(int i = 1; i< solution.size(); i++){
        prevPair = solution[i - 1]->getState();
        currPair = solution[i]->getState();
        if(prevPair.first < currPair.first) {//RIGHT

        } else if(prevPair.first > currPair.first) {//LEFT

        } else if(prevPair.second < currPair.second) {//DOWN

        } else if(prevPair.second > currPair.second) {//UP

        }
    }

    return "efrat";
}