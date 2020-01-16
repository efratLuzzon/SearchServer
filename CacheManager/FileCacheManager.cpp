//
// Created by magshimim on 15.1.2020.
//

#include <unistd.h>
#include "FileCacheManager.h"


string FileCacheManger::get(string key) {
    pthread_mutex_lock(&mutex);
    string solution;
    auto findKey = numProblem.find(key); //find iterator
    solution = *findKey;
    string line, allSolution;
    ifstream myfile (solution);
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            getline (myfile,line);
            allSolution +=line;
        }
        myfile.close();
    }
    pthread_mutex_unlock(&mutex);
    return allSolution;
}


void FileCacheManger::insert(string key, string obj) {
    pthread_mutex_lock(&mutex);
    fstream data;
    data.open(key,ios::out|ios::binary);
    if(!data.is_open()){
        perror("open file error");
        exit(1);
    }
    size_t len = obj.size();
//    data.write(len, sizeof(size_t));
    data.write(obj.c_str(), len);
    data.close();
//    data.write((char*)&obj,sizeof(obj) +1);
//    data.close();
    numProblem.insert(key);
    pthread_mutex_unlock(&mutex);
}


bool FileCacheManger::isExsist(string key) {
    pthread_mutex_lock(&mutex);
    bool found = true;
    if (numProblem.find(key) == numProblem.end()){
        found = false;
    }
    pthread_mutex_unlock(&mutex);
    return found;
}
