#ifndef AGIOTA
#define AGIOTA

#include <iostream>
#include <sstream>
#include <vector>
#include "cliente.h"
#include "transition.h"
#include "crud.h"
using namespace std;

class Agiota{
private:
    int money;

public:
    Repositorio < Cliente > rcli;
    Repositorio < Transition > rtrans;
    
    //set money
    Agiota(int money = 0){
        this->money = money;
    }

    void addDevedor(string Id, string nome){
        rcli.add(Id, Cliente(Id, nome));        
    }

    string showDevedor(string id){
        int saldo;
        stringstream ss;
        for(auto &it : rtrans.coisas){
            auto tr = it.second;
            if(tr.getNome() == id){
                ss << "   " << tr.toString() << endl;                
            }            
        }
        
        auto i = rcli.get(id);
        saldo = i.getDevendo();

        ss << "   "  << "saldo: ";
        if(saldo < 0){
            ss << "\033[31m";
        }else{
            ss << "\033[34m";
        }
        ss << saldo << "\033[39m" << endl;

        return ss.str();
    }


    void addTran(string idNome, int value){
        static int indice = 0;
        Cliente &devedor = rcli.get(idNome);
        int valorDevendo = devedor.getDevendo();   
        if(value > 0 && value > -valorDevendo){ //depositando                
            throw "fail: valor maior que divida";                 
        }
        if(value < 0 && (money + value) < 0){ //emprestimo
            throw "fail: fundos insuficientes";
        }
        
        int totalAgiota, totalDevedor;
        totalAgiota = money + value;
        totalDevedor = valorDevendo + value;
        
        this->money = totalAgiota;
        devedor.setDevendo(totalDevedor);  
        rtrans.add(to_string(indice), Transition(idNome, value, indice));
        indice ++;
    }

    void matar(string id){
        rcli.rm(id);
        for(auto it : rtrans.coisas){
            if(it.second.getNome() == id){
                rtrans.rm(it.first);
            }
        }
    }
};

#endif 