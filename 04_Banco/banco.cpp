#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Operacao{
public:
    string descricao;
    float valor;
    float saldo;

    Operacao(string descricao, float valor, float saldo){
        this->descricao = descricao;
        this->valor = valor;
        this->saldo = saldo;
    }
};

class Conta{
private:
    int ID;
    float saldo;
    int numero;
    vector <Operacao> extr;

public:
    Conta(int ID = 0, float saldo = 0){
        this->ID = ID;
        this->saldo = saldo;
        pushOperation("abertura", 0, saldo);
    }

    void pushOperation(string labelDescricao, float value, float saldo){
        extr.push_back(Operacao(labelDescricao, value, saldo));
    }

    bool depositar(int valor){
        if(valor >= 0){
            this->saldo = this->saldo + valor;
            pushOperation("deposito", valor, this->saldo);
            return true;
        }
        return false;
    }

    bool sacar(int valor){
        if(this->saldo >= valor){
            this->saldo = this->saldo - valor;
            pushOperation("saque", (-valor), this->saldo);
            return true;
        }
        return false;
    }

    void tarifa(int valor){
        this->saldo = this->saldo - valor;
        pushOperation("tarifa", (-valor), this->saldo);
    }

    bool extornar(int posicao){
        if(posicao < (int)extr.size()){
            if(this->extr[posicao].descricao == "tarifa"){
                    this->saldo += extr[posicao].valor;
                    pushOperation("extorno", (-extr[posicao].valor), this->saldo);
                    return true; 
            }
        }
        return false;
    }

    string extratoN(int valor){
        stringstream ss;
        for(int i = (extr.size() - valor); i < (int)extr.size(); i++){
            ss << "  " << i << ":" << setw(9) << extr[i].descricao << ":" ;
            if(extr[i].valor < 0){
                ss << "\033[31m" << setw(4) << extr[i].valor;
            }else{
                ss << "\033[34m" << setw(4) << extr[i].valor;
            }
            ss << "\033[30m" << ":" << setw(5) << extr[i].saldo << endl;
        }
        return ss.str();
    }

    string extrato(){
        stringstream ss;
        for(int i = 0; i < (int)extr.size(); i++){
            ss << "  " << i << ":" << setw(9) << extr[i].descricao << ":" ;
            if(extr[i].valor < 0){
                ss << "\033[31m" << setw(4) << extr[i].valor;
            }else{
                ss << "\033[34m" << setw(4) << extr[i].valor;
            }
            ss << "\033[30m" << ":" << setw(5) << extr[i].saldo << endl;
        }
        return ss.str();
    }

    string show(){
        stringstream ss;
        ss << "conta:" << this->ID << " saldo:" << this->saldo;
        return ss.str();
    }
};

struct Controll{
    Conta conta;

    string funcoes(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        if(op == "help"){
            out << "  end;" << endl
                << "  show;" << endl
                << "  init(IDconta);" << endl
                << "  extrato;" << endl
                << "  extratoN(valor);" << endl
                << "  deposito(valor);" << endl
                << "  saque(valor);" << endl
                << "  tarifa(valor);" << endl
                << "  extornar(valores);" << endl;
        }else if(op == "show"){
            out << "  " << conta.show();
        }else if(op == "init"){
            int id;
            in >> id;
            conta = Conta(id);
            out << "  success";
        }else if(op == "extrato"){
            out << conta.extrato();
        }else if(op == "extratoN"){
            int valor;
            in >> valor;
            out << conta.extratoN(valor);
        }else if(op == "deposito"){
            int valor;
            in >> valor;
            if(conta.depositar(valor)){
                out << "  success";
            }
            else{
                out << "  fail: epa! valor invalido para deposito";
            }
        }else if(op == "saque"){
            int valor;
            in >> valor;
            if(conta.sacar(valor)){
                out << "  success";
            }
            else{
                out << "  fail: epa! voce nao tem esse dinheiro todo pra sacar";
            }
        }else if(op == "tarifa"){
            int valor;
            in >> valor;
            conta.tarifa(valor);
            out << "  success";
        }else if(op == "extornar"){
            int valor;
            while (in >> valor){
                if(conta.extornar(valor)){
                    out << "  success:" << setw(6) << "indice " << valor << " extornado" << endl;
                }
                else{
                    out << "  failure:" << setw(6) << "indice " << valor << " nao e tarifa" << endl;
                }
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
            cout << "\033[32m" << line << "\033[30m" << endl;
            cout << funcoes(line) << endl;
        }
    }

};


int main(){
    Controll ctr;
    ctr.exec();

    return 0;
}