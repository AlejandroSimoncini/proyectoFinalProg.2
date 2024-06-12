#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Administrar.h"


void Administrar::guardarAutores()  {
    ofstream archivo("autores.txt");
    for (int i = 0; i < numAutores; i++) {
        archivo << autores[i].toString() << endl;
    }
}

void Administrar::cargarAutores() {
    ifstream archivo("autores.txt");
    string linea;
    numAutores = 0;
    while (getline(archivo, linea) && numAutores < MAX_AUTORES) {
        autores[numAutores++] = Autor::fromString(linea);
    }
}

void Administrar::guardarUsuarios()  {
    ofstream archivo("usuarios.txt");
    for (int i = 0; i < numUsuarios; i++) {
        archivo << usuarios[i].toString() << endl;
    }
}

void Administrar::cargarUsuarios() {
    ifstream archivo("usuarios.txt");
    string linea;
    numUsuarios = 0;
    while (getline(archivo, linea) && numUsuarios < MAX_USUARIOS) {
        usuarios[numUsuarios++] = Usuario::fromString(linea);
    }
}

void Administrar::guardarNoticias()  {
    ofstream archivo("noticias.txt");
    for (int i = 0; i < numNoticias; i++) {
        archivo << noticias[i].toString() << endl;
        for (int j = 0; j < noticias[i].getNumComentarios(); j++) {
            archivo << noticias[i].getComentarios()[j].toString() << endl;
        }
        archivo << "###" << endl;
    }
}

void Administrar::cargarNoticias() {
    ifstream archivo("noticias.txt");
    string linea;
    numNoticias = 0;
    while (getline(archivo, linea) && numNoticias < MAX_NOTICIAS) {
        if (linea == "###") continue;
        Noticia noticia = Noticia::fromString(linea);
        while (getline(archivo, linea) && linea != "###") {
            noticia.agregarComentario(Comentario::fromString(linea));
        }
        noticias[numNoticias++] = noticia;
    }
}

Administrar::Administrar() : numAutores(0), numUsuarios(0), numNoticias(0) {
    cargarAutores();
    cargarUsuarios();
    cargarNoticias();
}

void Administrar::registrarAutor(string dni, string nombre, string medio) {
    if (numAutores < MAX_AUTORES) {
        autores[numAutores++] = Autor(dni, nombre, medio);
        guardarAutores();
    } else {
        cout << "No se pueden registrar mas autores." << endl;
    }
}

void Administrar::registrarUsuario(string dni, string nombre, int edad) {
    if (numUsuarios < MAX_USUARIOS) {
        usuarios[numUsuarios++] = Usuario(dni, nombre, edad);
        guardarUsuarios();
    } else {
        cout << "No se pueden registrar mas usuarios." << endl;
    }
}

void Administrar::cargarNoticia(string titulo, string detalle, int dia, int mes, int año, string dniAutor) {
    for (int i = 0; i < numAutores; i++) {
        if (autores[i].getDni() == dniAutor) {
            if (numNoticias < MAX_NOTICIAS) {
                noticias[numNoticias++] = Noticia(titulo, detalle, dia, mes, año, dniAutor);
                guardarNoticias();
                return;
            } else {
                cout << "No se pueden registrar mas noticias." << endl;
            }
        }
    }
    cout << "Autor no encontrado." << endl;
}

void Administrar::registrarComentario(int numero, string texto, string dniUsuario) {
    cout << "Lista de noticias:"<<endl;
    for (int i = 0; i < numNoticias; i++) {
        cout << i + 1 << ". " << noticias[i].getTitulo() << endl;
    }

    int opcion;
    cout << "Seleccione la noticia a comentar (0 para cancelar): ";
    cin >> opcion;

    if (opcion > 0 && opcion <= numNoticias) {
        string tituloNoticia = noticias[opcion - 1].getTitulo();
        for (int i = 0; i < numUsuarios; i++) {
            if (usuarios[i].getDni() == dniUsuario) {
                noticias[opcion - 1].agregarComentario(Comentario(texto,numero,dniUsuario));
                guardarNoticias();
                cout << "comentario agregado correctamente a la noticia: " << tituloNoticia << endl;
                return;
            }
        }
        cout << "Usuario no encontrado." << endl;
    } 
    else {
        cout << "Operacion cancelada." << endl;
    }
}

void Administrar::listarNoticiasAnio()
{
    int año;
    cout << "Ingrese año: ";
    cin >> año;

    cout << "Noticias publicadas en el año " << año << ":"<<endl;
    for (int i = 0; i < numNoticias; i++) {
        if (noticias[i].getAnio() == año) {
            cout << i + 1 << ". " << noticias[i].getTitulo() << endl;
        }
    }

    int opcion;
    cout << "Seleccione una noticia para ver detalles (0 para salir): ";
    cin >> opcion;

    if (opcion > 0 && opcion <= numNoticias) {
        noticias[opcion - 1].mostrar();
    }
}

