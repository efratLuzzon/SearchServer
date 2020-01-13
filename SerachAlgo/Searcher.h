//
// Created by user on 08/01/2020.
//

#ifndef EX4_ALGORITHM_H
#define EX4_ALGORITHM_H

#include "Isearcher.h"
#include "../State.h"
#include <queue>

using namespace std;

template <class T, class Solution>
class Searcher : Isearcher<T, Solution> {
    int evaluatedNodes;
protected:
    Searcher();
    State<T> popOpenList();
    //IMPLEMENT HERE
    virtual int getNumOfNodesEvaluated();
    //IMPLEMENT IN CHILD
    virtual Solution search (Isearchable<State<T>> searchable){};
    virtual int openListSize(){};
    virtual void addToOpenList(State<T>){}
    virtual bool openListContain(State<T>){}
    virtual  bool openListIsEmpty(){}
};

template <class T, class Solution>
Searcher<T, Solution>::Searcher() {
    this->evaluatedNodes = 0;
//    this->openList = new priority_queue<T>;
}
template <class T, class Solution>
int Searcher<T, Solution>::getNumOfNodesEvaluated() {
    return evaluatedNodes;
}

#endif //EX4_ALGORITHM_H
