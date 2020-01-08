//
// Created by user on 08/01/2020.
//

#ifndef EX4_ALGORITHM_H
#define EX4_ALGORITHM_H

#include "Isearcher.h"
#include "State.h"
#include <queue>

using namespace std;

template <class T>
class Searcher : Isearcher<T> {
    priority_queue<T> openList;
    int evaluatedNodes;
protected:
    State<T> popOpenList();
public:
    Searcher();
    int openListSize();
    int getNumOfNodesEvaluated();
    virtual Solution search (Isearchable<T> searchable);
};

template <class T>
Searcher<T>::Searcher() {
    this->evaluatedNodes = 0;
    this->openList = new priority_queue<T>;
}

#endif //EX4_ALGORITHM_H
