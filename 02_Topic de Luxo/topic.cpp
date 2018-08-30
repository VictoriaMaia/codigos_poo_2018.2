#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Passageiro{
    string nome;
    int idade;

    Passageiro(string nome, int idade){
        this->nome = nome;
        this->idade = idade;
    }
};

struct Topic{    
    int preferencial;
    vector< Passageiro* > poltronas;
    
    Topic(int lotacaoMax = 0, int preferencial = 0):poltronas(lotacaoMax, nullptr){
        this->preferencial = preferencial;
    }

    ~Topic(){
        for(Passageiro *pass : poltronas){
            if(pass != nullptr){
                delete(pass);
            }
        }
    }

    bool out(string nome){
        for(int i = 0; i < (int)poltronas.size(); i++){
            if(poltronas[i] != nullptr && poltronas[i]->nome == nome){
                poltronas[i] = nullptr;
                return true;
            }
        } 
        cout << "Fail : não tem ninguem com esse nome aqui" << endl;
        return false;
    }


    bool in(string nome, int idade){        
        for(Passageiro *p : poltronas){
            if(p != nullptr && p->nome == nome){
                cout << "Erro: Você ja esta na topic" << endl;
                return false;
            }            
        }

        if(idade > 60){
            for(int i = 0; i < (int)poltronas.size(); i++){
                if(poltronas[i] == nullptr){
                    poltronas[i] = new Passageiro(nome, idade);
                    return true;
                }
            }
            cout << "Erro: Topic lotada" << endl;
            return false;
        }
        
        for(int i = this->preferencial; i < (int)poltronas.size(); i++){
            if(poltronas[i] == nullptr){
                poltronas[i] = new Passageiro(nome, idade);
                return true;
            }
        }

        for(int i = 0; i < this->preferencial; i++){
            if(poltronas[i] == nullptr){
                poltronas[i] = new Passageiro(nome, idade);
                return true;
            }
        }   
        
        cout << "Erro: Topic lotada" << endl;
        return false;
    }

    string show(){
        stringstream ss;
        ss << "[";
        for(int i = 0; i < (int)poltronas.size(); i++){            
            if(i < this->preferencial){
                ss << " @";
                if(poltronas[i] != nullptr){                    
                    ss << poltronas[i]->nome << ":" << poltronas[i]->idade;
                }
            }
            else{  
                ss << " #";          
                if(poltronas[i] != nullptr){
                    ss <<  poltronas[i]->nome << ":" << poltronas[i]->idade;
                }                
            }
        }
        ss << " ]";
        return ss.str();           
    }
};
// struct Controller{
    
// };


int main(){
    Topic top;
    string op;
    while(true){
        cin >> op;
        if(op == "end"){
            break;
        }else if(op == "help"){
            cout << "show; new (lotacaoTotal,preferencial); in (nome,idade); out (nome); " << endl;
        }else if(op == "show"){
            cout << "    " << top.show() << endl;
        }else if(op == "new"){
            int lotacaoMax, preferencial;
            cin >> lotacaoMax >> preferencial;
            top = Topic(lotacaoMax, preferencial);
            cout << "    done" << endl;
        }else if(op == "in"){
            string nome;
            int idade;
            cin >> nome >> idade;
            if(top.in(nome, idade)){
                cout << "    done" << endl;
            }
        }else if(op == "out"){
            string nome;
            cin >> nome;
            if(top.out(nome)){
                cout << "   done" << endl;
            }
        }
    }
    


    return 0;
}