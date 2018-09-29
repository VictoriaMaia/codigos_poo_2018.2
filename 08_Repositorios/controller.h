#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <sstream>
#include "crud.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
using namespace std;

struct Controll{
    Repositorio < Aluno > alunos;
    Repositorio < Professor > professores;
    Repositorio < Disciplina > disciplinas;

    string funcoes(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        try{
            if(op == "help"){
                out << "  end;" << endl
                    << "  addAlu(matricula, curso, nome);" << endl
                    << "  addPro(nome, siape);" << endl
                    << "  addDis(código, nome);" << endl
                    << "  showAlu;" << endl
                    << "  showPro;" << endl
                    << "  showDis;" << endl
                    << "  getAlu(matricula);" << endl
                    << "  getPro(siape);" << endl
                    << "  getDis(codigo);" << endl
                    << "  rmAlu(matricula);" << endl
                    << "  rmPro(siape);" << endl
                    << "  rmDis(codigo);" << endl;
            }else if(op == "addAlu"){
                string matricula, curso, nome;
                in >> matricula >> curso;
                getline(in, nome);
                alunos.add(matricula, Aluno(matricula, curso, nome));
            }else if(op == "addPro"){
                string nome, siape;
                in >> siape;
                getline(in, nome);
                professores.add(siape, Professor(nome, siape));
            }else if(op == "addDis"){
                string codigo, nome;
                in >> codigo;
                getline(in, nome);
                disciplinas.add(codigo, Disciplina(codigo, nome));
            }else if(op == "showAlu"){
                out << alunos.show();
            }else if(op == "showPro"){
                out << professores.show();
            }else if(op == "showDis"){
                out << disciplinas.show();
            }else if(op == "getAlu"){
                string key;
                in >> key;
                out << alunos.get(key);
            }else if(op == "getPro"){
                string key;
                in >> key;
                out << professores.get(key);
            }else if(op == "getDis"){
                string key;
                in >> key;
                out << disciplinas.get(key);
            }else if(op == "rmAlu"){
                string key;
                in >> key;
                alunos.rm(key);
            }else if(op == "rmPro"){
                string key;
                in >> key;
                professores.rm(key);
            }else if(op == "rmDis"){
                string key;
                in >> key;
                disciplinas.rm(key);
            }
        }catch(string erro){
            cout << "\033[32m" << "   " << erro << "\033[39m" << endl;
        }
        
        return out.str();
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            if(line == "end"){
                break;
            }
            cout << "\033[35m" << line << "\033[39m" << endl;
            cout << funcoes(line) << endl;
            
        }
    }

};


#endif