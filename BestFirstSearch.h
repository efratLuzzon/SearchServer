//
// Created by user on 08 ינואר 2020.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include "SerachAlgo/SearcherPriority.h"
using namespace std;
template <class T, class Solution>
class BestFirstSearch : Searcher<T,Solution> {
public:
    BestFirstSearch();
    virtual Solution search (Isearchable<State<T>> searchable);
    Solution backTrace();
};
template <class T, class Solution>
Solution BestFirstSearch<T,Solution>::search(Isearchable<State<T>> searchable) {
    addToOpenList(searchable.getInitialState());
    priority_queue<State<T>> closed = priority_queue<State<T>>();
    while (this->openListSize() > 0) {
        State<T> n = this->popOpenList();
        closed.push(n);
        if(searchable.isGoal(n)) {
            return backTrace();
        }
        vector<State<T>> succerssors = searchable.getAllPossibleStates(n);
        for(State<T> state : succerssors) {
            bool stateIsInClosed = false;
            //check if state is in closed
            for (State<T> stateInClosed : closed) {
                if(stateInClosed.Equals(state)) {
                    stateIsInClosed = true;
                }
            }
            if(!stateIsInClosed && !this->openListContain(state)) {
                state.setComeFrom(n);
                this->addToOpenList(state);
            } else {
                double newPathWeight = n.getCost() + searchable.getweightOfEdge(n, state);
                if(state.getCost() > newPathWeight) { // if this way is better
                    state.setCost(newPathWeight);
                    state.setComeFrom(n);
                    if(!this->openListContain(state)) {
                        this->addToOpenList(state);
                    } else {
                        this->deleteFromOpenList(state);
                        this->addToOpenList(state);
                    }
                }
            }
        }
    }
}
template <class T, class Solution>
Solution BestFirstSearch<T,Solution>::backTrace() {
    return Solution();
}

#endif //EX4_BESTFIRSTSEARCH_H
