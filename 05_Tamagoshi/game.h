#ifndef GAME
#define GAME

#include <iostream>
#include "images.h"
#include "pet.h"
using namespace std;

class Game{
private:
    Pet dinoKun;
public:
    string init(string nome, int ener, int hung, int cl){
        stringstream ss;
        dinoKun = Pet(nome, ener, hung, cl);
        ss << printInit();
        return ss.str();
    }

    string show(){
        stringstream shw;
        shw << "\033[35m" << dinoKun.toString() << "\033[30m";
        if(dinoKun.getAlive()){
            if(dinoKun.getInformations(E) <= 3 && dinoKun.getInformations(H) <= 2 && dinoKun.getInformations(C) <= 4){
                shw << printShowSujoFaminto(); //sujo faminto cansado
            }
            else if(dinoKun.getInformations(E) > 3 && dinoKun.getInformations(H) <= 2 && dinoKun.getInformations(C) > 4){
                shw << printShowFaminto(); //faminto
            }
            else if(dinoKun.getInformations(E) > 3 && dinoKun.getInformations(H) > 2 && dinoKun.getInformations(C) <= 4){
                shw << printShowSujo(); //sujo
            }
            else if(dinoKun.getInformations(E) > 3 && dinoKun.getInformations(H) <= 2 && dinoKun.getInformations(C) <= 4){
                shw << printShowSujoFaminto(); //faminto sujo
            }
            else if(dinoKun.getInformations(E) <= 3 && dinoKun.getInformations(H) > 2 && dinoKun.getInformations(C) > 4){
                shw << printShowCansado(); //cansado
            }
            else if(dinoKun.getInformations(E) <= 3 && dinoKun.getInformations(H) <= 2 && dinoKun.getInformations(C) > 4){
                shw << printShowFaminto(); //cansado faminto
            }
            else if(dinoKun.getInformations(E) <= 3 && dinoKun.getInformations(H) > 2 && dinoKun.getInformations(C) <= 4){
                shw << printShowSujo(); //cansado sujo
            }
            else {
                shw << printShowDeBoas(); //de boas
            }
        }
        else{
            shw << printDied();
        }
        return shw.str();
    }

    bool play(){
        if(dinoKun.getAlive()){
            dinoKun.setInformations(-2, E);
            dinoKun.setInformations(-1, H);
            dinoKun.setInformations(-3, C);
            dinoKun.setInformations(1, A);
            dinoKun.setInformations(1, D);
            return true;
        }
        return false;
    }

    bool eat(){
        if(dinoKun.getAlive()){
            dinoKun.setInformations(-1, E);
            dinoKun.setInformations(4, H);
            dinoKun.setInformations(-2, C);
            dinoKun.setInformations(1, A);
            return true;
        }
        return false;
    }

    int sleep(){
        if(dinoKun.getAlive()){
            if(dinoKun.getInformations(E) <= (dinoKun.getInformations(EMax) - 5)){
                dinoKun.setInformations(-1, H);
                int diferenca;
                diferenca = dinoKun.getInformations(EMax) - dinoKun.getInformations(E);
                dinoKun.setInformations(diferenca, E);
                dinoKun.setInformations(diferenca, A);
                return 1;
            }
            else{
                return 0;
            }    
            
        }
        return -1;
    }


    bool clean(){
        if(dinoKun.getAlive()){
            dinoKun.setInformations(-1, H);
            dinoKun.setInformations(-3, E);
            dinoKun.setInformations(2, A);
            int limpezaTotal = dinoKun.getInformations(CMax);
            dinoKun.setInformations(limpezaTotal, C);
            return true;
        }
        return false;
    }





};

#endif