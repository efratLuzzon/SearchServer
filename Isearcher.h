//
// Created by user on 08/01/2020.
//

#ifndef EX4_ISEARCHER_H
#define EX4_ISEARCHER_H

#include "Isearchable.h"
#include "Solution.h"
template <class T>
class Isearcher {
public:
    virtual Solution search (Isearchable<State<T>> searchable);
    virtual int getNumOfNodesEvaluated();
};
#endif //EX4_ISEARCHER_H
