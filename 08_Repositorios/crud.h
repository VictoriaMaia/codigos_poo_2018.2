#ifndef CRUD
#define CRUD

#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

template < typename T >

struct Repositorio{
    map <string, T> coisas;

    bool exist(string key){
        return coisas.find(key) != coisas.end();
    }

    void add(string key, T element){
        if(!exist(key)){
            coisas[key] = element;
        }
        else{
            throw "fail: " + key + " ja existe";
        }
    }

    void rm(string key){
        if(!exist(key)){
            throw "fail: " + key + " não existe";
        }
        coisas.erase(key);        
    }

    string get(string key){
        auto it = coisas.find(key);
        if(it != coisas.end()){
            return "   " + it->second.toString() + "\n";
        }
        else{
            throw "fail: " + key + " não existe";
        }
    }

    string show(){
        stringstream ss;
        for(auto par : coisas){
            ss << "   " << par.second.toString() << endl;
        }
        return ss.str();
    }
};


#endif