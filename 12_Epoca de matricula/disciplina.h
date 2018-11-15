#pragma once
#include <iostream>
#include <vector>
#include "aluno.h"
using namespace std;

class Disciplina{
    string idDisciplina;
    vector <Aluno *> vAlunos;

    void matricular(Aluno *aluno);
    void desmatricular(string idAluno);

public:
    Disciplina(string id = ""){
        this->idDisciplina = id;
    }

    string getNome();
    string toString();
    friend class Aluno;
    // friend std::ostream &operator<<(std::ostream &out, const Disciplinas &dis);
};