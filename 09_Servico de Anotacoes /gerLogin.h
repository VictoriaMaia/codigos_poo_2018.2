#ifndef GERLOGIN
#define GERLOGIN
#include <iostream>
#include "usuario.h"
#include "sistema.h"
using namespace std;

class GerLogin{
    Usuario *current;
    Sistema *sys;
public:
    GerLogin(Sistema *sys){
        this->sys = sys;
        this->current = nullptr;
    }

    Usuario &getCurrent(){
        if(current == nullptr){
            throw "fail: ninguem logado no sistema";
        }
        return *current;
    }

    void login(string login, string pass){
        if(current != nullptr){
            throw "fail: Já existe alguem logado";
        }
        Usuario &user = sys->getUser(login);
        if(!user.verificaPass(pass)){
            throw "fail: senha inválida";
        }
        current = &user;
    }

    void logout(){
        if(current == nullptr){
            throw "fail: ninguem logado no sistema";
        }
        current = nullptr;
    }
};


#endif