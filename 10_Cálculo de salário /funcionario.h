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
    virtual int calculoSalario() = 0;
    // virtual void setBonus() = 0;
    virtual void addDiaria() = 0;
    virtual string getNome() = 0;
    virtual string toString() = 0;
    virtual ~Funcionario(){};
    
    //friend ostream& operator<<(ostream &os, Funcionario& func);
};

class Professor : public Funcionario{
    string letraClasse;
    int diarias;
public:
    Professor(string nome = "", string letraClasse = ""): 
    Funcionario(nome, "Prof", 2){
        this->letraClasse = letraClasse;
        this->diarias = 0;
    }

    int calculoSalario(){
        int salario;
        if(letraClasse == "A"){
            salario = 3000;
        }else if(letraClasse == "B" ){
            salario = 5000;
        }else if(letraClasse == "C" ){
            salario = 7000;            
        }else if(letraClasse == "D" ){
            salario = 9000;
        }else if(letraClasse == "E" ){
            salario = 11000;
        }
        return salario + 100*this->diarias;
    }

    void addDiaria(){
        if(diarias > maxDiarias){
            throw "Maximo diarias ja atingido!";
        }
        maxDiarias = maxDiarias - 1;
        diarias = diarias + 1;
    }

    string getNome(){
        return this->nome;
    }

    string toString(){
        return tipoFunc + " " + nome + " classe " + letraClasse + "\nsalário " + to_string(calculoSalario());
    }    
};

// ostream& operator<<(ostream &os, Funcionario& func){
//     os << func.tipoFunc << " " << func.nome;
//     return os;
//}

class Servidor : public Funcionario{
    int nivel;
    int diarias{0};
public:
    Servidor(string nome = "", int nivel = 0):
    Funcionario(nome, "Servidor", 1){
        this->nivel = nivel;
    }

    int calculoSalario(){
        return 3000 + 300*nivel + 100*diarias;
    }
    
    void addDiaria(){
        if(diarias > maxDiarias){
            throw "Máximo diarias ja atingido!";
        }
        maxDiarias = maxDiarias - 1;
        diarias = diarias + 1;
    }
    
    string getNome(){
        return this->nome;
    }
    
    string toString(){
        return tipoFunc + " " + nome + " nível " + to_string(nivel)  + "\nsalário " + to_string(calculoSalario());
    }
    
};

class Tecnico : public Funcionario{
    int horas;
    bool insalubre;
public:
    Tecnico(string nome, int horas, string insalubre):
    Funcionario(nome, "tecnico", 0){
        this->horas = horas;
        if(insalubre == "sim"){
            this->insalubre = true;
        }else{
            this->insalubre = false;
        }
        
    }

    int calculoSalario(){
        float salario;
        salario = 4 * this->horas;
        if(insalubre){
            salario += 500;
        }
        return salario;
    }

    void addDiaria(){
        throw "Técnico não recebe diária";
    }

    string getNome(){
        return this->nome;
    }

    string toString(){
        return tipoFunc + " " + nome + " " + to_string(horas)+"h " + (insalubre == true ? "insalubre": "salubre") + "\nsalário " + to_string(calculoSalario());
    }
    
};



#endif