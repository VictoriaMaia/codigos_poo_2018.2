#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Disciplina;

class Aluno{
    string idAluno;
    vector <Disciplina *> vDisciplinas;

public:
    Aluno(string id = ""){
        this -> idAluno = id;
    }

    void matricular(Disciplina *disciplina);
    void desmatricular(string idDisciplina);
    vector <Disciplina *> getDisciplinas();
    string getNome();
    string toString();
    // friend class Disciplina;
};