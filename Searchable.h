//
// Created by user on 08 ינואר 2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include "Isearchable.h"
#include <vector>
#include <unordered_map>

using namespace std;
template <class T>
class Searchable : Isearchable<T> {
    vector<State<T>> _vertexs;
    unordered_map<pair<State<T>,State<T>>,double> _edges;
    State<T> _initialState;
    State<T> _goalState;
public:
    Searchable();
    virtual State<T> getInitialState();
    virtual State<T> getgoalState();
    virtual bool isGoal(State<T>);
    virtual vector<State<T>> getAllPossibleStates(State<T> n);
    double getweightOfEdge(State<T>,State<T>);
};
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
    //TODO
}

template<class T>
double Searchable<T>::getweightOfEdge(State<T> first, State<T> second) {
    auto weight = _edges.find({first,second});
    if(weight!= _edges.end()) {
        return weight;
    } else {
        //TODO throw exeption out of map
    }

}


#endif //EX4_SEARCHABLE_H
