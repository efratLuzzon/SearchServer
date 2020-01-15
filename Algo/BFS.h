//
// Created by user on 13 ינואר 2020.
//
#pragma once
#ifndef EX4_BFS_H
#define EX4_BFS_H

#include "../MyStruct/MyQueqe.h"
#include <iostream>
#include "../SerachAlgo/SearcherPriority.h"
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
    State<T>* init = searchable->getInitialState();
    State<T>* goal = searchable->getgoalState();
    std::queue<State<T>*> vertex_queue;
    std::set<State<T>*> visited_vertices;
    vertex_queue.push(init);

    while(!vertex_queue.empty()) {
        this->numOfNodesEvaluated++;
        // Get next vertex
        State<T>* current_vertex = vertex_queue.front();
        vertex_queue.pop();

        // Make note of current visit
        visited_vertices.insert(current_vertex);
//        std::cout << "Looking at " << current_vertex << std::endl;
        vector<State<T>*> adj = searchable->getAllPossibleStates(current_vertex);

        for (int j = 0; j < adj.size(); j++) {
            //if (*adj[j]) {
                if ((*goal).Equals(adj[j])) {

                    vector<State<T>*> result = this->traceBack(init, goal);
                    std::cout << "Found it " << j << std::endl;
                    return result;
                } else if (!(visited_vertices.find(adj[j]) != visited_vertices.end())) {
                    vertex_queue.push(adj[j]);
                }
            //}
        }
    }
    std::cout << "Could not find it!" << std::endl;
}


#endif //EX4_BFS_H
