#pragma once
#include "Persona.h"
#include <iostream>
using namespace std;

class Cliente : Persona
{
	string nit, correo_electronico;
	int	idcliente = 0;


public:
	Cliente() {}

	Cliente(int idcl,string nom, string ape, int tel, string fi, char gen, string n, string ce) : Persona(nom, ape, tel, fi, gen) 
	{
		nit = n;
		correo_electronico = ce;
		idcliente = idcl;

	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "SELECT c.idCliente, c.nombres,c.apellidos,c.nit,c.correo_electronico,c.telefono, if(c.genero = 1,'masculino', 'femenino') as genero, c.fechaingreso FROM CLIENTES c";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "------------Clientes---------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout<< "Id: " << fila[0]<<" " << "Nombres: " << fila[1] << " " << "Apellidos: " << fila[2] << " " << "Nit: " << fila[3] << " " << "Email; " << fila[4] << " " << "Telefono: " << fila[5] << " " << "genero " << fila[6] << " " << "Fecha Ingreso: " << fila[7]  << endl;
				}
			}
			else {
				cout << "---Error al Ingresar la informacion---" << endl;
			}
		}
		else {
			cout << "...Error en la conexion...";
		}
		cn.cerrar_conexion();
	}

 	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			

			string insert = "INSERT INTO clientes(nombres,apellidos,telefono,fechaingreso,genero,nit,correo_electronico)values('" + nombres + "', '" + apellidos + "', " + t + ", '" + fecha_ingreso + "', " + genero + ", '" + nit + "', '" + correo_electronico + "');";
			const char* i = insert.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}

		}
		else {
			cout << "...Error en la conexion...";
		}
		cn.cerrar_conexion();


	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string ID = to_string(idcliente);
			string insert = "DELETE FROM clientes WHERE idCliente = '" + ID + "';";



			const char* i = insert.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Registro Eliminado Con Exito ..." << endl;
			}
			else {
				cout << " xxx Error al Eliminar  xxx" << endl;
			}

		}
		else {
			cout << "...Error en la conexion...";
		}
		cn.cerrar_conexion();


	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string ID = to_string(idcliente);

			string insert = "UPDATE clientes SET nombres = '" + nombres + "'," +
				"apellidos = '" + apellidos + "'," +
				"telefono = '" + t + "'," +
				"fechaingreso = '" + fecha_ingreso + "'," +
				"genero = " + genero + "," +
				"nit = '" + nit + "'," +
				"correo_electronico = '" + correo_electronico + "'" +
				"WHERE idCliente = '" + ID + "'";



			const char* i = insert.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Actualizar  xxx" << endl;
			}

		}
		else {
			cout << "...Error en la conexion...";
		}
		cn.cerrar_conexion();


	}


};

