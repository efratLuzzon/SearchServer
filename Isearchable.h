//
// Created by user on 08/01/2020.
//

#ifndef EX4_ISEARCHABLE_H
#define EX4_ISEARCHABLE_H

#include "State.h"
template <class T>
class Isearchable {
public:
    virtual State<T> getInitialState();
    virtual State<T> getgoalState();
    virtual bool isGoal();
};

#endif //EX4_ISEARCHABLE_H
