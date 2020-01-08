//
// Created by user on 08/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H


template <class T>
class State {
    T _state;
    double _cost;
    State<T> comeFrom;
public:
    State(T state);
    bool Equals(State<T> state);
};

template<class T>
State<T>::State(T state) {
    _state = state;
}
template<class T>
bool State<T>::Equals(State<T> state) {
    //TODO
}


#endif //EX4_STATE_H
