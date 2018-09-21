#ifndef AGIOTA
#define AGIOTA

#include <iostream>
#include <sstream>
#include <vector>
#include "cliente.h"
#include "transition.h"
using namespace std;

enum fails {nExiste = -1, deucerto=0, Existe=1, nMoney, morDivida};

class Agiota{
private:
    int money;
    vector < Cliente > devedores;
    vector < Transition > transferencia;
public:
    Agiota(int money = 0){
        this->money = money;
    }

    int DevedorExist(string id){
        for(int i = 0; i < (int)devedores.size(); i++){
            if(devedores[i].getId() == id){
                return i;
            }
        }
        return nExiste;
    }

    bool addDevedor(string Id, string nome){
        if(DevedorExist(Id) == nExiste){
            devedores.push_back(Cliente(Id, nome));
            return true;
        }
        return false;
    }


    int addTran(string idNome, int value){
        int devedor = DevedorExist(idNome);
        int valorDevendo = devedores[devedor].getDevendo();
        if(devedor != nExiste){
            if(value > 0 && value > -valorDevendo){ //depositando                
                return morDivida;                 
            }
            if(value < 0 && (money + value) < 0){
                return nMoney;
            }

            int totalAgiota, totalDevedor;
            int idtr = transferencia.size();
            totalAgiota = money + value;
            totalDevedor = valorDevendo + value;

            this->money = totalAgiota;
            devedores[devedor].setDevendo(totalDevedor);    

            transferencia.push_back(Transition(idNome, value, idtr));
            return deucerto;
        }    
        return nExiste;
    }

    string showDevedor(string id){
        int saldo = 0;
        stringstream ss;
        for(auto &i : transferencia){
            if(i.getNome() == id){
                ss << i.toString() << endl;
                saldo = saldo + i.getValor();
            }            
        }
        ss << "saldo: ";
        if(saldo < 0){
            ss << "\033[31m";
        }else{
            ss << "\033[34m";
        }
        ss << saldo << "\033[39m";

        return ss.str();
    }

    string showTr(){
        stringstream ss;
        for(auto &i : transferencia){
            ss << i.toString() << endl;
        }
        return ss.str();
    }

    string showAll(){
        stringstream ss;
        for(auto& i : devedores){
            ss << i.toString() << endl;
        }
        return ss.str();
    }

    void matar(string id){
        for(int i = 0; i < (int)devedores.size(); i++){
            if(devedores[i].getId() == id){
                devedores.erase(devedores.begin() + i);
            }
        }

        for(int i = 0; i < (int)transferencia.size(); i++){
            if(transferencia[i].getNome() == id){
                transferencia.erase(transferencia.begin() + i);
            }
        }
    }

};




#endif 