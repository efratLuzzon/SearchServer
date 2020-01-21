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
    int i = 0;
    int indexPriorityAdjInVector;
    int indexClosedAdjInVector;
    std::set<State<T>*> closed;
    std::priority_queue<State<T>*, vector<State<T>*>,Compare> _vertex_queue;
    vector<State<T>*> _vectorQ;
    bool InPriorityQuque(State<T>*);
    bool isAdjInClosedList(State<T>*);
    void eraseFromPriorityQueqe(int);
    State<T>* getStateFromClosed(State<T>*);
    void cleanAll();
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
    while(!_vertex_queue.empty()){

        this->numOfNodesEvaluated++;
        State<T>* current_vertex = _vertex_queue.top();

        _vertex_queue.pop();
        closed.insert(current_vertex);

        if ((*goal).Equals(current_vertex)) {

            vector<State<T>*> result = this->traceBack(init, current_vertex);
            std::cout << "Found it " << std::endl;
            cleanAll();
            return result;
        }

        vector<State<T>*> adj = searchable->getAllPossibleStates(current_vertex);
        for (int j = 0; j < adj.size(); j++) {
            State<T>* neighbor = adj[j];
            neighbor->setCost(neighbor->getInitCost() + current_vertex->getCost());
           //double currentPath = current_vertex->getCost() + adj[j]->getCost();
            bool inClosed = isAdjInClosedList(neighbor);
            bool inPriority = InPriorityQuque(neighbor);
            if(!inClosed && !inPriority) {  // adj is not in CLOSED and s is not in OPEN:
                _vertex_queue.push(neighbor);
           } else if(!inClosed) { //adj inst in close
                double oldCost;
                oldCost = _vectorQ[indexPriorityAdjInVector]->getCost();
                if(oldCost > neighbor->getCost()){
                    eraseFromPriorityQueqe(indexPriorityAdjInVector);
                    _vertex_queue.push(neighbor);
                }
           }
        }
    }
    vector<State<T> *> emptyVector;
    cleanAll();
    return emptyVector;
}

template<class T>
void BestFirstSearch<T>::cleanAll() {
    indexPriorityAdjInVector = -1;
    indexClosedAdjInVector = -1;
    closed.clear();
    _vectorQ.clear();
    while (!_vertex_queue.empty()) {
        _vertex_queue.pop();
    }
}

#endif //EX4_BESTFIRSTSEARCH_H
