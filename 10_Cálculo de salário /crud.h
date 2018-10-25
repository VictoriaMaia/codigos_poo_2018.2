#ifndef CRUD
#define CRUD
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

template < typename T >

class Repositorio{
    map <string, T> coisas;
public:     
    bool exist(string key){
        return coisas.find(key) != coisas.end(); //ture = achou alguem 
    }
    
    void add(string key, T newElement){
        if(!exist(key)){
            coisas[key] = newElement;
        }
        else{
            throw "fail: funcionário " + newElement->getNome() + " ja existe"; 
        }
        
    }

    string show(string key){         
        return coisas.find(key)->second->toString();
    }

    void rm(string key){
        if(!exist(key)){
            throw "fail: funcionario " + key + "não existe";
        }        
        
        delete coisas.find(key)->second;
        coisas.erase(key);           
    }
    // get    
};

#endif