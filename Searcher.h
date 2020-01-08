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
    priority_queue<State<T>> openList;
    int evaluatedNodes;
protected:
    State<T> popOpenList();
public:
    Searcher();
    int openListSize();
    void addToOpenList(State<T>);
    void deleteFromOpenList(State<T>);
    bool openListContain(State<T>);
    int getNumOfNodesEvaluated();
};

template <class T>
Searcher<T>::Searcher() {
    this->evaluatedNodes = 0;
    this->openList = new priority_queue<T>;
}
template <class T>
void Searcher<T>::addToOpenList(State<T> state) {
    openList.push(state);
}
template <class T>
bool Searcher<T>::openListContain(State<T> state) {
    for (State<T> s : openList) {
        if(s.Equals(state)) {
            return true;
        }
    }
    return false;
}

template<class T>
void Searcher<T>::deleteFromOpenList(State<T> toDelete) {

}

#endif //EX4_ALGORITHM_H
