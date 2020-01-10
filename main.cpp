#include <iostream>
#include <string>
#include "ServerImplements.h"
using namespace std;



int main() {
    MySerialServer serialServer;
    ClientHandler* clientHandler = new MyTestClientHandler<string, string>();
    try{
        serialServer.open(5200, *clientHandler);
    } catch( char* e){
        cout<<e<<endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
