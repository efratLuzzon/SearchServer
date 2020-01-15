//
// Created by magshimim on 14.1.2020.
//

#include "StringReverse.h"

string StringReverser::solve(string name) {
    string reverse;
    for(int i = name.length() - 1; i >= 0; i--){
        reverse += name[i];
    }
    return reverse;
}