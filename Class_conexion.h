#pragma once
#include <mysql.h>
#include <iostream>

using namespace std;

class Class_conexion
{
	private: 
		MYSQL* conector;
		int status = 0;
	
	public: 
		void conexion_open_sql() {
			conector = mysql_init(0);
			conector = mysql_real_connect(conector, "127.0.0.1", "Lab-con", "Lab_con", "estudiante", 3306, NULL, 0);
			status = 1;
			//cout << "Conexion establecida!!\n\n\n";
		}
		MYSQL* getConector() {
			return conector;
		}
		void conexion_closed_sql() {
			mysql_close(conector);
			status = 0;
		}
};

