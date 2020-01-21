//
// Created by user on 13 ינואר 2020.
//
#pragma once
#ifndef EX4_DFS_H
#define EX4_DFS_H
#include <iostream>
#include "../State.h"
#include "../SerachAlgo/SearcherAbstract.h"
#include <set>
#include <stack>

using namespace std;

template <class T>
class DFS : public SearcherAbstract<T>{
public:
    DFS(){}
    virtual vector<State<T>*> search (Isearchable<T>* searchable); //abstract method
    string getName();
};
template <class T>
vector<State<T>*> DFS<T>::search(Isearchable<T>* searchable) {
    this->numOfNodesEvaluated = 0;
    State<T>* init = searchable->getInitialState();
    State<T>* goal = searchable->getgoalState();
    std::stack<State<T>*> vertex_stack;
    std::set<T> visited_vertices;
    visited_vertices.insert(init->getState()); //mark init
    vertex_stack.push(init);

    while(!vertex_stack.empty()) {
        this->numOfNodesEvaluated++;
        // Get next vertex
        State<T>* current_vertex = vertex_stack.top();
        vertex_stack.pop();

        if ((*goal).Equals(current_vertex)) {
            vector<State<T>*> result = this->traceBack(init, current_vertex);
            std::cout << "Found it " << std::endl;
            return result;
        }

        vector<State<T>*> adj = searchable->getAllPossibleStates(current_vertex);
        for (int j = 0; j < adj.size(); j++) {
            State<T>* neighbor = adj[j];
            if (!(visited_vertices.find(neighbor->getState()) != visited_vertices.end())) {
                neighbor->setCost(neighbor->getInitCost() + current_vertex->getCost());
                visited_vertices.insert(neighbor->getState());
                vertex_stack.push(neighbor);
            }
        }
    }
    vector<State<T> *> emptyVector;
    return emptyVector;
}

template<class T>
string DFS<T>::getName() {
    return "DFS";
}


#endif //EX4_DFS_H
