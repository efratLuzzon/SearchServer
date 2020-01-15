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
#include <list>

using namespace std;


/*
 * Interface of CacheManger.
 * key - the problem
 * object - the solution
 * EACH OBJECT MUST HAVE CLASSNAME!!
 * */
template <class Object> class CacheManager {

public:
    virtual Object get(string) = 0;
    virtual void insert(string, Object) = 0;
    virtual ~CacheManager(){}
};

#endif //EX4_CACHEMANAGER_H
