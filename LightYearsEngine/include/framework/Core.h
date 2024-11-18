#pragma once

#include <iostream>
#include <stdio.h>
#include <memory>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace ly
{
template<typename T>
using unique = unique_ptr<T>;

template<typename T>
using shared = shared_ptr<T>;

template<typename T>
using weak = weak_ptr<T>;

template<typename T>
using List = vector<T>;

template<typename keyType, typename valType, typename Pr = less<keyType>>
using Map = map<keyType, valType, Pr>;

template<typename keyType, typename valType, typename hasher = hash<keyType>>
using Dictionary = unordered_map<keyType, valType, hasher>;

template<typename T>
using Set = unordered_set<T>;


// macro
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)

}

