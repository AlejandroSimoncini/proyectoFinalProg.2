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
                string nombre = autores[i].getNombre();
                noticias[numNoticias++] = Noticia(titulo, detalle, dia, mes, año, dniAutor,nombre);
                guardarNoticias();
                return;
            } else {
                cout << "No se pueden registrar mas noticias." << endl;
            }
        }
        else 
        {
            cout << "Autor no encontrado." << endl;
        }
    }
}

void Administrar::registrarComentario(string texto, string dniUsuario) {
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
                numComentarios++;
                string nombreUsuario = usuarios[i].getNombre();
                noticias[opcion - 1].agregarComentario(Comentario(texto,numComentarios,dniUsuario,nombreUsuario));
                guardarNoticias();
                cout << "comentario agregado correctamente a la noticia: " << tituloNoticia << endl;
                return;
            }
        }
        cout << "Usuario no encontrado" << endl;
    } 
    else {
        cout << "Operacion cancelada" << endl;
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
    tm* fecha = localtime(&now);
    int mesActual = 1 + fecha->tm_mon;
    int añoActual = 1900 + fecha->tm_year;

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
    cout << "Lista de noticias:"<<endl;
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

bool verificarAnio(int anio) {
    return anio >= 1900 && anio <= 2024;
}

bool verificarDia(int dia, int mes, int anio) {
    if (dia < 1 || dia > 31)
        return false;
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
        return false;
    if (mes == 2) {
        if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) {
            if (dia > 29)
                return false;
        } else {
            if (dia > 28)
                return false;
        }
    }
    return true;
}

bool verificarMes(int mes) {
    return mes >= 1 && mes <= 12;
}

void Administrar::menu() {
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
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1: {
                // Registro de autor
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
                // Registro de usuario
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
                // Carga de noticia
                string titulo, detalle, dniAutor;
                int dia, mes, anio;
                cout << "Ingrese titulo: ";
                getline(cin, titulo);
                cout << "Ingrese detalle: ";
                getline(cin, detalle);
                cout << "Ingrese dia: ";
                cin >> dia;
                cout << "Ingrese mes: ";
                cin >> mes;
                cout << "Ingrese anio: ";
                cin >> anio;
                while (!verificarDia(dia, mes , anio)) {
                    cout << "Dia invalido. Ingrese un dia valido: ";
                    cin >> dia;
                }
                while (!verificarMes(mes)) {
                    cout << "Mes invalido. Ingrese un mes entre 1 y 12: ";
                    cin >> mes;
                }
                while (!verificarAnio(anio)) {
                    cout << "Anio invalido. Ingrese un anio entre 1900 y 2024: ";
                    cin >> anio;
                }
                cin.ignore(); 
                cout << "Ingrese DNI del autor: ";
                getline(cin, dniAutor);
                cargarNoticia(titulo, detalle, dia, mes, anio, dniAutor);
                break;
            }
            case 4: {
                // Registro de comentario
                string texto, dniUsuario;
                cout << "Ingrese texto del comentario: ";
                getline(cin, texto);
                cout << "Ingrese DNI del usuario: ";
                getline(cin, dniUsuario);
                registrarComentario(texto, dniUsuario);
                break;
            }
            case 5: {
                // Listar noticias por año
                listarNoticiasAnio();
                break;
            }
            case 6: {
                // Listar noticias del último mes
                listarNoticiasUltimoMes();
                break;
            }
            case 7: {
                // Mostrar noticia y comentarios
                mostrarNoticiaYComentarios();
                break;
            }
            case 8: {
                // Listar noticias por autor
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