## Advanced Programming1 HW4

Search algorithms, CPP language

### General Description:

In this task we were asked to deal with with creating connections between a server and multiple clients.
Each client sends a problem to the server and waits for a solution.
The program finds the best way to go from point to point in graph by search algorithms.
We implemented the search algorithms BestFisrtSearch, A*, BFS, DFS.

 ### Compile and Run

 In order to compile the code use the following command:
 g++ -std=c++14 */*.cpp *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
 Fisrt run a.out and second open a client support TCP and connect to the server.
 The default port to use is 5600 but can accept another. Pay Attention that the port in the code is appropriate to
 the port in the client.
 Enjoy :)
https://github.com/efratLuzzon/miliStone2
 ### Developers
 This program developed by Efrat Luzzun and Aluma Davidi, CS students from Bar-Ilan university, Israel.