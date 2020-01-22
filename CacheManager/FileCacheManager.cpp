//
// Created by magshimim on 15.1.2020.
//

#include <unistd.h>
#include "FileCacheManager.h"


string FileCacheManger::get(string key) {
    pthread_mutex_lock(&mutex);
    string solution;
    string line, allSolution;
    auto findKey = numProblem.find(key); //find iterator
    if(findKey == numProblem.end()) {
        ifstream myfile(key);
        if (myfile.is_open()) {
            while (myfile.good()) {
                getline(myfile, line);
                allSolution += line;
            }
            myfile.close();
        }
    } else {
        solution = *findKey;
        ifstream myfile(solution);
        if (myfile.is_open()) {
            while (myfile.good()) {
                getline(myfile, line);
                allSolution += line;
            }
            myfile.close();
        }
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
    data.write(obj.c_str(), len);
    data.close();
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
