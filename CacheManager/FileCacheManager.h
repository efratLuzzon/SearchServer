//
// Created by magshimim on 15.1.2020.
//
#pragma once
#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

#include "FileCacheManager.h"
#include "CacheManager.h"
#include <unordered_set>
class FileCacheManger : public CacheManager<string>{
private:
    unordered_set<string> numProblem;
public:
    FileCacheManger(){}
    virtual string get(string);
    virtual void insert(string, string);
    virtual bool isExsist(string);
    virtual ~FileCacheManger(){}
};

#endif //EX4_FILECACHEMANAGER_H
