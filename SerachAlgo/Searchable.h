//
// Created by user on 08 ינואר 2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include "Isearchable.h"
#include "../Graph.h"
#include <vector>
#include <unordered_map>

using namespace std;
template <class T>
class Searchable : Isearchable<T> {
private:
    Graph<T> _graphStates;
    State<T> _initialState;
    State<T> _goalState;
public:
    Searchable(Graph<T> graphStates, State<T> initialState, State<T> goalState);
    virtual State<T> getInitialState();
    virtual State<T> getgoalState();
    virtual vector<State<T>> getAllPossibleStates(State<T> n);
    virtual double getweightOfPath(State<T> first, State<T> second);
    virtual bool isGoal(State<T>);
};
template<class T>
Searchable<T>::Searchable(Graph<T> graphStates, State<T> initialState, State<T> goalState) {
    _graphStates = graphStates;
    _initialState = initialState;
    _goalState = goalState;
}
template<class T>
State<T> Searchable<T>::getInitialState() {
    return _initialState;
}

template<class T>
bool Searchable<T>::isGoal(State<T> state) {
    return state.Equals(_goalState);
}

template<class T>
State<T> Searchable<T>::getgoalState() {
    return _goalState;
}

template<class T>
vector<State<T>> Searchable<T>::getAllPossibleStates(State<T> n) {
    _graphStates.getAllNeighbors(n);
}

template<class T>
double Searchable<T>::getweightOfPath(State<T> first, State<T> second) {
    _graphStates.getWeightOfEdge(first, second);
}

//template<class T>
//void Searchable<T>::setVertexVisited(State<T> state) {
//    _graphStates.setVertexVisited(state);
//}
//
//template<class T>
//bool Searchable<T>::vertexIsVisited(State<T> state) {
//    return _graphStates.vertexIsVisited(state);
//}

#endif //EX4_SEARCHABLE_H
