#ifndef USUARIO
#define USUARIO

#include <iostream>
#include <vector>
#include <sstream>
#include "nota.h"

using namespace std;

class Usuario{
    string login;
    string pass;
    vector <Nota> anotacoes;
public:
    Usuario(string login = "", string pass = ""): login(login), pass(pass){}

    string getLogin(){
        return login;
    }

    void addNote(string titulo, string texto){
        for(auto &n : anotacoes){
            if(n.getTitulo() == titulo)
                throw "fail: ja existe anotação com este título";
        }
        anotacoes.push_back(Nota(titulo, texto));
    }

    void rmNote(string titulo){
        for(auto it = anotacoes.begin(); it != anotacoes.end(); it++){
            if(it->getTitulo() == titulo){
                anotacoes.erase(it);
                return;
            }
        }
        throw "fail: não existe anotação com esse título";        
    }
    
    bool verificaPass(string pass){
        return pass == this->pass;
    }

    void changePass(string oldPass, string newPass){
        if(verificaPass(oldPass)){
            this->pass = newPass;
            return;
        }
        throw "Fail: senha errada";
    }


    string toString(){
        stringstream ss;
        ss << login << endl;
        for(auto &nota : anotacoes){
            ss << nota.toString() << endl;
        }
        return ss.str();
    }    
};

#endif