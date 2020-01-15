//
// Created by magshimim on 14.1.2020.
//
#pragma once
#ifndef EX4_OADAPTER_H
#define EX4_OADAPTER_H

#include "Solver.h"
#include <vector>
#include <iostream>
using namespace std;
class ObjectAdapterSolver : public Solver<vector<vector<double>>,string>{
private:
    Isearcher<pair<int,int>, vector<State<pair<int,int>>*>>* _searcher;
public:
    ObjectAdapterSolver(Isearcher<pair<int,int>, vector<State<pair<int,int>>*>>* searcher) : _searcher(searcher){}
    virtual string solve(vector<vector<double>>){ return "std::__cxx11::string()"; }
    virtual ~ObjectAdapterSolver(){}
};
#endif //EX4_OADAPTER_H
