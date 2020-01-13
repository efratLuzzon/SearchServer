//
// Created by user on 13 ינואר 2020.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H
#include "SerachAlgo/SearcherPriority.h"
using namespace std;
template <class T, class Solution>
class BFS : Searcher<T,Solution> {
public:
    BFS();
    virtual Solution search (Isearchable<State<T>> searchable);
    Solution backTrace();
};
template <class T, class Solution>
Solution BFS<T,Solution>::search(Isearchable<State<T>> searchable) {}

template <class T, class Solution>
Solution BFS<T,Solution>::backTrace() {}


#endif //EX4_BFS_H
