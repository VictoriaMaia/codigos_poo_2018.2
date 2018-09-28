#ifndef CLIENTE
#define CLIENTE

#include <sstream>
#include <iostream>
using namespace std;

class Cliente{
private:
    string Id;
    string nome;
    bool alive{1};
    int devendo{0};

public:
    Cliente(string Id = "", string nome = ""){
        this->Id = Id;
        this->nome = nome;
    }

    string toString(){
        stringstream ss;
        ss << Id << " : " << nome << " : ";
        if(devendo < 0){
            ss << "\033[31m";
        }else{
            ss << "\033[34m";
        }
        ss << devendo << "\033[39m";
        return ss.str();
    }

    int getDevendo(){
        return devendo;
    }

    void setDevendo(int valor){
        this->devendo = valor;
    }

};

#endif