void Administrar::listarNoticiasUltimoMes()  {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int mesActual = 1 + ltm->tm_mon;
    int añoActual = 1900 + ltm->tm_year;

    cout << "Noticias publicadas en el último mes:"<<endl;
    int count = 0;
    for (int i = 0; i < numNoticias; i++) {
        if (noticias[i].getAnio() == añoActual && noticias[i].getMes() == mesActual) {
            cout << count + 1 << ". " << noticias[i].getTitulo() << endl;
            count++;
        }
    }

    int opcion;
    cout << "Seleccione una noticia para ver detalles (0 para salir): ";
    cin >> opcion;

    if (opcion > 0 && opcion <= count) {
        noticias[opcion - 1].mostrar();
    }
}

void Administrar::mostrarNoticiaYComentarios()  {
    cout << "\nLista de noticias:\n";
    for (int i = 0; i < numNoticias; i++) {
        cout << i + 1 << ". " << noticias[i].getTitulo() << endl;
    }

    int opcion;
    cout << "Seleccione una noticia para ver detalles y comentarios (0 para salir): ";
    cin >> opcion;

    if (opcion > 0 && opcion <= numNoticias) {
        noticias[opcion - 1].mostrar();
    }
}

void Administrar::listarNoticiasAutor()  {
    cout << "Lista de autores:"<<endl;
    for (int i = 0; i < numAutores; i++) {
        cout << i + 1 << ". " << autores[i].getNombre() << endl;
    }

    int opcion;
    cout << "Seleccione un autor para ver sus noticias (0 para salir): ";
    cin >> opcion;

    if (opcion > 0 && opcion <= numAutores) {
        string dniAutor = autores[opcion - 1].getDni();
        cout << "Noticias publicadas por " << autores[opcion - 1].getNombre() << ":"<<endl;
        for (int i = 0; i < numNoticias; i++) {
            if (noticias[i].getDniAutor() == dniAutor) {
                cout << i + 1 << ". " << noticias[i].getTitulo() << endl;
            }
        }

        cout << "Seleccione una noticia para ver detalles (0 para salir): ";
        cin >> opcion;

        if (opcion > 0 && opcion <= numNoticias) {
            noticias[opcion - 1].mostrar();
        }
    }
}

void Administrar::menu() 
{

        int opcion;
    do {
        cout << "--- Menu ---" << endl;
        cout << "1. Registrar autor" << endl;
        cout << "2. Registrar usuario" << endl;
        cout << "3. Cargar noticia" << endl;
        cout << "4. Registrar Comentario" << endl;
        cout << "5. Listar noticias por anio" << endl;
        cout << "6. Listar noticias del ultimo mes" << endl;
        cout << "7. Mostrar noticia y comentarios" << endl;
        cout << "8. Listar noticias por autor" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: " << endl;
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1: {
                string dni, nombre, medio;
                cout << "Ingrese DNI: ";
                getline(cin, dni);
                cout << "Ingrese nombre: ";
                getline(cin, nombre);
                cout << "Ingrese medio: ";
                getline(cin, medio);
                registrarAutor(dni, nombre, medio);
                break;
            }
            case 2: {
                string dni, nombre;
                int edad;
                cout << "Ingrese DNI: ";
                getline(cin, dni);
                cout << "Ingrese nombre: ";
                getline(cin, nombre);
                cout << "Ingrese edad: ";
                cin >> edad;
                cin.ignore(); 
                registrarUsuario(dni, nombre, edad);
                break;
            }
            case 3: {
                string titulo, detalle, dniAutor;
                int dia, mes, año;
                cout << "Ingrese título: " << endl;
                getline(cin, titulo);
                cout << "Ingrese detalle: " << endl;
                getline(cin, detalle);
                cout << "Ingrese día: " << endl;
                cin >> dia;
                cout << "Ingrese mes: " << endl;
                cin >> mes;
                cout << "Ingrese anio: " << endl;
                cin >> año;
                cin.ignore(); 
                cout << "Ingrese DNI del autor: " << endl;
                getline(cin, dniAutor);
                cargarNoticia(titulo, detalle, dia, mes, año, dniAutor);
                break;
            }
            case 4: {
                int numero;
                string texto, dniUsuario;
                cout << "Ingrese numero de comentario: " << endl;
                cin >> numero;
                cin.ignore(); 
                cout << "Ingrese texto del comentario: " << endl;
                getline(cin, texto);
                cout << "Ingrese DNI del usuario: " << endl;
                getline(cin, dniUsuario);
                registrarComentario(numero, texto, dniUsuario);
                break;
            }
            case 5: {
                listarNoticiasAnio();
                break;
            }
            case 6: {
                listarNoticiasUltimoMes();
                break;
            }
            case 7: {
                mostrarNoticiaYComentarios();
                break;
            }
            case 8: {
                listarNoticiasAutor();
                break;
            }
            case 0: {
                cout << "Saliendo..." << endl;
                break;
            }
            default: {
                cout << "Opcion no valida" << endl;
            }
        }
    } while (opcion != 0);
}
