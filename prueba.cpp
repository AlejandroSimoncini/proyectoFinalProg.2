#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

const int MAX_AUTORES = 100;
const int MAX_USUARIOS = 100;
const int MAX_NOTICIAS = 100;

class Persona {
    protected:
        string DNI;
        string nombre;
    public:
        Persona();
        Persona(string dni, string nom);
        string getDni();
        string getNombre();
};

Persona::Persona() {
    nombre = "";
    DNI = "";
}

Persona::Persona(string dni, string nom) {
    nombre = nom;
    DNI = dni;
}

string Persona::getNombre() {
    return nombre;
}

string Persona::getDni() {
    return DNI;
}

class Autor : public Persona {
    private:
        string medio;
    public:
        Autor();
        Autor(string dni, string nom, string med);
        string getMedio();
        string toString();
        static Autor fromString(string& datos);
};

Autor::Autor() {
    DNI= "";
    nombre = "";
    medio = "";
}

Autor::Autor(string dni, string nom, string medi) : Persona(dni, nom) {
    medio = medi;
}

string Autor::getMedio() {
    return medio;
}

string Autor::toString() {
    return DNI + "," + nombre + "," + medio;
}

Autor Autor::fromString(string& datos) {
    stringstream ss(datos);
    string dni, nombre, medio;
    getline(ss, dni, ',');
    getline(ss, nombre, ',');
    getline(ss, medio, ',');
    return Autor(dni, nombre, medio);
}

class Comentario {
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

Comentario::Comentario() {
    texto = "";
    numero = 0;
    dniUsuario = "";
}

Comentario::Comentario(string com, int num, string usr) {
    texto = com;
    numero = num;
    dniUsuario = usr;
}

string Comentario::toString() {
    return to_string(numero) + "," + texto + "," + dniUsuario;
}

Comentario Comentario::fromString(string& datos) {
    stringstream ss(datos);
    string texto, strNumero, dniUser;
    getline(ss, strNumero, ',');
    getline(ss, texto, ',');
    getline(ss, dniUser, ',');
    int num = stoi(strNumero);
    return Comentario(texto, num, dniUser);
}

string Comentario::getDniUsuario() {
    return dniUsuario;
}

void Comentario::setNumero(int num) {
    numero = num;
}

void Comentario::mostrar() {
    cout << "Comentario #" << numero << " por " << dniUsuario << ": " << texto << endl;
}

const int MAX_COMENTARIOS = 100;

class Noticia {
    private:
        string titulo;
        string detalle;
        int dia;
        int mes;
        int anio;
        string dniAutor;
        Comentario comentarios[MAX_COMENTARIOS];
        int numComentarios;
        int proximoNumeroComentario;

    public:
        Noticia();
        Noticia(string tit, string det, int d, int m, int a, string dniA);
        void agregarComentario(Comentario comment);
        void mostrar();
        string toString();
        static Noticia fromString(string& str);
        int getAnio();
        int getMes();
        string getDniAutor();
        string getTitulo();
        Comentario* getComentarios();
        int getNumComentarios();
};

Noticia::Noticia() {
    titulo = "";
    detalle = "";
    dia = 0;
    mes = 0;
    anio = 0;
    dniAutor = "";
    numComentarios = 0;
    proximoNumeroComentario = 1;
}

Noticia::Noticia(string tit, string det, int d, int m, int a, string dniA) {
    titulo = tit;
    detalle = det;
    dia = d;
    mes = m;
    anio = a;
    dniAutor = dniA;
    numComentarios = 0;
    proximoNumeroComentario = 1;
}

void Noticia::agregarComentario(Comentario comment) {
    if (numComentarios < MAX_COMENTARIOS) {
        comment.setNumero(proximoNumeroComentario++);
        comentarios[numComentarios++] = comment;
    }
}

void Noticia::mostrar() {
    cout << "Titulo: " << titulo << endl;
    cout << "Detalle: " << detalle << endl;
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
    cout << "Autor: " << dniAutor << endl;
    cout << "Comentarios: " << endl;
    for (int i = 0; i < numComentarios; i++) {
        comentarios[i].mostrar();
    }
}

string Noticia::toString() {
    return titulo + "," + detalle + "," + to_string(dia) + "," + to_string(mes) + "," + to_string(anio) + "," + dniAutor;
}

Noticia Noticia::fromString(string& datos) {
    stringstream ss(datos);
    string titulo, detalle, diaStr, mesStr, anioStr, dniAutor;
    getline(ss, titulo, ',');
    getline(ss, detalle, ',');
    getline(ss, diaStr, ',');
    getline(ss, mesStr, ',');
    getline(ss, anioStr, ',');
    getline(ss, dniAutor, ',');
    int dia = stoi(diaStr);
    int mes = stoi(mesStr);
    int anio = stoi(anioStr);
    return Noticia(titulo, detalle, dia, mes, anio, dniAutor);
}

int Noticia::getAnio() {
    return anio;
}

int Noticia::getMes() {
    return mes;
}

string Noticia::getDniAutor() {
    return dniAutor;
}

string Noticia::getTitulo() {
    return titulo;
}

Comentario* Noticia::getComentarios() {
    return comentarios;
}

int Noticia::getNumComentarios() {
    return numComentarios;
}

class Usuario : public Persona {
    private:
        int edad;
    public:
        Usuario();
        Usuario(string dni, string nom, int ed);
        int getEdad();
        string toString();
        static Usuario fromString(string& datos);
};

Usuario::Usuario() {
    DNI = "";
    nombre = "";
    edad = 0;
}

Usuario::Usuario(string dni, string nom, int ed) : Persona(dni, nom) {
    edad = ed;
}

int Usuario::getEdad() {
    return edad;
}

string Usuario::toString() {
    return DNI + "," + nombre + "," + to_string(edad);
}

Usuario Usuario::fromString(string& datos) {
    stringstream ss(datos);
    string dni, nombre, edadStr;
    getline(ss, dni, ',');
    getline(ss, nombre, ',');
    getline(ss, edadStr, ',');
    int edad = stoi(edadStr);
    return Usuario(dni, nombre, edad);
}

class Administrar {
    private:
        Noticia noticias[MAX_NOTICIAS];
        Usuario usuarios[MAX_USUARIOS];
        Autor autores[MAX_AUTORES];
        int numAutores;
        int numUsuarios;
        int numNoticias;
    public:
        Administrar();
        void guardarAutor();
        void cargarAutor();
        void registrarAutor(string dni, string nombre, string medio);

