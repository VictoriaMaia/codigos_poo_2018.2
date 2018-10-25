#ifndef FUNCIONARIO
#define FUNCIONARIO
#include <iostream>

using namespace std;

class Funcionario{
protected:
    string nome;
    string tipoFunc;
    int maxDiarias;
    float bonus;
public:
    Funcionario(string nome = "", string tipoFunc = "", int maxDiarias = 0, float bonus = 0.0){
        this -> nome = nome;
        this -> tipoFunc = tipoFunc;
        this -> maxDiarias = maxDiarias;
        this -> bonus = bonus;
    }
    virtual int calculoSalario(string letra) = 0;
    // virtual void setBonus() = 0;
    // virtual void addDiaria() = 0;
    virtual string getNome() = 0;
    virtual string toString() = 0;
    virtual ~Funcionario(){};
    
    //friend ostream& operator<<(ostream &os, Funcionario& func);
};

class Professor : public Funcionario{
    string letraClasse;
public:
    Professor(string nome = "", string letraClasse = ""): 
    Funcionario(nome, "Prof", 2){
        this->letraClasse = letraClasse;
    }

    int calculoSalario(string letra){
        if(letra == "A"){
            return 3000;
        }else if(letra == "B"){
            return 5000;
        }else if(letra == "C"){
            return 7000;            
        }else if(letra == "D"){
            return 9000;
        }else if(letra == "E"){
            return 11000;
        }
        return 0;
    }

    string getNome(){
        return this->nome;
    }


    string toString(){
        return tipoFunc + " " + nome + " classe " + letraClasse + "\nsalário " + to_string(calculoSalario(letraClasse));
    }    
};

// ostream& operator<<(ostream &os, Funcionario& func){
//     os << func.tipoFunc << " " << func.nome;
//     return os;
//}

#endif