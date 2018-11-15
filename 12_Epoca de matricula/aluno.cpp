#include <iostream>
#include <vector>
#include <sstream>
#include "aluno.h"
#include "disciplina.h"

using namespace std;

void Aluno::matricular(Disciplina * disciplina){
    for(auto *dis : this->vDisciplinas){
        if(dis->getNome() == disciplina->getNome()){
            throw "Disciplina ja cadastrada";
        }
    }
    vDisciplinas.push_back(disciplina);
    disciplina->matricular(this);
}

void Aluno::desmatricular(string idDisciplina){
    for(size_t i = 0; i < this->vDisciplinas.size(); i++){
			if(vDisciplinas[i]->getNome() == idDisciplina){
				vDisciplinas[i]->desmatricular(this->getNome());
                vDisciplinas.erase(vDisciplinas.begin()+i);                
				return;
			}
	}
    throw "O aluno " + this->getNome() + " não esta matriculado na disciplina " + idDisciplina;

}

vector <Disciplina *> Aluno::getDisciplinas(){
    return this->vDisciplinas;
}

string Aluno::getNome(){
    return this->idAluno;
}
string Aluno::toString(){
    stringstream out;
    out << this->idAluno << " [ ";
    for(auto &i : this->vDisciplinas){
        out << i->getNome() << " ";
    }
    out << "]" << endl;
    return out.str();
}
