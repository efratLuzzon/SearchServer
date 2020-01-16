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
            std::cout << "Found it " << std::endl;
            return result;
        }

        vector<State<T>*> adj = searchable->getAllPossibleStates(current_vertex);
        for (int j = 0; j < adj.size(); j++) {
            if (!(visited_vertices.find(adj[j]->getState()) != visited_vertices.end())) {
                    visited_vertices.insert(adj[j]->getState());
                    vertex_queue.push(adj[j]);
            }
        }
    }
    vector<State<T> *> emptyVector;
    return emptyVector;
}


#endif //EX4_BFS_H
