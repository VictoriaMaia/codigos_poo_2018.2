#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "crud.h"
#include "aluno.h"
#include "disciplina.h"

using namespace std;

class Controller{
    Repositorio <Aluno> rAlunos;
    Repositorio <Disciplina> rDisciplinas;

public:
    Controller():rAlunos("Aluno"), rDisciplinas("Disciplina"){}

    void shell(string line){
        stringstream in(line);
        string op;
        in >> op;
        if(op == "help"){
            cout << "end" << endl
                 << "newalu <nome>" << endl
                 << "newdis <nome>" << endl
                 << "show" << endl
                 << "mat <aluno disciplina1 disciplina2...>" << endl
                 << "rmmat <aluno disciplina1 disciplina2...>" << endl
                 << "rmalu <aluno>" << endl;
                 
        }else if(op == "newalu"){
            string nome;
            while (in >> nome){
                rAlunos.add(nome, Aluno(nome));
            }            
        }else if(op == "newdis"){
            string nome;
            while (in >> nome){
                rDisciplinas.add(nome, Disciplina(nome));
            }            
        }else if(op == "show"){
            cout << rAlunos.toString();
            cout << rDisciplinas.toString();            
        }else if(op == "mat"){
            string nome;
            in >> nome;
            Aluno *alu = rAlunos.get(nome);
            try{
                while(in >> nome){
                    Disciplina *dis = rDisciplinas.get(nome);
                    alu->matricular(dis);                  
                }
            }catch(string e){
                cout << "\033[31m" << e << "\033[39m"<< endl;
            }catch(char const* e){
                cout << "\033[31m" << e << "\033[39m"<< endl;
            }
        }else if(op == "rmmat"){
            string nome;
            in >> nome;
            Aluno *alu = rAlunos.get(nome);
            try{
                while(in >> nome){
                    Disciplina *dis = rDisciplinas.get(nome);
                    alu->desmatricular(dis->getNome());                  
                }
            }catch(string e){
                cout << "\033[31m" << e << "\033[39m"<< endl;
            }catch(char const* e){
                cout << "\033[31m" << e << "\033[39m"<< endl;
            }
        }else if(op == "rmalu"){
            string nome;
            in >> nome;
            Aluno *alu = rAlunos.get(nome);
            vector<Disciplina*> vetDisc = alu->getDisciplinas();
            for(auto &disc : vetDisc){
                alu->desmatricular(disc->getNome());
            }
            rAlunos.rm(nome);
        }else{
            cout << "comando inválido" << endl;
        }

    }
    
    void exec(){
        string line;
        while(true){
            getline(cin, line);
            cout << "\033[32m" << "$" << line << "\033[39m" << endl;
            if(line == "end"){
                break;
            }
            try{
                shell(line);
            }catch(string e){
                cout << "\033[31m" << e << "\033[39m"<< endl;
            }catch(char const* e){
                cout << "\033[31m" << e << "\033[39m"<< endl;
            }
            
        }
    }
};