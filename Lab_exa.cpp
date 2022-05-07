#include <iostream>
#include <mysql.h>
#include <iomanip>
#include "Class_conexion.h"
#include "Estudiante.h"

using namespace std;
MYSQL* conector;
int status = 0;
Class_conexion obj_conexion;


struct Est_estudiantes {
    char chr_nombres[60], chr_apellidos[60], chr_direccion[100], chr_genero, chr_email[70], chr_fecha_nacimiento[10], chr_carnet[40];
    int int_telefono, int_estudiante;
};


void ingreso() {
    Est_estudiantes est_estudiante;
    cout << "******************************" << endl;
    cout << "****Ingreso de estudiantes****" << endl;
    cout << "******************************\n" << endl;
    cout << "Ingrese un nuevo estudiante: " << endl;

    cout << "Carnet: ";
    cin >> est_estudiante.chr_carnet;
    cout << "Nombre: ";
    cin >> est_estudiante.chr_nombres;
    cout << "Apellido: ";
    cin >> est_estudiante.chr_apellidos;
    cout << "Direccion: ";
    cin >> est_estudiante.chr_direccion;
    cout << "Telefono: ";
    cin >> est_estudiante.int_telefono;
    cout << "Genero: ";
    cin >> est_estudiante.chr_genero;
    cout << "E-mail: ";
    cin >> est_estudiante.chr_email;
    cout << "Fecha de nacimiento: ";
    cin >> est_estudiante.chr_fecha_nacimiento;
    Estudiante obj_estudiante = Estudiante(est_estudiante.chr_carnet, est_estudiante.chr_nombres, est_estudiante.chr_apellidos, est_estudiante.chr_direccion, est_estudiante.chr_genero, est_estudiante.chr_email, est_estudiante.chr_fecha_nacimiento, est_estudiante.int_telefono);
    obj_estudiante.ingreso();
}


void mostrar() {
    Estudiante obj_estudiante;
    obj_estudiante.mostrar();
}

void eliminar() {
    Estudiante obj_estudiante;
    obj_estudiante.eliminar();
}

void update() {
    Estudiante obj_estudiante;
    obj_estudiante.update();
}

void banner_motd() {
    system("cls");
    system("date /t");
    cout << "\n\n   _|_|_|  _|_|_|    _|    _|  _|_|_|   " << endl;
    cout << " _|        _|    _|  _|    _|  _|    _| " << endl;
    cout << " _|        _|_|_|    _|    _|  _|    _|  " << endl;
    cout << " _|        _|    _|  _|    _|  _|    _| " << endl;
    cout << "   _|_|_|  _|    _|    _|_|    _|_|_|  \n" << endl;
}

int main()
{
    int int_fin = 0;
    do {
        int int_menu;
        banner_motd();
        cout << "Agregar ............................. 1" << endl;
        cout << "Mostrar ............................. 2" << endl;
        cout << "Actualizar .......................... 3" << endl;
        cout << "Eliminar ............................ 4" << endl;
        cout << "Salir ............................... 5" << endl;
        cout << "\nBienvenido, escoge una opcion:";
        cin >> int_menu;
        system("cls");
        switch (int_menu)
        {
        case 1:
            banner_motd();
            ingreso();
            break;
        case 2:
            banner_motd();
            mostrar();
            break;
        case 3:
            update();
            break;
        case 4:
            eliminar();
            break;
        case 5:
            int_fin = 1;
            cout << "Hora de salida ";
            system("time /t");
            break;
        default:
            cout << "Opcion no valida, sirvase a intentar de nuevo";
            break;
        }
        system("pause");
    } while (int_fin == 0);
}