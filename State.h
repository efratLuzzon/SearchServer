//
// Created by user on 08/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H


template <class T>
class State {
    T _state;
    double _cost;
    State<T>* _comeFrom;
public:
    bool operator < (State<T>) const;
    bool operator > (State<T>) const;
    bool operator == (State<T>) const;


//    const  void operator() (State<T>) const {}

    State(T state);
    bool Equals(State<T> state) const;
    void setComeFrom(State<T>);
    double getCost();
    void setCost(double);
};

template<class T>
State<T>::State(T state) {
    _state = state;
}
template<class T>
bool State<T>::Equals(State<T> state) const{
    bool equal = false;
    if(this->_state == state._state) {
        equal = true;
    }
    return equal;
}
template<class T>
void State<T>::setComeFrom(State<T> state) {
    _comeFrom = state;
}
template<class T>
bool State<T>::operator>(State<T> s) const {
    return (s.getCost() > _cost);
}
template<class T>
bool State<T>::operator<(State<T> s) const {
    return (s.getCost() < _cost);
}
template <class T> double State<T>::getCost() {
    return _cost;
}
template <class T> void State<T>::setCost(double cost) {
    _cost = cost;
}
template <class T>
bool State<T>::operator==(State<T> state) const {
    bool equal = false;
    if(this->_state == state._state) {
        equal = true;
    }
    return equal;
}

//struct iterator_hash {
//    template <typename State<T>>
//    std::size_t operator()(const I &i) const {
//        return std::hash<int>()(*i); // or return sth based on i
//    }
//};
#endif //EX4_STATE_H
