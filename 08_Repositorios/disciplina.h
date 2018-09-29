#ifndef DISCIPLINA
#define DISCIPLINA

#include <iostream>
using namespace std;

class Disciplina{
private:
    string codigo;
    string nome;
public:
    Disciplina(string codigo = "", string nome = ""){
        this->codigo = codigo;
        this->nome = nome;
    }

    string toString(){
        return codigo + ":" + nome;
    }
};




#endif