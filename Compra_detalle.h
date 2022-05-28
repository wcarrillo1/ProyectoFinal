#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <string>
using namespace std;
class Compra_detalle
{
protected: 
		 int idCompra_detalle = 0, idCompra = 0, idProducto = 0, cantidad = 0;
		 float precio_costo_unitario = 0.00;

public:	Compra_detalle() {}

	  Compra_detalle(int idCd,int idC, int idPro, int cant, float pcu) {
		  idCompra_detalle = idCd;
		  idCompra = idC;
		  idProducto = idPro;
		  cantidad = cant;
		  precio_costo_unitario = pcu;
	  }

	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  string idC = to_string(idCompra);
		  string Ip = to_string(idProducto);
		  string can = to_string(cantidad);
		  string pc = to_string(precio_costo_unitario);
		  if (cn.getConectar()) {
			  string insert = "INSERT INTO compras_detalle(idCompra,idProduecto,cantidad,precio_costo_unitario)values(" + idC + "," + Ip + "," + can + "," + pc + ",now());";
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
			  string ID = to_string(idCompra);
			  string insert = "DELETE FROM Compras WHERE idCompra = '" + ID + "';";
			  const char* i = insert.c_str();
			  //executar el query
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

	  void leer() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  string ID = to_string(idCompra);
		  if (cn.getConectar()) {
			  string consulta = "select * from compras_detalle where idCompra = '" + ID + "';";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  cout << "------------Compra---------------" << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << "id Detalle Compra: " << fila[0] << " " << "No. Compra: " << fila[1] << " " << "idProducto: " << fila[2] << " " << "Cantidad: " << fila[3] << " " << "Precio Costo: " << fila[4] << endl;
				  }

				  
			  }
			  else {
				  cout << "---No existen datos en el detalle de la compra---" << endl;
			  }

			  
		  }
		  else {
			  cout << "...Error en la conexion...";
		  }
		  cn.cerrar_conexion();
	  }

	  //void actualizar() {
		 // int q_estado;
		 // ConexionBD cn = ConexionBD();
		 // cn.abrir_conexion();
		 // if (cn.getConectar()) {
			//  string ID = to_string(idCompra);
			//  string insert = "UPDATE Compraes SET Compra = '" + no_orden_compra + "'" +
			//	  "WHERE idCompra = '" + ID + "'";
			//  const char* i = insert.c_str();
			//  //executar el query
			//  q_estado = mysql_query(cn.getConectar(), i);
			//  if (!q_estado) {
			//	  cout << "Actualizacion Exitosa ..." << endl;
			//  }
			//  else {
			//	  cout << " xxx Error al Actualizar  xxx" << endl;
			//  }
		 // }
		 // else {
			//  cout << "...Error en la conexion...";
		 // }
		 // cn.cerrar_conexion();
	  //}


};

