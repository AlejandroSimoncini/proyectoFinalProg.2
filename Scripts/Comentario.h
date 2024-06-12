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
        string toString() const;
        static Comentario fromString(const string& datos);
        string getDniUsuario() const;
        void setNumero(int num);
        void mostrar() const;
};

#endif 