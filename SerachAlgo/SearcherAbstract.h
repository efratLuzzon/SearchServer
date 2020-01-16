//
// Created by magshimim on 15.1.2020.
//
#pragma once
#ifndef EX4_SEARCHERABSTRACT_H
#define EX4_SEARCHERABSTRACT_H

#include "Isearcher.h"
template <class T>
class SearcherAbstract : public Isearcher<T , vector<State<T>*>>{
protected:
    int numOfNodesEvaluated = 0;
    vector<State<T>*> traceBack(State<T>* init, State<T>* goal);
public:
    virtual int getNumOfNodesEvaluated();
    virtual ~SearcherAbstract(){}
};
template <class T>
vector<State<T>*> SearcherAbstract<T>::traceBack(State<T> *init, State<T> *goal) {
    vector<State<T>*> prevState;
    vector<State<T>*> path;
    prevState.push_back(goal);
    while(!(*goal).Equals(init)){
        goal = goal->getComeFrom();
        prevState.push_back(goal);
    }
    for(int i = prevState.size() - 1; i >= 0; i--){
        path.push_back(prevState[i]);
    }
    return path;
}
template <class T>
int SearcherAbstract<T>::getNumOfNodesEvaluated() {
    return numOfNodesEvaluated;
}
#endif //EX4_SEARCHERABSTRACT_H
