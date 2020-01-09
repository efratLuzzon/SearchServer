//
// Created by user on 08 ינואר 2020.
//

#ifndef EX4_ALGORITHMS_H
#define EX4_ALGORITHMS_H

#include "Searcher.h"
using namespace std;
template <class T>
class BestFirstSearch : Searcher<State<T>> {
public:
    BestFirstSearch();
    virtual Solution search (Isearchable<State<T>> searchable);
    Solution backTrace();
};
template <class T>
Solution BestFirstSearch<T>::search(Isearchable<State<T>> searchable) {
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

template<class T>
Solution BestFirstSearch<T>::backTrace() {
    return Solution();
}

template <class T>
class DFS : Searcher<State<T>> {
public:
    DFS();
    virtual Solution search (Isearchable<State<T>> searchable);
};
Solution DFS::search(Isearchable<State<T>> searchable) {
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
    }*/
    //TODO change the string "balck" "gray" to boll (visit or not)
}

template <class T>
class BFS : Searcher<State<T>> {
public:
    BFS();
    virtual Solution search (Isearchable<State<T>>  searchable);
};

Solution BFS<T>::search(Isearchable<State<T>> searchable) {

}
template <class T>
class HillClimbing : Searcher<State<T>> {
public:
    HillClimbing();
    virtual Solution search (Isearchable<T> searchable);
};
template <class T>
class AStar : Searcher<State<T>> {
public:
    AStar();
    virtual Solution search (Isearchable<T> searchable);
};




#endif //EX4_ALGORITHMS_H
