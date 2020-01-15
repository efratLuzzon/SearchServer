//
// Created by user on 08/01/2020.
//

#ifndef EX4_ISEARCHER_H
#define EX4_ISEARCHER_H

#include "Isearchable.h"
template <class Problem, class Solution>
class Isearcher {
public:
    virtual Solution search (Isearchable<Problem>* searchable) =  0;
    virtual int getNumOfNodesEvaluated() = 0;
    virtual ~Isearcher(){}
};
#endif //EX4_ISEARCHER_H
