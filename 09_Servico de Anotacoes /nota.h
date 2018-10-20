#ifndef NOTA
#define NOTA
#include <iostream>
using namespace std;

class Nota{
    string titulo;
    string texto;
public:
    Nota(string titulo = "", string texto = ""):titulo(titulo),texto(texto){}

    string toString(){
        return "[" + titulo + "; " + texto + "]";
    }

    string getTitulo(){
        return titulo;
    }
};

#endif