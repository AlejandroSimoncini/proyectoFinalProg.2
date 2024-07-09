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
        string nombreUsuario;
    public:
        Comentario();
        Comentario(string com, int num, string dniUsr,string nombUsr);
        string toString() const;
        static Comentario fromString(const string& datos);
        string getDniUsuario() ;
        void setNumero(int num);
        void mostrar();
};

#endif 