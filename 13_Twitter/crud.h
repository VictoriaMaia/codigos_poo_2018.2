#pragma once
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

template < typename T >

class Repositorio{
    string tipo;
    map <string,T> coisas;

public:
    Repositorio(string tipo):tipo(tipo){}
    
    bool exist(string key){
        return coisas.find(key) != coisas.end();
    }

    void add(string key, T t){
        if(!exist(key)){
            coisas[key] = t;
        }    
        else{
            throw tipo + " já existe";
        }
    }

    T* get(string key){
        auto it = coisas.find(key);
        if(it != coisas.end()){
            return &it->second;      
        }
        throw tipo + " " + key + " não existe";
    }


    void rm(string key){
        if(exist(key)){
            coisas.erase(key);
        }
        throw tipo + " " + key + " não existe";
        
    }

    string toString(){
        stringstream out;
        // out << this->tipo << ":" << endl;
        for(auto par : coisas){
            out << par.second.toString();
        }
        out << endl;
        return out.str();
    }
};