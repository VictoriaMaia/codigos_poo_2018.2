#ifndef PROFESSOR
#define PROFESSOR

#include <iostream>
#include "crud.h"

using namespace std;

class Professor{
private:
    string nome;
    string siape;
public:
    Professor(string nome = "", string siape = ""){
        this->nome = nome;
        this->siape = siape;
    }

    string toString(){
        return siape + ":" + nome;
    }

};

#endif