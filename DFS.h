//
// Created by user on 13 ינואר 2020.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H
/*
#include "SerachAlgo/SearcherPriority.h"
using namespace std;
template <class T, class Solution>
class DFS : Searcher<T,Solution> {
public:
    DFS();
    virtual Solution search (Isearchable<State<T>> searchable);
    Solution backTrace();
};
template <class T, class Solution>
Solution DFS<T,Solution>::search(Isearchable<State<T>> searchable) {
    /*addToOpenList(searchable.getInitialState());
    while(!openListIsEmpty()) {
        State<T> n = popOpenList();
        searchable.setValOfVertex(n, "Gray");
        if (n.Equals(searchable.getgoalState())) {
            return backTrace();
        }
        vector<State<T>> succerssors = searchable.getAllPossibleStates(n);
        for (State<T> state : succerssors) {
            if (searchable.getValOfVertex(state) == "") {
                addToOpenList(state);
            }
        }
        searchable.setValOfVertex(n, "Black");
    }
}

template <class T, class Solution>
Solution DFS<T,Solution>::backTrace() {}
*/


#endif //EX4_DFS_H
