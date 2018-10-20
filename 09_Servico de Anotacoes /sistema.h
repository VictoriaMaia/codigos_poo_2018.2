#ifndef SISTEMA
#define SISTEMA
#include <iostream>
#include <vector>
#include <sstream>
#include "usuario.h"
using namespace std;

class Sistema{
    vector <Usuario> usuarios;
public:
    void addUser(string login, string pass){
        for(auto user : usuarios){
            if(user.getLogin() == login){
                throw "fail: Usuário já existe";
            }
        }
        usuarios.push_back(Usuario(login, pass));
    }

    Usuario &getUser(string login){
        for(auto &user : usuarios){
            if(user.getLogin() == login){
                return user;                
            }
        }
        throw "fail: id não existe";
    }

    string showUser(){
        stringstream ss;
        ss << "Usuários:" << endl;
        ss << "[";
        for(auto user : usuarios){
            ss << user.getLogin() << " : ";
        }
        ss << "]" << endl;
        return ss.str();
    }
};

#endif