//
// Created by magshimim on 8.1.2020.
//
#pragma once
#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

#include "../SerachAlgo/Isearcher.h"
#include "../SerachAlgo/SearchableMatrix.h"
#include <string>
using namespace std;
template<class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(Problem) = 0;
    //virtual string getName();
    virtual ~Solver(){}
};



#endif //EX4_SOLVER_H
