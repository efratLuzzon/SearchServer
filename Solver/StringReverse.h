//
// Created by magshimim on 14.1.2020.
//
#pragma once
#ifndef EX4_STRINGREVERSE_H
#define EX4_STRINGREVERSE_H

#include <iostream>
#include "Solver.h"

using namespace std;
class StringReverser : public Solver <string, string>{
    virtual string solve(string);
    virtual ~StringReverser(){}
};
#endif //EX4_STRINGREVERSE_H
