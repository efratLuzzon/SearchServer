//
// Created by magshimim on 14.1.2020.
//

#include "OAdapter.h"



string ObjectAdapterSolver::solve(vector<vector<double>> matrix) {
    Isearchable<pair<int, int>> *searchable = new SearchableMatrix(matrix);
    vector<State<pair<int, int>> *> solution = _searcher->search(searchable);

    return "efrat";
}