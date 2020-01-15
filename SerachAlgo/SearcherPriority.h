//
// Created by user on 08/01/2020.
//
#pragma once
#ifndef EX4_ALGORITHM_H
#define EX4_ALGORITHM_H

#include "Isearcher.h"
#include "../State.h"
#include <queue>

using namespace std;
/*
template <class T, class Solution>
class Searcher : public Isearcher<T,Solution> {
    priority_queue<State<T>> openList;
    int evaluatedNodes;
protected:
    State<T> popOpenList();
public:
    Searcher();
    virtual int openListSize() const;
    virtual void addToOpenList(State<T>);
    virtual void update(State<T>);
    virtual bool openListContain(State<T>);
    virtual int getNumOfNodesEvaluated();
    virtual bool openListIsEmpty();
};
template <class T,class Solution>
int Searcher<T,Solution>::openListSize() const {
    return openList.size();
}
template <class T,class Solution>
int Searcher<T,Solution>::getNumOfNodesEvaluated() {

}

template <class T,class Solution>
Searcher<T, Solution>::Searcher() {
    //this->evaluatedNodes = 0;
    //this->openList = new priority_queue<T>;
}
template <class T, class Solution>
void Searcher<T, Solution>::addToOpenList(State<T> state) {
    openList.push(state);
}
template <class T, class Solution>
bool Searcher<T, Solution>::openListContain(State<T> state) {
//    for (State<T> s : openList) { //TODO PROBLEM - CANT FIND IN THIS OPERATION
//        if(s.Equals(state)) {
//            return true;
//        }
//    }
//    return false;
}

template<class T, class Solution>
void Searcher<T, Solution>::update(State<T> toUpdate) {
    if(openListContain(toUpdate)) {
        vector<State<T>> temp;
        State<T> s = openList.top();
        while (!s.Equals(toUpdate)) {
            openList.pop();
            temp.push_back(s);
            s = openList.top();
        }
        openList.pop();//pop toUpdate
        openList.push(s); //add toUpdate again
        for(State<T> state : temp) { //bring back all the states
            openList.push(state);
        }
    }
}
template<class T, class Solution>
bool Searcher<T, Solution>::openListIsEmpty() {
    return openList.empty();
}
*/
#endif