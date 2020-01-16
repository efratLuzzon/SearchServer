//
// Created by magshimim on 14.1.2020.
//

#include "SearchableMatrix.h"
SearchableMatrix::SearchableMatrix(vector<vector<double>>& matrix) {
    _matrix = matrix;
    int sizeMatrix = _matrix.size();
    pair<int, int> pairInit= make_pair(_matrix[sizeMatrix - 2][0],_matrix[sizeMatrix - 2][1]);
    _initialState = new State<pair<int, int>>(pairInit, nullptr,
                                              _matrix[pairInit.first][pairInit.second]);

    pair<int, int> pairGoal = make_pair(_matrix[sizeMatrix - 1][0],_matrix[sizeMatrix - 1][1]);
    _goalState = new State<pair<int, int>>(pairGoal, nullptr,
                                           _matrix[pairGoal.first][pairGoal.second]);
}
State<pair<int, int>>* SearchableMatrix::getInitialState() {
    return _initialState;
}

State<pair<int, int>>* SearchableMatrix::getgoalState() {
    return _goalState;
}

vector<State<pair<int, int>>*> SearchableMatrix::getAllPossibleStates(State<pair<int, int>>* state) {
    vector<State<pair<int, int>>*> adj;
    pair<int, int> v = state->getState();
    double costFather = state->getCost();
    double costAdj;
    if(v.first > 0) {
        costAdj = _matrix[v.first - 1][v.second];
        pair<int, int> p = {v.first - 1,v.second};
        if (costAdj != -1) {
            adj.push_back(new State<pair<int, int>>(p, state, costFather + costAdj));
        }
    }
    if(v.second > 0) {
        costAdj = _matrix[v.first][v.second - 1];
        pair<int, int> p = {v.first,v.second - 1};
        if(costAdj != -1) {
            adj.push_back(new State<pair<int, int>>(p, state, costFather + costAdj));
        }
    }
    if(v.first < _matrix.size() - 3) {
        costAdj = _matrix[v.first + 1][v.second];
        pair<int, int> p = {v.first + 1,v.second};
        if (costAdj != -1) {
            adj.push_back(new State<pair<int, int>>(p, state, costFather + costAdj));
        }
    }
    if(v.second < _matrix[0].size() - 1) {
        costAdj = _matrix[v.first][v.second + 1];
        pair<int, int> p = {v.first,v.second + 1};
        if (costAdj != -1) {
            adj.push_back(new State<pair<int, int>>(p, state, costFather + costAdj));
        }
    }
    return adj;
}


