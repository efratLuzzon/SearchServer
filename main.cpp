#include <iostream>
#include <string>
#include "Server/MySerialServer.h"
#include "Algo/BestFirstSearch.h"
#include "Solver/Solver.h"
#include "Algo/BFS.h"
#include "clientHandler/MatrixClientHandler.h"
#include "Solver/OAdapter.h"
#include "CacheManager/FileCacheManager.h"
#include "Algo/DFS.h"
#include "Algo/BestFirstSearch.h"
#include "Server/MyParallelServer.h"
#include "Algo/AStar.h"
using namespace std;



int main() {

    std::string str1 = "efrat";
    std::string str2 = "luzzon";
    std::string str3 = "avital";
    std::string str4 = "luzzon";
    std::string str5 = "avital";

    std::size_t str_hash = std::hash<std::string>{}(str1);
    string a = to_string(str_hash);
    cout<< str1<< std::hash<std::string>{}(str1)<<endl;
    cout<< a<< endl;
//    cout<< str3<< std::hash<std::string>{}(str3)<<endl;
//    cout<< str4<< std::hash<std::string>{}(str4)<<endl;
//    cout<< str5<< std::hash<std::string>{}(str5)<<endl;



    //MySerialServer server;
    MyParallelServer server;
    Isearcher<pair<int,int>, vector<State<pair<int,int>>*>>* astar = new BFS<pair<int,int>>;
    //ObjectAdapterSolver oa = ObjectAdapterSolver(bfs);
    Solver<vector<vector<double>>,string> * solve = new ObjectAdapterSolver(astar);
    CacheManager<string>* fileCacheManger = new FileCacheManger();
    ClientHandler* clientHandler = new GetMatrix (solve, fileCacheManger);
//    try{
    server.open(5892, clientHandler);
//    } catch( const char* e){
//        cout<<e<<endl;
//    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
