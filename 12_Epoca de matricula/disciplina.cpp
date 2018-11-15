#include <iostream>
#include <sstream>
#include "disciplina.h"
#include "aluno.h"

using namespace std;

void Disciplina::matricular(Aluno *aluno){
    for(auto *al : this->vAlunos){
        if(al->getNome() == aluno->getNome()){
            throw "Aluno ja cadastrado nessa disciplina";
        }
    }
    this->vAlunos.push_back(aluno);
}

void Disciplina::desmatricular(string idAluno){
    for(size_t i = 0; i < this->vAlunos.size(); i++){
        if(vAlunos[i]->getNome() == idAluno){
            vAlunos.erase(vAlunos.begin()+i);
        }
    }
}

string Disciplina::getNome(){
    return this->idDisciplina;
}
string Disciplina::toString(){
    stringstream out;
    out << this->idDisciplina << " [ ";
    for(auto &i : this->vAlunos){
        out << i->getNome() << " ";
    }
    out << "]" << endl;
    return out.str();
}
    