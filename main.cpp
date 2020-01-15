#include <iostream>
#include <string>
#include "ServerImplements.h"
#include "BestFirstSearch.h"
#include "Solver/Solver.h"
#include "Algo/BFS.h"
#include "clientHandler/MatrixClientHandler.h"
#include "Solver/OAdapter.h"
#include "CacheManager/FileCacheManager.h"

using namespace std;



int main() {
    MySerialServer serialServer;
    BFS<int> bfs;
    ObjectAdapterSolver oa(bfs);
    Solver<vector<vector<double>>,string> * solve = new ObjectAdapterSolver(&bfs);
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