        void guardarUsuario();
        void cargarUsuario();
        void registrarUsuario(string dni, string nombre, int edad);

        void guardarNoticia();
        void cargarNoticia();
        void registrarNoticia(string titulo, string detalle, int dia, int mes, int año, string dniAutor);

        void registrarComentario(int numero, string texto, string dniUsuario);
        
        void filtrarnoticiasAnio();
        void filtrarnoticiasUltmes();
        void filtrarAutor();
        void mostrarNoticiaComentarios();
        
        void menu();
};

void Administrar::guardarAutor() {
    ofstream archivo("autores.txt");
    for (int i = 0; i < numAutores; i++) {
        archivo << autores[i].toString() << endl;
    }
}

void Administrar::cargarAutor() {
    ifstream archivo("autores.txt");
    string linea;
    numAutores = 0;
    while (getline(archivo, linea) && numAutores < MAX_AUTORES) {
        autores[numAutores++] = Autor::fromString(linea);
    }
}

void Administrar::guardarUsuario() {
    ofstream archivo("usuarios.txt");
    for (int i = 0; i < numUsuarios; i++) {
        archivo << usuarios[i].toString() << endl; 
    }
}

void Administrar::cargarUsuario() {
    ifstream archivo("usuarios.txt");
    string linea;
    numUsuarios = 0;
    while (getline(archivo, linea) && numUsuarios < MAX_USUARIOS) {
        usuarios[numUsuarios++] = Usuario::fromString(linea);
    }
}

void Administrar::guardarNoticia() {
    ofstream archivo("noticias.txt");
    for (int i = 0; i < numNoticias; i++) {
        archivo << noticias[i].toString() << endl; 
    }
}

void Administrar::cargarNoticia() {
    ifstream archivo("noticias.txt");
    string linea;
    numNoticias = 0;
    while (getline(archivo, linea) && numNoticias < MAX_NOTICIAS) {
        noticias[numNoticias++] = Noticia::fromString(linea);
    }
}

Administrar::Administrar() {
    numAutores = 0;
    numUsuarios = 0;
    numNoticias = 0;
    cargarAutor();
    cargarUsuario();
    cargarNoticia();
}

void Administrar::registrarAutor(string dni, string nombre, string medio) {
    for (int i = 0; i < numAutores; i++) {
        if (autores[i].getDni() == dni) {
            cout << "El autor con este DNI ya esta registrado." << endl;
            return;
        }
    }

    if (numAutores < MAX_AUTORES) {
        autores[numAutores++] = Autor(dni, nombre, medio);
        guardarAutor();
        cout << "Autor registrado exitosamente." << endl;
    } else {
        cout << "No se pueden registrar más autores." << endl;
    }
}

void Administrar::registrarUsuario(string dni, string nombre, int edad) {
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i].getDni() == dni) {
            cout << "El usuario con este DNI ya esta registrado." << endl;
            return;
        }
    }

    if (numUsuarios < MAX_USUARIOS) {
        usuarios[numUsuarios++] = Usuario(dni, nombre, edad);
        guardarUsuario();
        cout << "Usuario registrado exitosamente." << endl;
    } else {
        cout << "No se pueden registrar más usuarios." << endl;
    }
}

