//
// Created by user on 08/01/2020.
//
#pragma once
#ifndef EX4_STATE_H
#define EX4_STATE_H
using namespace std;

template <class T>
class State {
private:
//    T* ptr;
    T _state;
    double _cost;
    State<T>* _comeFrom;
    bool _isViseted;
public:
    bool isIsViseted() const;
    void setIsViseted(bool isViseted);
    State(T state, State<T>* comeFrom, double cost) : /*ptr(&state),*/ _state(state), _comeFrom(comeFrom)
    , _cost(cost){}
    //compare cost
    //inline bool operator==(const State<T>&) const ;

//    T* getPtr();

//    inline bool operator!=(const State<pair<T, T>>& ) const;
//    inline bool operator< (const State<pair<T, T>>&) const;
//    inline bool operator> (const State<pair<T, T>>&) const;
//    inline bool operator<=(const State<pair<T, T>>& ) const;
//    inline bool operator>=(const State<pair<T, T>>&) const;
//    bool Equals(State<pair<T, T>>& state) ;
    bool Equals(State<T>* state);
    void setComeFrom(State<T>*);
    State<T>* getComeFrom();
    double getCost() const ;
    void setCost(double);
    T getState();

};
//template<class T>
//T* State<T>::getPtr() {
//    return ptr;
//}
template<class T>
State<T> * State<T>::getComeFrom() {
    return _comeFrom;
}
/*bool State<T>::operator==(const State<T> & state)const {
    return (getPtr() == state.getPtr());
}*/
//template<class T>
//bool State<T>::operator!=(const State<pair<T, T>> & state)const {
//    return (state.getCost() != _cost);
//}
//template<class T>
//bool State<T>::operator<(const State<pair<T, T>> & state) const{
//    return (state.getCost() < _cost);
//}
//template<class T>
//bool State<T>::operator>(const State<pair<T, T>>& state) const{
//    return (state.getCost() > _cost);
//}
//template<class T>
//bool State<T>::operator>=(const State<pair<T, T>> & state) const{
//    return (state.getCost() >= _cost);
//}
//template<class T>
//bool State<T>::operator<=(const State<pair<T, T>> & state)const {
//    return (state.getCost() <= _cost);
//}
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


#endif //EX4_STATE_H
