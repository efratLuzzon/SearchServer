#include <iostream>
#include <string>
#include "ServerImplements.h"
#include "Algo/BestFirstSearch.h"
#include "Solver/Solver.h"
#include "Algo/BFS.h"
#include "clientHandler/MatrixClientHandler.h"
#include "Solver/OAdapter.h"
#include "CacheManager/FileCacheManager.h"
#include "Algo/DFS.h"
#include "Algo/BestFirstSearch.h"

using namespace std;



int main() {
    MySerialServer serialServer;
    Isearcher<pair<int,int>, vector<State<pair<int,int>>*>>* bfs = new BestFirstSearch<pair<int, int>>;
    //ObjectAdapterSolver oa = ObjectAdapterSolver(bfs);
    Solver<vector<vector<double>>,string> * solve = new ObjectAdapterSolver(bfs);
    CacheManager<string>* fileCacheManger = new FileCacheManger(5);
    ClientHandler* clientHandler = new GetMatrix (solve, fileCacheManger);
//    try{
        serialServer.open(5600, *clientHandler);
//    } catch( const char* e){
//        cout<<e<<endl;
//    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
