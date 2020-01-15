//
// Created by magshimim on 15.1.2020.
//
#pragma once
#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

#include "FileCacheManager.h"
#include "CacheManager.h"
class FileCacheManger : public CacheManager<string>{
private:
    unordered_map<string, pair<string, list<string>::iterator>> _cacheMap;
    int _capacity;
    list<string> _lruKeys;
public:
    FileCacheManger(int capacity) : _capacity(capacity){}
    virtual string get(string);
    virtual void insert(string, string);
    void use(typename unordered_map<string, pair<string, list<string>::iterator>>::iterator& it);
    virtual ~FileCacheManger(){}
//    template <class Predicate>
//    void foreach(Predicate p);
};

#endif //EX4_FILECACHEMANAGER_H
