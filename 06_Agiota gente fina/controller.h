#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <sstream>
#include "agiota.h"
using namespace std;

struct Controll{
    Agiota GenteFina;

    string erros(int e, string Id = ""){
        stringstream ss;
        ss << "    ";
        switch (e){
            case Existe:
                ss << "fail: cliente " + Id + " ja existe";
                break;
            case nExiste:
                ss << "fail: cliente " + Id + " nao existe";
                break;
            case nMoney:
                ss << "fail: fundos insuficientes";
                break;
            case morDivida:
                ss << "fail: valor maior que divida";
                break;
        }
        return ss.str();
    }



    string funcoes(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        if(op == "help"){
            out << "  end;" << endl
                << "  init(money);" << endl
                << "  add cli(id, nome);" << endl
                << "  add tr(id, valor);" << endl
                << "  show all;" << endl
                << "  show tr;" << endl
                << "  show(id);" << endl
                << "  matar(id);" << endl;
        }else if(op == "init"){
            int dindin;
            in >> dindin;
            GenteFina = Agiota(dindin);
            
        }else if(op == "add"){
            in >> op;
            if(op == "cli"){
                string id, nome;
                in >> id;
                getline(in, nome);
                if(!GenteFina.addDevedor(id, nome)){
                    out << erros(Existe, id);
                }
            }
            else if(op == "tr"){
                string id;
                int value, resp;
                in >> id >> value;
                resp = GenteFina.addTran(id, value);
                if(resp != 0){
                    out << erros(resp, id);
                }
            }
         }else if(op == "show"){
            in >> op;
            if(op == "all")
                out << GenteFina.showAll();
            else if(op == "tr"){
                out << GenteFina.showTr();
            }else{
                string id;
                id = op;
                out << GenteFina.showDevedor(id);
            }
        }else if(op == "matar"){
            string id;
            in >> id;
            GenteFina.matar(id);
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
            cout << line << endl;
            cout << funcoes(line) << endl;
            
        }
    }

};


#endif