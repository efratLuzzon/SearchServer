#include <iostream>
#include <string>
#include "ServerImplements.h"
#include "BestFirstSearch.h"
#include "Solver.h"
using namespace std;



int main() {
    MySerialServer serialServer;
//    BestFirstSearch<int, string> searcher;
//    ObjectAdapterSolver<SearchableMatrix<int>, string, int>(searcher);
//    GetMatrix<SearchableMatrix<int>(solve, fileCacheManager);

    Isearcher<int, string>* searcher = new BestFirstSearch<int, string>();
    Solver<SearchableMatrix<int>, string>* solve = new ObjectAdapterSolver<SearchableMatrix<int>, string, int>(searcher);
    CacheManager<string>* fileCacheManger = new FileCacheManger<string>(5);
////    GetMatrix<string, string, int> g = GetMatrix<string, string, int>();
    ClientHandler* clientHandler =
            new GetMatrix <SearchableMatrix<int>, string, int>(solve, fileCacheManger);
    try{
        serialServer.open(5600, *clientHandler);
    } catch( const char* e){
        cout<<e<<endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
