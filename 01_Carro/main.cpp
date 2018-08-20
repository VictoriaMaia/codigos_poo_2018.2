#include <iostream>
using namespace std;

struct car{
    float gas;
    float gasMax;
    int pass;
    int passMax;
    float Km;

    bool in(){ //embarcar  
        if(pass < passMax){
            pass++;     
            cout << "Done \n";       
            return true;
        }

        cout << "Carro lotado!! \n";
        return false;
        
    }

    bool out(){ //desembarcar
        if(pass != 0){
            pass --;
            cout << "Done \n";
            return true;
        }
        
        cout << "Carro vazio! \n";
        return false;
    }

    void fuel(float value){ //abastecer
        if(value > gasMax){
            gas = gasMax;                        
        }
        else{
            gas = value;
        }

        cout << "Done\n";
    }
    
    void drive(float distance){ //dirigir
        if(this->pass != 0){
            float gas_viagem, gas_restante;
            gas_viagem = distance/10;
            gas_restante = this->gas - gas_viagem;
            if(gas_restante >= 0){
                this->gas = gas_restante;
                Km += distance;
                cout << "Done\n";
            }
            else{
                cout << "Não tens gasosa para a viagem! \n";
            }
        }
        else{
            cout << "Não tem ninguem no carro! \n";
        }            
    }
    
    
    void show(){
        cout << "pass: " << this->pass << ", gas: " << this->gas << ", Km: " << this-> Km << endl;
    }
};




int main(){
    car kalhambek = {0, 10, 0, 2, 0};
    string op;
    float value;
    while(true){
        cin >> op;
        if(op == "help"){
            cout << "Opções: \n in\n out\n fuel _value\n drive _distance\n show\n sair\n";
        }
        else if(op == "in"){
            kalhambek.in();
        }
        else if(op == "out"){
            kalhambek.out();
        }
        else if(op == "fuel"){
            cin >> value;
            kalhambek.fuel(value);
        }
        else if(op == "drive"){
            cin >> value;
            kalhambek.drive(value);
        }
        else if(op == "show"){            
            kalhambek.show();
        }
        else if(op == "sair"){
            break;
        }
        else{
            cout << "Operação inválida \n";
        }
    }   
}