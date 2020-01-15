//
// Created by user on 09 ינואר 2020.
//
#pragma once
#ifndef EX4_GRAPH_H
#define EX4_GRAPH_H
/*
#include <unordered_map>
#include "State.h"
#include <vector>
#include <utility>
using namespace std;
template<class T>
class Graph {
private:
    unordered_map<pair<State<T>, State<T>>, bool>* _vertexs;
    unordered_map<pair<State<T>,State<T>>,double>* _edges;
public:
    Graph(){
//        _vertexs = new unordered_map<State<T>,bool>();
//        _edges = new unordered_map<pair<State<T>,State<T>>,double>();
    }
    double getWeightOfEdge(State<T> first, State<T> second);
    vector<State<T>> getAllNeighbors(State<T>);
    void setVertexVisited(State<T> state);
    bool vertexIsVisited(State<T>);
    void setVertexs(State<T>);
    void setEdges(State<T>& , State<T> &, double);
};
template<class T>
double Graph<T>::getWeightOfEdge(State<T> first, State<T> second) {
    typename unordered_map<pair<State<T>,State<T>>,double>::iterator it = _edges->find({first,second});
    if(it!= _edges->end()) {
        return it->second;
    } else {
        //TODO throw exeption out of map
    }
}
template<class T>
vector<State<T>> Graph<T>::getAllNeighbors(State<T> n) {
    vector<State<T>> neighbors;
    for (pair<State<T>,State<T>> &edge : _edges) {
        if(edge.first.Equals(n)) {
            neighbors.push_back(edge.second);
        }
    }
    return neighbors;
}
template<class T>
bool Graph<T>::vertexIsVisited(State<T> state) {
    typename unordered_map<State<T>,bool>::iterator it = _vertexs.find(state);;
    if(it!= _vertexs->end()) {
        return it->second;
    } else {
        //TODO throw exeption out of map
    }
}
template<class T>
void Graph<T>::setVertexVisited(State<T> state) {
    typename unordered_map<State<T>,bool>::iterator it = _vertexs->find(state);;
    if(it!= _vertexs->end()) {
        _vertexs->at(state) = true;
    } else {
        //TODO throw exeption out of map
    }
}


template<class T>
void Graph<T>::setVertexs(State<T>  node) {
    //TODO
    _vertexs->insert[{node, node}] = false;
//        _vertexs[node] = 5;
//    _vertexs->emplace(node, false);
}
template<class T>
void Graph<T>::setEdges(State<T>&  first, State<T>&  second, double cost){
    _edges->insert[{first, second}] = cost;
}*/
#endif //EX4_GRAPH_H
