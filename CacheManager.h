//
// Created by magshimim on 8.1.2020.
//
#pragma once
#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

#include <list>
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;


/*
 * Interface of CacheManger.
 * key - the problem
 * object - the solution
 * EACH OBJECT MUST HAVE CLASSNAME!!
 * */
template <class Object> class CacheManager {

public:
    virtual bool isObjectInCache(string) = 0;
    virtual Object get(string) = 0;
    virtual void insert(string, Object) = 0;
    virtual ~CacheManager(){}
};

template <class Object>
class FileCacheManger :  CacheManager<Object>{
private:
    unordered_map<string, string> diskSolution; // problem, fileName
    Object obtToClone;
    bool first = true;

public:
    FileCacheManger(){}
    Object getObtToClone() const;
    void setObtToClone(Object obtToClone);
    virtual bool isObjectInCache(string);
    virtual Object get(string);
    virtual void insert(string, Object);
    void writeToFile(const Object& obj, string);
    virtual ~FileCacheManger(){}
};
template <class Object>
bool FileCacheManger<Object>::isObjectInCache(string problem) {
    bool objInDisk = false;
    if(!(this->diskSolution.find(problem) == this->diskSolution.end())){
        objInDisk = true;
    }
    return objInDisk;
}
template <class Object>
Object FileCacheManger<Object>::get(string problem) {
    Object objToReturn;
    fstream file_obj;
    string fileName;
    if(!(this->diskSolution.find(problem) == this->diskSolution.end())){
        //find in chache

        auto onePeaceInMap = this->diskSolution.find(problem);

        //read object from file
        file_obj.clear();
        fileName = "../" +  onePeaceInMap->second + ".txt";
        file_obj.open(fileName, ios::in | ios::binary);
        if (!file_obj) {
            throw "File failed in open";
        }
//        last  = chacheMap.find(keyList.front())->second.first;
        file_obj.seekp(0, ios::beg);
        file_obj.read((char *) &(objToReturn), sizeof(getObtToClone()));
        file_obj.close();
    } else {
        throw "Error - Object not in Disk";
    }

    return objToReturn;
}
template <class Object>
void FileCacheManger<Object>::insert(string problem, Object obj) {
    if(this->first){
        this->obtToClone =  obj;
        first = false;
    }
    //SEARCH IN CACHE
    if(!(this->diskSolution.find(problem) == this->diskSolution.end())){
        //FIND
        auto onePeaceInMap = this->diskSolution.find(problem);

        //return object from disk
        //TODO
        writeToFile(obj,onePeaceInMap->second);
    } else {
        string nameFile = problem + obj.class_name;
        this->diskSolution[problem] = nameFile;
//        this->diskSolution.insert(problem, a);
        writeToFile(obj,nameFile);

    }
}

template <class Object>
void FileCacheManger<Object>::writeToFile(const Object& obj, string name){
    string fileName = "../" + name +".txt";
//    string fileName = "../" + index + "EX4"+obj.class_name+".txt";
    fstream file_obj;
    file_obj.open(fileName, ios::out | ios::binary );
    if(!file_obj){
        throw "File failed in open";
    }
    file_obj.seekp(0, ios::beg);
    file_obj.write((char *)& (obj), sizeof(obj));
    file_obj.close();
}

template<class Object>
Object FileCacheManger<Object>::getObtToClone() const {
    return obtToClone;
}

template<class Object>
void FileCacheManger<Object>::setObtToClone(Object obtToClone) {
    FileCacheManger::obtToClone = obtToClone;
}

#endif //EX4_CACHEMANAGER_H
