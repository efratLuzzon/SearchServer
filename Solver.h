//
// Created by magshimim on 8.1.2020.
//
#pragma once
#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

#include "SerachAlgo/Isearcher.h"
#include <string>
using namespace std;
template<class Problem, class Solution> class Solver {

public:
    virtual Solution solve(Problem*) = 0;
    virtual ~Solver(){}
};
template<class Problem, class Solution, class T>
class ObjectAdapterSolver : public Solver<Problem, Solution> {
private:
    Isearcher<T, Solution>* searcher;
public:
    ObjectAdapterSolver(Isearcher<T, Solution>*);
    virtual Solution solve(Problem*);
    virtual ~ObjectAdapterSolver(){}
};
template<class Problem, class Solution, class T>
ObjectAdapterSolver<Problem, Solution,T>::ObjectAdapterSolver(Isearcher<T, Solution>* search) {
    searcher = search;
}
template<class Problem, class Solution, class T>
Solution ObjectAdapterSolver<Problem, Solution,T>::solve(Problem* problem) {
    Solution solution = searcher->search(*problem);
    return solution;
}


template<class Problem, class Solution>
class StringReverser :public Solver<Problem, Solution>{
    virtual Solution solve(Problem);
    virtual ~StringReverser(){}
};
template<class Problem, class Solution>
Solution StringReverser<Problem, Solution>::solve(Problem name) {
    Solution reverse;
    for(int i = name->length() - 1; i >= 0; i--){
        reverse += name[i];
    }
    return reverse;
}
#endif //EX4_SOLVER_H
