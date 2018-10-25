#ifndef CONTROLL
#define CONTROLL
#include <iostream>
#include <sstream>
#include "crud.h"
#include "funcionario.h"
using namespace std;

class Controller{
    Repositorio <Funcionario*> rFuncionarios;
public:
    void shell(string line){
        stringstream in(line);
        string op;
        in >> op;
        if(op == "help"){
            cout << "end" << endl
                 << "addProf <nome, classe(A,B,C,D ou E)>" << endl                 
                 << "show <nome>" << endl
                 << "rm <nome>" << endl;
        }else if(op == "addProf"){
            string nome, classe;
            in >> nome >> classe;
            rFuncionarios.add(nome, new Professor(nome, classe));
        }else if(op == "show"){
            string nome;
            in >> nome;
            cout << rFuncionarios.show(nome) << endl;
        }else if(op == "rm"){
            string nome;
            in >> nome;
            rFuncionarios.rm(nome);
        }else{
            cout << "operação inválida" << endl;
        }
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            cout << "\033[32m" << "$" << line << "\033[39m" << endl;
            if(line == "end"){
                return;
            }
            try{
                shell(line);
            }catch(string e){
                cout << e << endl;
            }
        }
    }

};

#endif