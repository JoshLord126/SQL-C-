#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "Persona.h"
#include "Class_conexion.h"

class Estudiante: public Persona{
	private: 
		//int int_estudiante;
		char chr_carnet[40];
			 
	public:
		Estudiante() {
		}
		Estudiante(char chr_car[40], char chr_nom[60], char chr_ape[60], char chr_dir[100], char chr_gen, char chr_ema[70], char chr_fen[10], int int_tel) : Persona(chr_nom, chr_ape, chr_dir, chr_gen, chr_ema, chr_fen, int_tel) {
			//int_estudiante = int_est;
			for (int i = 0; i < 40; i++) {
				chr_carnet[i] = chr_car[i];
			}
		}

        Class_conexion obj_conexion;

        void ingreso() {
            obj_conexion.conexion_open_sql();

            string str_nombre(chr_nombres);
            string str_apellido(chr_apellidos);
            string str_direccion(chr_direccion);
            string str_genero(1, chr_genero);
            string str_email(chr_email);
            string str_fecha_nacimiento(chr_fecha_nacimiento);
            string str_telefono = to_string(int_telefono);
            string str_carnet(chr_carnet);
            string insert_dat = "insert into estudiantes(carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento) values('" + str_carnet + "', '" + str_nombre + "', '" + str_apellido + "', '" + str_direccion + "', '" + str_telefono + "', " + str_genero + ", '" + str_email + "', '" + str_fecha_nacimiento + "')";
            const char* execute_insert = insert_dat.c_str();
            int q_estado = mysql_query(obj_conexion.getConector(), execute_insert);
           if (!q_estado) {
                cout << "\n\nIngreso OK\n\n";
           }
           else {
                cout << "\n\nIngreso F\n\n";
           }
           obj_conexion.conexion_closed_sql();
        }

        void mostrar() {
            obj_conexion.conexion_open_sql();
            MYSQL_ROW fila;
            MYSQL_RES* result;

            string show_dat = "select * from estudiantes";
            const char* execute_show = show_dat.c_str();
            int q_estado = mysql_query(obj_conexion.getConector(), execute_show);
            if (!q_estado) {
                cout << "*********************************************************************************************************************************************************" << endl;
                cout << "***********************************************************************ESTUDIANTES***********************************************************************" << endl;
                cout << "*********************************************************************************************************************************************************" << endl;
                cout << "No. | ID | Carnet |    Nombres    |     Apellidos     |        Direccion        |   Telefono   | Genero |           E-mail           | Fech. Nacimiento |" << endl;
                int i = 1;
                result = mysql_store_result(obj_conexion.getConector());
                while (fila = mysql_fetch_row(result)) {
                    cout << i << setw(5) << " | " << setw(2) << fila[0] << " | " << setw(6) << fila[1] << " | " << setw(13) << fila[2] << " | " << setw(17) << fila[3] << " | " << setw(23) << fila[4] << " | " << setw(12) << fila[5] << " | " << setw(6) << fila[6] << " | " << setw(26) << fila[7] << " | " << setw(16) << fila[8] << " |" << endl;
                    i++;
                }
            }
            else {
                cout << "\n\nMostrar F\n\n";
            }
            obj_conexion.conexion_closed_sql();
        }

        void eliminar() {
            string delete_dat, str_id;
            mostrar();
            cout << "\n\n\n\nIngrese el ID para eliminar: ";
            cin >> str_id;
            obj_conexion.conexion_open_sql();
            delete_dat = "delete from estudiantes where id_estudiante=" + str_id;
            const char* execute_delete = delete_dat.c_str();
            int q_estado = mysql_query(obj_conexion.getConector(), execute_delete);
            if (!q_estado) {
                cout << "\n\nEliminado\n\n";
            }
            else {
                cout << "\n\nF\n\n";
            }
            obj_conexion.conexion_closed_sql();
        }

        void update() {
            string update_dat, str_id, str_new, str_column;
            mostrar();
            cout << "\n\n\n\nIngrese el ID para alterar: ";
            cin >> str_id;
            cout << "Ingresa el campo a editar: ";
            cin >> str_column;
            cout << "Ingrese el nuevo valor: ";
            cin >> str_new;

            obj_conexion.conexion_open_sql();

            update_dat = "update estudiantes set " + str_column + "='" + str_new + "' where id_estudiante=" + str_id;
            const char* execute_update = update_dat.c_str();
            int q_estado = mysql_query(obj_conexion.getConector(), execute_update);
            if (!q_estado) {
                cout << "\n\Actualizado\n\n";
            }
            else {
                cout << "\n\nF\n\n";
            }
            obj_conexion.conexion_closed_sql();
        }
};

