//
// Created by magshimim on 8.1.2020.
//
#pragma once
#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

#include "SerachAlgo/Isearcher.h"
#include "SerachAlgo/SearchableMatrix.h"
#include <string>
using namespace std;
template<class Problem, class Solution> class Solver {

public:
    virtual Solution solve(Problem*) = 0;
    virtual ~Solver(){}
};

template<class T, class Solution>
class ObjectAdapterSolver : public Solver<SearchableMatrix<State<T>>, Solution> {
private:
    Isearcher<T, Solution>* searcher;
public:
    ObjectAdapterSolver(Isearcher<T, Solution>*);
    virtual Solution solve(SearchableMatrix<State<T>>*);
    virtual ~ObjectAdapterSolver(){}
};
template<class T, class Solution>
ObjectAdapterSolver<T, Solution>::ObjectAdapterSolver(Isearcher<T, Solution>* search) {
    searcher = search;
}
template<class T, class Solution>
Solution ObjectAdapterSolver<T, Solution>::solve(SearchableMatrix<State<T>>* problem) {
    Solution solution = searcher->search(problem);
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
