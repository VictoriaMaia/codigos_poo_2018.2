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
                 << "addSta <nome, nivel>" << endl 
                 << "addTer <nome, horasTrabalhadas, insalubre?[s/n]>" << endl              
                 << "show <nome>" << endl
                 << "rm <nome>" << endl
                 << "addDiaria <nome>" << endl;
        }else if(op == "addProf"){
            string nome, classe;
            in >> nome >> classe;
            rFuncionarios.add(nome, new Professor(nome, classe));
        }else if(op == "addSta"){
            string nome;
            int nivel;
            in >> nome >> nivel;
            rFuncionarios.add(nome, new Servidor(nome, nivel));
        }else if(op == "addTer"){
            string nome, insalubre;
            int horas;
            in >> nome >> horas >> insalubre;
            rFuncionarios.add(nome, new Tecnico(nome, horas, insalubre));
        }else if(op == "show"){
            string nome;
            in >> nome;
            cout << rFuncionarios.show(nome) << endl;
        }else if(op == "rm"){
            string nome;
            in >> nome;
            rFuncionarios.rm(nome);
        }else if(op == "addDiaria"){
            string nome;
            in >> nome;
            rFuncionarios.diaria(nome);
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
            }catch(char const* e){
                cout << e << endl;
            }
        }
    }

};

#endif