void Administrar::registrarNoticia(string titulo, string detalle, int dia, int mes, int año, string dniAutor) {
    bool autorRegistrado = false;
    for (int i = 0; i < numAutores; i++) {
        if (autores[i].getDni() == dniAutor) {
            autorRegistrado = true;
            break;
        }
    }

    if (!autorRegistrado) {
        cout << "No se puede registrar la noticia. El autor no está registrado." << endl;
        return;
    }

    if (numNoticias < MAX_NOTICIAS) {
        noticias[numNoticias++] = Noticia(titulo, detalle, dia, mes, año, dniAutor);
        guardarNoticia();
        cout << "Noticia registrada exitosamente." << endl;
    } else {
        cout << "No se pueden registrar más noticias." << endl;
    }
}

void Administrar::registrarComentario(int numero, string texto, string dniUsuario) {
    bool usuarioRegistrado = false;
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i].getDni() == dniUsuario) {
            usuarioRegistrado = true;
            break;
        }
    }

    if (!usuarioRegistrado) {
        cout << "No se puede registrar el comentario. El usuario no está registrado." << endl;
        return;
    }

    for (int i = 0; i < numNoticias; i++) {
        if (noticias[i].getNumComentarios() < MAX_COMENTARIOS) {
            noticias[i].agregarComentario(Comentario(texto, numero, dniUsuario));
            guardarNoticia();
            cout << "Comentario registrado exitosamente." << endl;
            return;
        }
    }

    cout << "No se pudo registrar el comentario." << endl;
}

void Administrar::filtrarnoticiasAnio() {
    int anio;
    cout << "Ingrese el año: ";
    cin >> anio;
    for (int i = 0; i < numNoticias; i++) {
        if (noticias[i].getAnio() == anio) {
            noticias[i].mostrar();
        }
    }
}

void Administrar::filtrarnoticiasUltmes() {
    time_t t = time(nullptr);
    tm* timePtr = localtime(&t);
    int mesActual = timePtr->tm_mon + 1;
    int anioActual = timePtr->tm_year + 1900;

    for (int i = 0; i < numNoticias; i++) {
        if (noticias[i].getAnio() == anioActual && noticias[i].getMes() == mesActual) {
            noticias[i].mostrar();
        }
    }
}

void Administrar::filtrarAutor() {
    string dniAutor;
    cout << "Ingrese el DNI del autor: ";
    cin >> dniAutor;
    for (int i = 0; i < numNoticias; i++) {
        if (noticias[i].getDniAutor() == dniAutor) {
            noticias[i].mostrar();
        }
    }
}

void Administrar::mostrarNoticiaComentarios() {
    for (int i = 0; i < numNoticias; i++) {
        noticias[i].mostrar();
    }
}

void Administrar::menu() {
    int opcion;
    do {
        cout << "Menu:" << endl;
        cout << "1. Registrar autor" << endl;
        cout << "2. Registrar usuario" << endl;
        cout << "3. Registrar noticia" << endl;
        cout << "4. Registrar comentario" << endl;
        cout << "5. Filtrar noticias por año" << endl;
        cout << "6. Filtrar noticias del ultimo mes" << endl;
        cout << "7. Filtrar noticias por autor" << endl;
        cout << "8. Mostrar noticias y comentarios" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1: {
                string dni, nombre, medio;
                cout << "Ingrese DNI: ";
                cin >> dni;
                cout << "Ingrese nombre: ";
                cin >> nombre;
                cout << "Ingrese medio: ";
                cin >> medio;
                registrarAutor(dni, nombre, medio);
                break;
            }
            case 2: {
                string dni, nombre;
                int edad;
                cout << "Ingrese DNI: ";
                cin >> dni;
                cout << "Ingrese nombre: ";
                cin >> nombre;
                cout << "Ingrese edad: ";
                cin >> edad;
                registrarUsuario(dni, nombre, edad);
                break;
            }
            case 3: {
                string titulo, detalle, dniAutor;
                int dia, mes, anio;
                cout << "Ingrese titulo: ";
                cin >> titulo;
                cout << "Ingrese detalle: ";
                cin >> detalle;
                cout << "Ingrese dia: ";
                cin >> dia;
                cout << "Ingrese mes: ";
                cin >> mes;
                cout << "Ingrese año: ";
                cin >> anio;
                cout << "Ingrese DNI del autor: ";
                cin >> dniAutor;
                registrarNoticia(titulo, detalle, dia, mes, anio, dniAutor);
                break;
            }
            case 4: {
                int numero;
                string texto, dniUsuario;
                cout << "Ingrese numero de comentario: ";
                cin >> numero;
                cout << "Ingrese texto del comentario: ";
                cin >> texto;
                cout << "Ingrese DNI del usuario: ";
                cin >> dniUsuario;
                registrarComentario(numero, texto, dniUsuario);
                break;
            }
            case 5:
                filtrarnoticiasAnio();
                break;
            case 6:
                filtrarnoticiasUltmes();
                break;
            case 7:
                filtrarAutor();
                break;
            case 8:
                mostrarNoticiaComentarios();
                break;
            case 9:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while(opcion != 9);
}

int main() {
    Administrar admin;
    admin.menu();
    return 0;
}
