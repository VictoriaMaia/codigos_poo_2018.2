#ifndef CONTROLL
#define CONTROLL

#include <iostream>
#include <sstream>
#include "gerLogin.h"
#include "sistema.h"
using namespace std;

template <class T>
T read(stringstream &in){
    T t;
    in >> t;
    return t;
}


class Controll{
    Sistema sys;
    GerLogin gerlogin;
public:
    Controll():gerlogin(&sys){}
    
    void shell(string line){
        stringstream in(line);
        string op;
        in >> op;
        if(op == "help"){
            cout << "addUser <login, senha>" << endl
                 << "showUsers" << endl
                 << "login <login, senha>" << endl
                 << "logout" << endl
                 << "changePass <oldPass, newPass>" << endl
                 << "addNote <titulo, texto>" << endl
                 << "rmNote <titulo>" << endl
                 << "showNotes" << endl
                 << "end" << endl;
        }else if(op == "addUser"){
            string name, pass;
            name = read<string>(in);
            pass = read<string>(in);            
            sys.addUser(name, pass);
            cout << "sucesso" << endl;
        }else if(op == "showUsers"){
            cout << sys.showUser();
        }else if(op == "login"){
            string name, pass;
            name = read<string>(in);
            pass = read<string>(in);                        
            gerlogin.login(name, pass);
            cout << "sucesso" << endl;
        }else if(op == "logout"){
            gerlogin.logout();
            cout << "sucesso" << endl;
        }else if(op == "changePass"){
            string newpass, pass;
            newpass = read<string>(in);
            pass = read<string>(in);                                    
            gerlogin.getCurrent().changePass(pass, newpass);
            cout << "sucesso" << endl;
        }else if(op == "addNote"){
            string titulo, texto;
            titulo = read<string>(in);
            texto = read<string>(in);                                    
            gerlogin.getCurrent().addNote(titulo, texto);
            cout << "sucesso" << endl;
        }else if(op == "rmNote"){
            string titulo;
            titulo = read<string>(in);
            gerlogin.getCurrent().rmNote(titulo);
        }else if(op == "showNotes"){
            cout << gerlogin.getCurrent().toString();
        }else{
            cout << "Operação inválida" << endl;
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
            }catch(char const *e){
                cout << e << endl;
            }
        }
    }
};

#endif