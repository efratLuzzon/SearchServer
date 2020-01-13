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

template <class Solution>
class FileCacheManger : public CacheManager<Solution>{
private:
    unordered_map<string, pair<Solution, list<string>::iterator>> _cacheMap;
    int _capacity;
    list<string> _lruKeys;



public:
    FileCacheManger(int capacity) : _capacity(capacity){}
    virtual Solution get(string);
    virtual void insert(string, Solution);
    void use(typename unordered_map<string, pair<Solution, list<string>::iterator>>::iterator& it);
    virtual ~FileCacheManger(){}
    template <class Predicate>
    void foreach(Predicate p);
    };

template <class Solution>
Solution FileCacheManger<Solution>::get(string key) {
    auto item = _cacheMap.find(key);
    //if item is in cache
    if(item != _cacheMap.end()) {
        use(item);
        return item->second.first;
    }
    fstream data;
    data.open(key,ios::in|ios::binary);
    if(!data.is_open()){
        throw "key doesn't exist in map";
    }
    Solution obj;
    data.read((char*)&obj,sizeof(obj));
    data.close();
    insert(key, obj);
    return obj;
}

template <class Solution>
void FileCacheManger<Solution>::insert(string key, Solution obj) {
    fstream data;
    auto item = _cacheMap.find(key);
    //if key is exist
    if(item != _cacheMap.end()){
        use(item);
        item->second.first = obj;
    } else {
        if((int)_cacheMap.size() == _capacity) {
            _cacheMap.erase(_lruKeys.back());
            _lruKeys.pop_back();
        }
        _lruKeys.push_front(key);
        _cacheMap[key] = {obj, _lruKeys.begin()};
    }
    data.open(key,ios::out|ios::binary);
    if(!data.is_open()){
        throw "open file error";
    }
    data.write((char*)&obj,sizeof(obj));
    data.close();
}

template <class Solution>
void FileCacheManger<Solution>::use(typename unordered_map<string, pair<Solution, list<string>::iterator>>::iterator& it) {
    _lruKeys.erase(it->second.second);
    _lruKeys.push_front(it->first);
    it->second.second = _lruKeys.begin();
}


template <class Solution>
template <class Predicate>
void FileCacheManger<Solution>::foreach(Predicate p) {
    for(string key: _lruKeys) {
        p(_cacheMap[key].first);
    }
}
#endif //EX4_CACHEMANAGER_H
