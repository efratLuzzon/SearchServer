//
// Created by user on 08  2020.
//
#pragma once
#ifndef EX4_SEARCHABLEMATRIX_H
#define EX4_SEARCHABLEMATRIX_H

#include "Isearchable.h"
#include <vector>
#include <unordered_map>

using namespace std;

class SearchableMatrix : public Isearchable<pair<int, int>> {
private:
    vector<vector<double>> _matrix;
    State<pair<int, int>>* _initialState;
    State<pair<int, int>>* _goalState;
public:

    SearchableMatrix(vector<vector<double>>& matrix);
    virtual State<pair<int, int>>* getInitialState();
    virtual State<pair<int, int>>* getgoalState();
    virtual vector<State<pair<int, int>>*> getAllPossibleStates(State<pair<int, int>>*);
    virtual ~SearchableMatrix(){}
};


#endif //EX4_SEARCHABLEMATRIX_H
