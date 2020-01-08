//
// Created by user on 08/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H


template <class T>
class State {
    T _state;
    double _cost;
    State<T> _comeFrom;
public:
    State(T state);
    bool Equals(State<T> state);
    void setComeFrom(State<T>);
    double getCost();
    void setCost(double);
};

template<class T>
State<T>::State(T state) {
    _state = state;
}
template<class T>
bool State<T>::Equals(State<T> state) {
    //TODO
}
template<class T>
void State<T>::setComeFrom(State<T> state) {
    _comeFrom = state;
}

#endif //EX4_STATE_H
