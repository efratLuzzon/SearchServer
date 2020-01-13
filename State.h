//
// Created by user on 08/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H


template <class T>
class State {
private:
    T _stateX;
    T _stateY;
    double _cost;
    State<T>* _comeFrom;
public:
    State(T state1, T state2);
    bool operator < (State<T>&) const;
    bool operator > (State<T>&) const;
    bool Equals(State<T>& state) const;
    void setComeFrom(State<T>& );
    const double getCost();
    void setCost(double);
    T getStateX();
    T getStateY();
};

template<class T>
State<T>::State(T state1, T state2) {
    _stateX = state1;
    _stateY = state2;
}
template<class T>
bool State<T>::Equals(State<T>& state) const{
    bool equal = false;
    if((this->_stateX = state._stateX) && (_stateY = state._stateY)){
        equal = true;
    }
    return equal;
}
template<class T>
void State<T>::setComeFrom(State<T> &state) {
    _comeFrom = state;
}
template<class T>
bool State<T>::operator>(State<T>& s) const {
    return (s.getCost() > _cost);
}
template<class T>
bool State<T>::operator<(State<T>& s) const {
    return (s.getCost() < _cost);
}
template <class T> const double State<T>::getCost() {
    return _cost;
}
template <class T>
void State<T>::setCost(double cost) {
    _cost = cost;
}
template <class T>
T State<T>::getStateX() {
    return _stateX;
}
template <class T>
T State<T>::getStateY() {
    return _stateY;
}


#endif //EX4_STATE_H
