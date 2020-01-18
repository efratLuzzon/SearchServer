//
// Created by user on 08/01/2020.
//
#pragma once
#ifndef EX4_STATE_H
#define EX4_STATE_H

#include <limits>

using namespace std;

template <class T>
class State {
private:
    T _state;
    double _cost;
    State<T>* _comeFrom;
    bool _isViseted;
    double heuristicVlaue = std::numeric_limits<double>::infinity();
public:
    bool isIsViseted() const;
    void setIsViseted(bool isViseted);
    State(T state, State<T>* comeFrom, double cost) : _state(state), _comeFrom(comeFrom), _cost(cost){}
    bool Equals(State<T>* state);
    void setComeFrom(State<T>*);
    State<T>* getComeFrom();
    double getCost() const ;
    void setCost(double);
    T getState();
    double getHeuristicVlaue();
    void setHeuristicVlaue(double);
};
//template<class T>
//T* State<T>::getPtr() {
//    return ptr;
//}
template<class T>
State<T> * State<T>::getComeFrom() {
    return _comeFrom;
}
template<class T>
bool State<T>::Equals(State<T>* state) {
    bool equal = false;
    T cur = this->getState();
    T other = state->getState();
    if((cur.first == other.first) && (cur.second == other.second)){
        equal = true;
    }
    return equal;
//    return (getPtr() == state->getPtr());
}
template<class T>
void State<T>::setComeFrom(State<T>* state) {
    _comeFrom = state;
}

template <class T>  double State<T>::getCost() const {
    return _cost;
}
template <class T>
void State<T>::setCost(double cost) {
    _cost = cost;
}
template <class T>
T State<T>::getState() {
    return _state;
}

template<class T>
bool State<T>::isIsViseted() const {
    return _isViseted;
}

template<class T>
void State<T>::setIsViseted(bool isViseted) {
    _isViseted = isViseted;
}
template<class T>
double State<T>::getHeuristicVlaue() {
    return this->heuristicVlaue;
}
template<class T>
void State<T>::setHeuristicVlaue(double val) {
    this->heuristicVlaue = val;
}
#endif //EX4_STATE_H
