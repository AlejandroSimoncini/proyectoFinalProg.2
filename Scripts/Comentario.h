#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <iostream>
using namespace std;

class Comentario
{
    private:
        int numero;
        string texto;
        string dniUsuario;
    public:
        Comentario();
        Comentario(string com, int num, string usr);
        string toString();
        static Comentario fromString(string& datos);
        string getDniUsuario();
        void setNumero(int num);
        void mostrar();
};

#endif 