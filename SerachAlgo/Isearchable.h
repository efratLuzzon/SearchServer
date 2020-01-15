//
// Created by user on 08/01/2020.
//

#ifndef EX4_ISEARCHABLE_H
#define EX4_ISEARCHABLE_H

#include "../State.h"
#include <vector>

using namespace std;
template <class T>
class Isearchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual State<T>* getgoalState() = 0;
    virtual vector<State<T>*> getAllPossibleStates(State<T>*) = 0;
    virtual ~Isearchable(){}
};


#endif //EX4_ISEARCHABLE_H
