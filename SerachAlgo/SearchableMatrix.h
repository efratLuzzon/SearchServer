//
// Created by user on 08  2020.
//

#ifndef EX4_SEARCHABLEMATRIX_H
#define EX4_SEARCHABLEMATRIX_H

#include "Isearchable.h"
#include "../Graph.h"
#include <vector>
#include <unordered_map>

using namespace std;
template <class T>
class SearchableMatrix : public Isearchable<T> {
private:
    vector<vector<State<T>>> _matrix;
    State<T> _initialState;
    State<T> _goalState;
public:
    SearchableMatrix(State<T>& initialState, State<T>& goalState, vector<vector<State<T>>>& matrix);
    virtual State<T> getInitialState();
    virtual State<T> getgoalState();
    virtual vector<State<T>> getAllPossibleStates(State<T> n);
    virtual bool isGoal(State<T>);
    //virtual double getweightOfPath(State<T> first, State<T> second);
};
template<class T>
SearchableMatrix<T>::SearchableMatrix(State<T>& initialState, State<T>& goalState, vector<vector<State<T>>>& matrix) {
    _matrix = matrix;
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
vector<State<T>> SearchableMatrix<T>::getAllPossibleStates(State<T> state) {
    T x = state.getStateX();
    T y = state.getStateY();
    //T is always implement as int in this class
    vector<State<T>> adj;
    if(x > 0) {
        adj.push_back(_matrix[x - 1][y]);
    }
    if(y > 0) {
        adj.push_back(_matrix[x][y - 1]);
    }
    if( x < _matrix.size() - 1) {
        adj.push_back(_matrix[x + 1][y]);
    }
    if( y < _matrix[0].size() - 1) {
        adj.push_back(_matrix[x][y + 1]);
    }
    return adj;
}

//template<class T>
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
