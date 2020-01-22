//
// Created by user on 13 ינואר 2020.
//
#pragma once
#ifndef EX4_BFS_H
#define EX4_BFS_H

#include "../MyStruct/MyQueqe.h"
#include <iostream>
#include "../State.h"
#include "../SerachAlgo/SearcherAbstract.h"
#include <set>
using namespace std;

template <class T>
class BFS : public SearcherAbstract<T>{
public:
    BFS(){}
    virtual vector<State<T>*> search (Isearchable<T>* searchable); //abstract method
    string getName();
};
template <class T>
vector<State<T>*> BFS<T>::search(Isearchable<T>* searchable) {
    this->numOfNodesEvaluated = 0;
    State<T>* init = searchable->getInitialState();
    State<T>* goal = searchable->getgoalState();
    std::queue<State<T>*> vertex_queue;
    std::set<T> visited_vertices;
    visited_vertices.insert(init->getState()); //mark
    vertex_queue.push(init);

    while(!vertex_queue.empty()) {
        this->numOfNodesEvaluated++;
        // Get next vertex
        State<T>* current_vertex = vertex_queue.front();
        vertex_queue.pop();

        if ((*goal).Equals(current_vertex)) {
            vector<State<T>*> result = this->traceBack(init, current_vertex);
            return result;
        }

        vector<State<T>*> adj = searchable->getAllPossibleStates(current_vertex);
        for (int j = 0; j < adj.size(); j++) {
            State<T>* neighbor = adj[j];
            if (!(visited_vertices.find(neighbor->getState()) != visited_vertices.end())) {
                    neighbor->setCost(neighbor->getInitCost() + current_vertex->getCost());
                    visited_vertices.insert(neighbor->getState());
                    vertex_queue.push(neighbor);
            }
        }
    }
    //if there is no path return empty vector
    vector<State<T> *> emptyVector;
    return emptyVector;
}

template<class T>
string BFS<T>::getName() {
    return "BFS";
}


#endif //EX4_BFS_H
