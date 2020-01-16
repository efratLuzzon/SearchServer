//
// Created by user on 08 ינואר 2020.
//
#pragma once
#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include <set>
#include <queue>
#include "../SerachAlgo/SearcherAbstract.h"
using namespace std;

template <class T>
class BestFirstSearch : public SearcherAbstract<T> {
    class Compare {
    public:
        bool operator()(State<T>* left, State<T>* right) {
            return (left->getCost()) > (right->getCost());
        }
    };
private:
    int indexPriorityAdjInVector;
    int indexClosedAdjInVector;
    std::set<State<T>*> closed;
    std::priority_queue<State<T>*, vector<State<T>*>,Compare> _vertex_queue;
    vector<State<T>*> _vectorQ;
    bool InPriorityQuque(State<T>*);
    bool isAdjInClosedList(State<T>*);
    void eraseFromPriorityQueqe(int);
    State<T>* getStateFromClosed(State<T>*);
public:
    BestFirstSearch() : indexPriorityAdjInVector(-1), indexClosedAdjInVector(-1){}
    virtual vector<State<T>*> search (Isearchable<T>* searchable); //abstract method
//    ~BestFirstSearch();
};
template <class T>
State<T>* BestFirstSearch<T>::getStateFromClosed(State<T>* newState) {
    for(State<T>* s: closed){
        if(s->Equals(newState)){
            return s;
        }
    }
}
template <class T>
void BestFirstSearch<T>::eraseFromPriorityQueqe(int index) {
    _vectorQ.clear();
    while (!_vertex_queue.empty()){
        State<T>* state = _vertex_queue.top();
        _vectorQ.push_back(state);
        _vertex_queue.pop();
    }
    for (int i = 0; i < _vectorQ.size(); i++){
        if(i != index){
            _vertex_queue.push(_vectorQ[i]);
        }
    }
}
template <class T>
bool BestFirstSearch<T>::isAdjInClosedList(State<T> * adj) {
    indexClosedAdjInVector = -1; // adj isnt in closed
    int i = -1;
    bool inClosed = false;
    for(State<T>* s: closed){
        i++;
        if(s->Equals(adj)){
            inClosed = true;
            indexClosedAdjInVector = i;
            break;
        }
    }
    return inClosed;
}
template <class T>
bool BestFirstSearch<T>::InPriorityQuque(State<T>* stateCompare) {
    bool isExists = false;
    indexPriorityAdjInVector = -1; // stateCompare isnt in priority.
    _vectorQ.clear();
    while(!_vertex_queue.empty()){
        State<T>* state = _vertex_queue.top();
        _vectorQ.push_back(state);
        _vertex_queue.pop();
    }
    for(int i = 0; i < _vectorQ.size(); i++){
        if(_vectorQ[i]->Equals(stateCompare)){
            isExists = true;
            indexPriorityAdjInVector = i;
        }
        _vertex_queue.push(_vectorQ[i]);
    }
    return isExists;
}

template <class T>
vector<State<T>*> BestFirstSearch<T>::search(Isearchable<T>* searchable) {
    this->numOfNodesEvaluated = 0;
    State<T>* init = searchable->getInitialState();
    State<T>* goal = searchable->getgoalState();
    _vertex_queue.push(init);
//    typename set<State<T>*>::iterator iteratorClosed;

    while(!_vertex_queue.empty()){
        this->numOfNodesEvaluated++;
        State<T>* current_vertex = _vertex_queue.top();
        _vertex_queue.pop();
        closed.insert(current_vertex);

        if ((*goal).Equals(current_vertex)) {

            vector<State<T>*> result = this->traceBack(init, current_vertex);
            std::cout << "Found it " << std::endl;
            return result;
        }

        vector<State<T>*> adj = searchable->getAllPossibleStates(current_vertex);
        for (int j = 0; j < adj.size(); j++) {
           double currentPath = current_vertex->getCost() + adj[j]->getCost();
           bool inClosed = isAdjInClosedList(adj[j]);
           bool inPriority = InPriorityQuque(adj[j]);
           if(!inClosed && !inPriority) {  // adj is not in CLOSED and s is not in OPEN:
                _vertex_queue.push(adj[j]);
           } else if(!inClosed) { //adj inst in close
                double oldCost;
//                if(indexPriorityAdjInVector == -1){ // adj in closed list
//                    auto oldState = getStateFromClosed(adj[j]);
//                    oldCost = oldState->getCost();
//                } else { // adj in open list
                oldCost = _vectorQ[indexPriorityAdjInVector]->getCost();
//                }
                if(oldCost > adj[j]->getCost()){
//                    if(indexPriorityAdjInVector == -1){ // adj in closed list
//                        _vertex_queue.push(adj[j]);
//                    } else { // in OPEN
                    eraseFromPriorityQueqe(indexPriorityAdjInVector);
                    _vertex_queue.push(adj[j]);
                    }
                }
            }
        }
        vector<State<T> *> emptyVector;
        return emptyVector;
    }
    /*Best First Search:
    OPEN = [initial state] // a priority queue of states to be evaluated
    CLOSED = [] // a set of states already evaluated
    while OPEN is not empty
    do
        1. n  dequeue(OPEN) // Remove the best node from OPEN
    2. add(n,CLOSED) // so we won’t check n again
    3. If n is the goal state,
    backtrace path to n (through recorded parents) and return path.
    4. Create n's successors.
    5. For each successor s do:
    a. If s is not in CLOSED and s is not in OPEN:
    i. update that we came to s from n
    ii. add(s,OPEN)
    b. Otherwise, if this new path is better than previous one //todo and s isnt in closed
    i. If it is not in OPEN add it to OPEN.
            ii. Otherwise, adjust its priority in OPEN
    done*/




#endif //EX4_BESTFIRSTSEARCH_H
