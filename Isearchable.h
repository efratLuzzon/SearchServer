//
// Created by user on 08/01/2020.
//

#ifndef EX4_ISEARCHABLE_H
#define EX4_ISEARCHABLE_H

#include "State.h"
#include <vector>

using namespace std;
template <class T>
class Isearchable {
public:
    virtual State<T> getInitialState();
    virtual State<T> getgoalState();
    virtual bool isGoal();
    virtual vector<State<T>> getAllPossibleStates(State<T> n);
    virtual double getweightOfPath(State<T>, State<T>);

};

#endif //EX4_ISEARCHABLE_H
