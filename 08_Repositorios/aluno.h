#ifndef ALUNO
#define ALUNO

#include <iostream>
using namespace std;

class Aluno{
private:
    string matricula;
    string curso;
    string nome;
public:
    Aluno(string matricula = "", string curso = "", string nome = ""){
        this->matricula = matricula;
        this->curso = curso;
        this->nome = nome;
    }

    string toString(){
        //(0021:RC:bia barbosa)
        return matricula + ":" + curso + ":" + nome;
    }

};

#endif