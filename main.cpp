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

namespace boot {
    class Main {
    public:
        int main(int argc, char *argv[]) {
            return 0;
        }
    };
}

int main(int argc, char **argv) {
    boot::Main main1;
    main1.main(argc, argv);
    if(argc > 1){
        try {
            string sPort = argv[1];
            int port = stoi(sPort);
            MyParallelServer server;
            Isearcher<pair<int,int>, vector<State<pair<int,int>>*>>* astar = new BestFirstSearch<pair<int,int>>;
            //ObjectAdapterSolver oa = ObjectAdapterSolver(bfs);
            Solver<vector<vector<double>>,string> * solve = new ObjectAdapterSolver(astar);
            CacheManager<string>* fileCacheManger = new FileCacheManger();
            ClientHandler* clientHandler = new GetMatrix (solve, fileCacheManger);
            try{
                server.open(port, clientHandler);
            } catch( const char* e){
                cout<<e<<endl;
            }
        } catch (const char* e) {
            cout<<e<<endl;
        }
    } else {
        cout<<"error - no num port"<<endl;
    }

    return 0;
}
