#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "tweet.h"
using namespace std;

class User{
    string nome;
    int naoLidos{0};
    list < Tweet* > timeLine;
    list < Tweet > myTweets;
    vector < User* > seguidores;
    vector < User* > seguidos;
    

public:
    User(string nome = ""){
        this->nome = nome;
    }

    void seguir(User *other){
        other->seguidores.push_back(this);
        seguidos.push_back(other);
    }
    
    void twittar(Tweet *twit){
        myTweets.push_front(*twit);
        for(auto &sgres : seguidores){
            sgres->timeLine.push_front(twit);
            sgres->naoLidos++;            
        }
    }

    void darLike(string idTw){
        for(auto &twuits : timeLine){
            if(twuits->getId() == idTw){
                twuits->darLike(this->nome);
                return;
            }
        }
        throw "Tweet " + idTw + " não existe na sua timeline";
    }

    
    string getUnread(){
        if(naoLidos > 0){
            stringstream ss;
            for(auto twuits : timeLine){
                if(naoLidos > 0){
                    ss << twuits->toString();
                    naoLidos--;
                }
            }
            return ss.str();
        }
        return "\033[35m Nada de novo por aqui! \033[39m \n";
    }
    
    string getTimeLine(){
        naoLidos = 0;
        stringstream ss;
        for(auto twuits : timeLine){
            ss << twuits->toString();
        }
        return ss.str();
    }

    string getMyTweets(){
        stringstream ss;
        for(auto &twuits : myTweets){
            ss << twuits.toString();
        }
        return ss.str();
    }
    
    string toString(){
        stringstream ss;
        ss << " " << this->nome << endl;
        ss << "    seguidos   [";
        for(auto &s : this->seguidos){
            ss << " " << s->nome;
        }
        ss << " ]\n";
        ss << "    seguidores [";
        for(auto &sd : this->seguidores){
            ss << " " << sd->nome;
        }
        ss << " ]\n";
        return ss.str();
    }

};    