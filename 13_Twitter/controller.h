#pragma once
#include <iostream>
#include <sstream>
#include "crud.h"
#include "tweet.h"
#include "user.h"

using namespace std;

class Controller{
    Repositorio < User > rUsers;
    Repositorio < Tweet > rTwit;
    TweetGenerator g_twit;
public:
    Controller():rUsers("usuário"), rTwit("tweet"), g_twit(&rTwit){}
    
    void shell(string line){
        stringstream in(line);
        string op;
        in >> op;
        if(op == "help"){
            cout << "end \n" 
                 << "users \n"
                 << "addUser    _nome \n"
                 << "seguir     _nome _outro \n"
                 << "twittar    _nome _(mensagem com varias palavras) \n"
                 << "like       _nome \n"
                 << "timeline   _nome \n"
                 << "myTweets   _nome \n"
                 << "unread     _nome \n";
        }else if(op == "users"){
            cout << rUsers.toString(); 
        }else if(op == "addUser"){
            string nome;
            in >> nome;
            if(nome.empty()){
               cout << "\033[31m" << "Não posso adicionar um usuário sem nome" << "\033[39m"<< endl;
               return;
            }
            rUsers.add(nome, User(nome));
        }else if(op == "seguir"){
            string pessoa, seguido;
            in >> pessoa >> seguido;
            User *pes = rUsers.get(pessoa);
            pes->seguir(rUsers.get(seguido));
        }else if(op == "twittar"){
            string nome, msg;
            in >> nome;
            getline(in, msg);
            Tweet *gerado = g_twit.create(nome, msg);
            User *twuitou = rUsers.get(nome);
            twuitou->twittar(gerado);            
        }else if(op == "timeline"){
            string nome;
            in >> nome;
            User *pes = rUsers.get(nome);
            cout << pes->getTimeLine();
        }else if(op == "myTweets"){
            string nome;
            in >> nome;
            User *pes = rUsers.get(nome);
            cout << pes->getMyTweets();
        }else if(op == "unread"){
            string nome;
            in >> nome;
            User *pes = rUsers.get(nome);
            cout << pes->getUnread();
        }else if(op == "like"){
            string nome, idTwuit;
            in >> nome >> idTwuit;
            User *pes = rUsers.get(nome);
            pes->darLike(idTwuit);
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
                break;
            }
            try{
                shell(line);
            }catch(string e){
                cout << "\033[31m" << e << "\033[39m"<< endl;
            }catch(char const* e){
                cout << "\033[31m" << e << "\033[39m"<< endl;
            }
            
        }
    }
};
