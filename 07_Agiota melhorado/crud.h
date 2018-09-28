#ifndef CRUD
#define CRUD

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

template < typename T >
struct Repositorio{
    map <string, T> coisas;

    bool exists(string key){
        return coisas.find(key) != coisas.end();
    }

    void add(string key, T elem){
        if(!exists(key)){
            coisas[key] = elem;
        }
        else{
            throw "fail: Id ja existe";
        }
    }

    T& get(string key){
        auto it = coisas.find(key);
        if(it != coisas.end())
            return it->second;
        else
            throw "fail: ID nao existe";
    }

    string showAll(){
        stringstream ss;
        for(auto it : coisas){
            ss << "   " <<  it.second.toString() << endl;
        }
        return ss.str();
    }

    void rm(string key){
        if(!exists(key))
            throw "fail: chave nao existe";
        coisas.erase(key);
    }


};




#endif