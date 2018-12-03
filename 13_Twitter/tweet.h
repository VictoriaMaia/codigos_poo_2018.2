#pragma once
#include <iostream>
#include <vector> 
#include <sstream>
#include "crud.h"

using namespace std;

class Tweet{
    int id;
    string username;
    string msg;
    vector < string > likes; 

public:
    Tweet(int id=0, string username="", string msg=""){
        this->id = id;
        this->username = username;
        this->msg = msg;
    }

    void darLike(string nome){
        likes.push_back(nome);
    }

    string getId(){
        return to_string(id);
    }

    string toString(){
        stringstream ss;
        ss << "   " << id << " " << username << ":"  << msg << " ";
        if(likes.size() != 0){ //tem uma lista de pessoas que gostaram
           ss << "{";
           for (auto &l : likes){
               ss << " " << l;
           } 
           ss << " }";
        } 
        ss << endl;
        return ss.str();
    }

};
    


// # Tem como responsabilidade gerar um tweet com 
// # id unico, guardando o tweet gerado no repositorio
// # de tweets. 
class TweetGenerator{
    Repositorio < Tweet > *r_tw;
    int nextId{0};

public:
    TweetGenerator(Repositorio <Tweet> *r_tw){
        this->r_tw = r_tw;
    }

    Tweet* create(string name, string msg){
        r_tw->add(to_string(nextId), Tweet(nextId, name, msg));
        Tweet *novo = r_tw->get(to_string(nextId));
        nextId++;
        return novo;
    }
};
