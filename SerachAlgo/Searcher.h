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
    //TODO - REMOVE
    priority_queue<State<T>> openList;
    int evaluatedNodes;
protected:
    State<T> popOpenList();
public:
    Searcher();
    int openListSize();
    void addToOpenList(State<T>);
    void update(State<T>);
    bool openListContain(State<T>);
    virtual int getNumOfNodesEvaluated();
    virtual Solution search (Isearchable<State<T>> searchable){};
    bool openListIsEmpty();
};

template <class T, class Solution>
Searcher<T, Solution>::Searcher() {
    this->evaluatedNodes = 0;
    this->openList = new priority_queue<T>;
}
template <class T, class Solution>
void Searcher<T, Solution>::addToOpenList(State<T> state) {
    openList.push(state);
}
template <class T, class Solution>
bool Searcher<T, Solution>::openListContain(State<T> state) {
    for (State<T> s : openList) {
        if(s.Equals(state)) {
            return true;
        }
    }
    return false;
}

template <class T, class Solution>
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
template <class T, class Solution>
bool Searcher<T, Solution>::openListIsEmpty() {
    return openList.empty();
}
template <class T, class Solution>
int Searcher<T, Solution>::getNumOfNodesEvaluated() {
    return evaluatedNodes;
}
template <class T, class Solution>
State<T> Searcher<T, Solution>::popOpenList() {
    evaluatedNodes++;
    auto top = openList.top();
    openList.pop();
    return top;
}
template <class T, class Solution>
int Searcher<T, Solution>::openListSize() {
    return openList.size();
}
#endif //EX4_ALGORITHM_H
