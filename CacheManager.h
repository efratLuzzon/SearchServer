//
// Created by magshimim on 8.1.2020.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H
/*
 * Interface of CacheManger
 * */
template <class Key, class Object> class CacheManager {
public:
    virtual bool isObjectInCache() = 0;
    virtual Object get(Key) = 0;
    virtual void insert(Key, Object) = 0;
    virtual ~CacheManager();
};
#endif //EX4_CACHEMANAGER_H
