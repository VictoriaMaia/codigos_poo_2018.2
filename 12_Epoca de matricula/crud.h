#pragma once
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

template < typename T >

class Repositorio{    
    string tipo;
    map <string, T> coisas;

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
            throw tipo + " ja cadastrado";
        }
    }

    T* get(string key){
        auto it = coisas.find(key);
        if(it != coisas.end()){
            return &it->second;      
        }
        throw tipo + " " + key + " não cadastrado";
    }


    void rm(string key){
        coisas.erase(key);
    }


    string toString(){
        // unsigned int tamanho = coisas.size();
        stringstream out;
        out << this->tipo << ":" << endl;
        for(auto par : coisas){
            out << par.second.toString();
        }
        out << endl;
        return out.str();
    }

};
