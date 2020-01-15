//
// Created by magshimim on 15.1.2020.
//

#include "FileCacheManager.h"


string FileCacheManger::get(string key) {
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
    string obj;
    data.read((char*)&obj,sizeof(obj));
    data.close();
    insert(key, obj);
    return obj;
}


void FileCacheManger::insert(string key, string obj) {
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


void FileCacheManger::use(typename unordered_map<string, pair<string, list<string>::iterator>>::iterator& it) {
    _lruKeys.erase(it->second.second);
    _lruKeys.push_front(it->first);
    it->second.second = _lruKeys.begin();
}



//template <class Predicate>
//void FileCacheManger<Solution>::foreach(Predicate p) {
//    for(string key: _lruKeys) {
//        p(_cacheMap[key].first);
//    }
//}
