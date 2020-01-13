//
// Created by user on 13 ינואר 2020.
//

#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H
#include "SerachAlgo/SearcherPriority.h"
using namespace std;
template <class T, class Solution>
class AStar : Searcher<T,Solution> {
public:
    AStar();
    virtual Solution search (Isearchable<State<T>> searchable);
    Solution backTrace();
};
template <class T, class Solution>
Solution AStar<T,Solution>::search(Isearchable<State<T>> searchable) {}

template <class T, class Solution>
Solution AStar<T,Solution>::backTrace() {

}

#endif //EX4_ASTAR_H
