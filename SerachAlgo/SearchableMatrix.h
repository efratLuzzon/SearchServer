//
// Created by user on 08 ינואר 2020.
//

#ifndef EX4_SEARCHABLEMATRIX_H
#define EX4_SEARCHABLEMATRIX_H

#include "Isearchable.h"
#include "../Graph.h"
#include <vector>
#include <unordered_map>

using namespace std;
template <class T>
class SearchableMatrix : Isearchable<T> {
private:
    Graph<T> _graphStates;
    State<T> _initialState;
    State<T> _goalState;
public:
    SearchableMatrix(Graph<T> graphStates, State<T> initialState, State<T> goalState);
    virtual State<T> getInitialState();
    virtual State<T> getgoalState();
    virtual vector<State<T>> getAllPossibleStates(State<T> n);
    virtual double getweightOfPath(State<T> first, State<T> second);
    virtual bool isGoal(State<T>);
};
template<class T>
SearchableMatrix<T>::SearchableMatrix(Graph<T> graphStates, State<T> initialState, State<T> goalState) {
    _graphStates = graphStates;
    _initialState = initialState;
    _goalState = goalState;
}
template<class T>
State<T> SearchableMatrix<T>::getInitialState() {
    return _initialState;
}

template<class T>
bool SearchableMatrix<T>::isGoal(State<T> state) {
    return state.Equals(_goalState);
}

template<class T>
State<T> SearchableMatrix<T>::getgoalState() {
    return _goalState;
}

template<class T>
vector<State<T>> SearchableMatrix<T>::getAllPossibleStates(State<T> n) {
    _graphStates.getAllNeighbors(n);
}

template<class T>
//double SearchableMatrix<T>::getweightOfPath(State<T> first, State<T> second) {
//    _graphStates.getWeightOfEdge(first, second);
//}

//template<class T>
//void SearchableMatrix<T>::setVertexVisited(State<T> state) {
//    _graphStates.setVertexVisited(state);
//}
//
//template<class T>
//bool SearchableMatrix<T>::vertexIsVisited(State<T> state) {
//    return _graphStates.vertexIsVisited(state);
//}

#endif //EX4_SEARCHABLEMATRIX_H
