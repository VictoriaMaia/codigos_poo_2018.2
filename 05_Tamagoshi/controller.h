#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "pet.h"
#include "game.h"
#include "images.h"
using namespace std;

struct Controll{
    Game tamagotchi;

    string funcoes(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        if(op == "help"){
            out << "  end;" << endl
                << "  init(name, energy, hungry, clean);" << endl
                << "  show;" << endl
                << "  play;" << endl
                << "  eat;" << endl
                << "  sleep;" << endl
                << "  clean;" << endl;
        }else if(op == "init"){
            string name;
            int energy,hungry,clean;
            in >> name >> energy >> hungry >> clean;
            out << tamagotchi.init(name, energy, hungry, clean);
        }else if(op == "show"){
            out << tamagotchi.show();
        }else if(op == "play"){
            int resul = tamagotchi.play();
            if(resul == -1){
                out << printPlay();
            }else if(resul == E){
                out << "fail: pet morreu de fraqueza" << endl;
                out << printDied();
            }else if(resul == H){
                out << "fail: pet morreu de fome" << endl;
                out << printDied();
            }else if(resul == C){
                out << "fail: pet morreu de sujo" << endl;
                out << printDied();
            }else{
                out << "fail: pet esta morto" << endl;
                out << printDied();
            }
        }else if(op == "eat"){
            if(tamagotchi.eat()){
                out << printEat();
            }
            else{
                out << "fail: pet esta morto" << endl;
                out << printDied();
            }
        }else if(op == "sleep"){
            int result = tamagotchi.sleep();
            if(result == 1){
                out << printSleep();
            }
            else if(result == 0) {
                out << "fail: nao esta com sono" << endl;
                out << printShowDeBoas();
            }
            else{
                out << "fail: pet esta morto" << endl;
                out << printDied();
            }
        }else if(op == "clean"){
            if(tamagotchi.clean()){
                out << printClean();
            }
            else{
                out << "fail: pet esta morto" << endl;
                out << printDied();
            }
        }

        return out.str();
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            if(line == "end"){
                break;
            }
            system("clear");
            cout << line << endl;
            cout << funcoes(line) << endl;
            
        }
    }

};


#endif