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
    bool InPriorityQuque(int& indexPriorityAdjInVector, State<T>*, vector<State<T>*>* _vectorQ,
                            priority_queue<State<T>*, vector<State<T>*>,Compare>* _vertex_queue);
    bool isAdjInClosedList(int& indexClosedAdjInVector,State<T>*, set<State<T>*>& closed);
    void eraseFromPriorityQueqe(int, vector<State<T>*>* _vectorQ, priority_queue<State<T>*, vector<State<T>*>,Compare>*);

public:
    BestFirstSearch(){}
    virtual vector<State<T>*> search (Isearchable<T>* searchable); //abstract method
};
template <class T>
void BestFirstSearch<T>::eraseFromPriorityQueqe(int index, vector<State<T>*>* _vectorQ, priority_queue<State<T>*, vector<State<T>*>,Compare>* _vertex_queue) {
        _vectorQ->clear();
    while (!_vertex_queue->empty()){
        State<T>* state = _vertex_queue->top();
        _vectorQ->push_back(state);
        _vertex_queue->pop();
    }
    for (int i = 0; i < _vectorQ->size(); i++){
        if(i != index){
            _vertex_queue->push((*_vectorQ)[i]);
        }
    }
}
template <class T>
bool BestFirstSearch<T>::isAdjInClosedList(int& indexClosedAdjInVector, State<T> * adj, set<State<T>*>& closed) {
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
bool BestFirstSearch<T>::InPriorityQuque(int& indexPriorityAdjInVector, State<T>* stateCompare, vector<State<T>*>* _vectorQ, priority_queue<State<T>*, vector<State<T>*>,Compare>* _vertex_queue) {
    bool isExists = false;
    indexPriorityAdjInVector = -1; // stateCompare isnt in priority.
    _vectorQ->clear();
    while(!_vertex_queue->empty()){
        State<T>* state = _vertex_queue->top();
        _vectorQ->push_back(state);
        _vertex_queue->pop();
    }
    for(int i = 0; (unsigned int)i < _vectorQ->size(); i++){
        if((*_vectorQ)[i]->Equals(stateCompare)){
            isExists = true;
            indexPriorityAdjInVector = i;
        }
        _vertex_queue->push((*_vectorQ)[i]);
    }
    return isExists;
}

template <class T>
vector<State<T>*> BestFirstSearch<T>::search(Isearchable<T>* searchable) {
    int indexPriorityAdjInVector = -1;
    int indexClosedAdjInVector = -1;
    this->numOfNodesEvaluated = 0;
    std::set<State<T>*> closed;
    std::priority_queue<State<T>*, vector<State<T>*>,Compare>* _vertex_queue;
    vector<State<T>*>* _vectorQ;
    _vectorQ = new vector<State<T>*>();
    _vertex_queue = new priority_queue<State<T>*, vector<State<T>*>,Compare>();
    State<T>* init = searchable->getInitialState();
    State<T>* goal = searchable->getgoalState();
    _vertex_queue->push(init);

    while(!_vertex_queue->empty()){
        this->numOfNodesEvaluated++;
        State<T>* current_vertex = _vertex_queue->top();
        _vertex_queue->pop();
        closed.insert(current_vertex);

        if ((*goal).Equals(current_vertex)) {
            vector<State<T>*> result = this->traceBack(init, current_vertex);
            return result;
        }

        vector<State<T>*> adj = searchable->getAllPossibleStates(current_vertex);
        for (int j = 0; (unsigned int)j < adj.size(); j++) {
            State<T>* neighbor = adj[j];
            neighbor->setCost(neighbor->getCost() + current_vertex->getCost());
            bool inClosed = isAdjInClosedList(indexClosedAdjInVector,neighbor, closed);
            bool inPriority = InPriorityQuque(indexPriorityAdjInVector, neighbor, _vectorQ, _vertex_queue);
            if(!inClosed && !inPriority) {  // adj is not in CLOSED and s is not in OPEN:
                _vertex_queue->push(neighbor);
            } else if(!inClosed) { //adj inst in close
                double oldCost;

                oldCost = (*_vectorQ)[indexPriorityAdjInVector]->getCost();

                if(oldCost > neighbor->getCost()){
                    eraseFromPriorityQueqe(indexPriorityAdjInVector, _vectorQ, _vertex_queue);
                    _vertex_queue->push(neighbor);
                }
            }
        }
    }
    vector<State<T> *> emptyVector;
    return emptyVector;
}

#endif //EX4_BESTFIRSTSEARCH_H
