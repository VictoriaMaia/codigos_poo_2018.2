#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <sstream>
#include "agiota.h"
using namespace std;

struct Controll{
    Agiota GenteFina;

    string funcoes(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        try{
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
                    GenteFina.addDevedor(id, nome);                                
                }
                else if(op == "tr"){
                    string id;
                    int value;
                    in >> id >> value;
                    GenteFina.addTran(id, value); 
                }                                   
            }else if(op == "show"){
                in >> op;
                if(op == "all")
                    out << GenteFina.rcli.showAll();
                else if(op == "tr"){
                    out << GenteFina.rtrans.showAll();
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
        }catch(const char* erro){
            cout << "   "<< "\033[32m" << erro << "\033[39m" << endl;
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