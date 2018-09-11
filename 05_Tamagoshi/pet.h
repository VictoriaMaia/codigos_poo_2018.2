#ifndef PET
#define PET

#include <iostream>
#include <sstream>
using namespace std;

enum gets {E, EMax, H, HMax, C, CMax, A, D};

class Pet{
private:
    string name;
    int energyMax, hungryMax, cleanMax;
    int energy, hungry, clean;
    int diamonds {0};
    int age {0};
    bool alive {true};

public:
    Pet(string name = "", int energyMax = 0, int hungryMax = 0, int cleanMax = 0){
        this->name = name;
        this->energyMax = energyMax;
        this->hungryMax = hungryMax;
        this->cleanMax = cleanMax;
        this->energy = energyMax;
        this->hungry = hungryMax;
        this->clean = cleanMax;
    }

    string getName(){
        return name;
    }

    int getInformations(int option){
        int result;
        switch (option){
            case E: 
                result = this->energy;
                break;
            case EMax: 
                result = this->energyMax;
                break;
            case H:
                result = this->hungry;
                break;
            case HMax:
                result = this->hungryMax;
                break;
            case C:
                result = this->clean;
                break;
            case CMax:
                result = this->cleanMax;
                break;
            case A:
                result = this->age;
                break;
            case D:
                result = this->diamonds;
                break;

        }
        return result;
    }

    bool getAlive(){
        return alive;
    }

    string toString(){
        stringstream ss;
        ss << "N:" << name << ", "
           << "E:" << energy << "/" << energyMax << ", "
           << "H:" << hungry << "/" << hungryMax << ", "
           << "C:" << clean << "/"  << cleanMax  << ", "
           << "D:" << diamonds << ", "
           << "A:" << age << endl;
        return ss.str();
    }

    void setAlive(bool valorMudanca){
        alive = valorMudanca;
    }

    void setInformations(int valor, int mudar){
        switch (mudar){
            case E:
                if((energy + valor) <= 0){
                    energy = 0;
                    this->alive = false;
                }else if((energy + valor) > energyMax){
                    this->energy = energyMax;
                }else{
                    this->energy = energy + valor;
                }
                break;
            
            case H:
                if((hungry + valor) <= 0){
                    hungry = 0;
                    this->alive = false;
                }else if((hungry + valor) > hungryMax){
                    this->hungry = hungryMax;
                }else{
                    this->hungry = hungry + valor;
                }
                break;

            case C:
                if((clean + valor) <= 0){
                    clean = 0;
                    this->alive = false;
                }else if((clean + valor) > cleanMax){
                    this->clean = cleanMax;
                }else{
                    this->clean = clean + valor;
                }
                break;
            
            case D:
                diamonds = diamonds + valor;
                break;

            case A:
                age = age + valor;
                break;
        }
    }
};

#endif