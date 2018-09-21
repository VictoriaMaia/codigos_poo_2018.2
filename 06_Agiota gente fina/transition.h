#ifndef TRANSITION
#define TRANSITION

#include <iostream>
#include <sstream>

using namespace std;

class Transition{
private:
    string nome;
    int valor;
    int Id;

public:
    Transition(string nome = "", int valor = 0, int id = 0){
        this->nome = nome;
        this->valor = valor;
        this->Id = id;
    }

    string getNome(){
        return nome;
    }

    int getValor(){
        return valor;
    }

    string toString(){
        stringstream ss;
        ss << "id:" << Id << " [" << nome << " ";
        if(valor < 0){
            ss << "\033[31m";
        }else{
            ss << "\033[34m";
        }
        ss << valor << "\033[39m" << "]" ;
        return ss.str();
    }

};




#endif