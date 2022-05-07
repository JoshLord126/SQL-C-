#pragma once
#include <iostream>

using namespace std;

class Persona{
	//atributos
protected: 
	char chr_nombres[60], chr_apellidos[60], chr_direccion[100], chr_genero, chr_email[70], chr_fecha_nacimiento[10];
	int int_telefono;
	
protected:
	Persona() {
	}
	Persona(char chr_nom[60], char chr_ape[60], char chr_dir[100], char chr_gen, char chr_ema[70], char chr_fen[10], int int_tel){
		for (int i = 0; i < 100; i++) {
			if (i < 1) {
				chr_genero = chr_gen;
				int_telefono = int_tel;
			}
			if (i < 10) {
				chr_fecha_nacimiento[i] = chr_fen[i];
			}
			if (i < 60) {
				chr_nombres[i] = chr_nom[i];
				chr_apellidos[i] = chr_ape[i];
			}
			if (i < 70) {
				chr_email[i] = chr_ema[i];
			}
			chr_direccion[i] = chr_dir[i];
		}
	}
};