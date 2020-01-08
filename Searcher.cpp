//
// Created by user on 08/01/2020.
//

#include "Searcher.h"

int Searcher::getNumOfNodesEvaluated() {
    return evaluatedNodes;
}
State<T> Searcher::popOpenList() {
    evaluatedNodes++;
    auto top = openList.top();
    openList.pop()
    return top;
}
int Searcher::openListSize() {
    return openList.size();
}