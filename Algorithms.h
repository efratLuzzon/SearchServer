//
// Created by user on 08 ינואר 2020.
//

#ifndef EX4_ALGORITHMS_H
#define EX4_ALGORITHMS_H

#include "Searcher.h"
class BestFirstSearch : Searcher {
public:
    BestFirstSearch();
    virtual Solution search (Isearchable<T> searchable);
};

class DFS : Searcher {
public:
    DFS();
    virtual Solution search (Isearchable<T> searchable);
};
class BFS : Searcher {
public:
    BFS();
    virtual Solution search (Isearchable<T> searchable);
};
class HillClimbing : Searcher {
public:
    HillClimbing();
    virtual Solution search (Isearchable<T> searchable);
};
class AStar : Searcher {
public:
    AStar();
    virtual Solution search (Isearchable<T> searchable);
};




#endif //EX4_ALGORITHMS_H
