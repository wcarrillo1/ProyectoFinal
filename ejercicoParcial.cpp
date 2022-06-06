#include <iostream>
#include <string>
#include <mysql.h>
#include "Estudiantes.h"
#include "Puesto.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Marca.h"
#include "Productos.h"
using namespace std;

void menuPrincipal() {
	cout << "*****menu*****" << endl;
	cout << "1.Administracion" << endl;
	cout << "2.Operador" << endl;
	cout << "3.Salir" << endl;
	cout << "Seleccione una Opcion: ";
}

void menuAdministracion() {
	cout << "Bienvendio al menu de administracion" << endl;
	cout << "1.Puestos" << endl;
	cout << "2.Clientes" << endl;
	cout << "3.Empleados" << endl;
	cout << "4.Marcas" << endl;
	cout << "5.Productos" << endl;
	cout << "6.Proveedores" << endl;
	cout << "7.Compras" << endl;
}

void menuPuestos() {
	string puesto;
	int opP = 0, idpuestos = 0;
	do {
		opP = 0;
		system("cls");
		cout << "Catalogo de puestos" << endl;
		cout << "1.Ver Registro" << endl;
		cout << "2.Crear" << endl;
		cout << "3.Editar registro" << endl;
		cout << "4.Eliminar registro" << endl;
		cout << "5.Salir al menu principal" << endl;
		cin >> opP;

		if (opP == 1) {
			system("cls");
			cout << "<<<<<Ver registros>>>>>" << endl;
			Puesto Pue = Puesto();
			Pue.leer();
			system("pause");
		}
		if (opP == 2) {
			system("cls");
			cout << "<<<<<Ingresar Puesto" << endl;
			cout << "Ingresa el nombre del puesto" << endl;
			cin >> puesto;
			Puesto Pue = Puesto(idpuestos, puesto);
			Pue.crear();
			system("pause");
		}
		if (opP == 3) {

			system("cls");
			Puesto Pue1 = Puesto();
			Pue1.leer();
			
			cout << "<<<<<Editar Puesto" << endl;
			cout << "Ingresa el id del puesto" << endl;
			cin >> idpuestos;
			cout << "Ingresa el nombre del puesto" << endl;
			cin >> puesto;
			Puesto Pue = Puesto(idpuestos, puesto);
			Pue.actualizar();
			system("pause");
		}
		if (opP == 4) {

			Puesto Pue1 = Puesto();
			Pue1.leer();
			cout << "<<<<<Eliminar Puesto" << endl;
			cout << "Ingresa el Codigo del puesto a eliminar" << endl;
			cin >> idpuestos;
			Puesto Pue = Puesto(idpuestos, puesto);
			Pue.eliminar();
		}

	} while (opP != 5);
	
	system("pause");
}

void ingresoCliente() {
	char genero = {};
	string nombres, apellidos, nit, correo_electronico, fechaIngreso;
	int  telefono = 0, idcliente = 0;
	cout << "<<<<<Ingresar Cliente" << endl;
	cout << "Ingresa los nombres del Cliente" << endl;
	getline(cin,nombres);
	getline(cin, nombres);
	cout << "Ingresa los apellidos del Cliente" << endl;
	cin >> apellidos;
	cout << "Ingresa el telefono del Cliente" << endl;
	cin >> telefono;
	cout << "Ingresa el nit del Cliente" << endl;
	cin >> nit;
	cout << "Ingresa el Genero del Cliente" << endl;
	cout << "Ingresa 1.Masculino o 2.Femenino" << endl;
	cin >> genero;
	cout << "Ingresa el email del Cliente" << endl;
	cin >> correo_electronico;
	cout << "Ingresa la fecha de Ingreso del Cliente" << endl;
	cin >> fechaIngreso;
	Cliente Obj = Cliente(idcliente,nombres,apellidos,telefono,fechaIngreso,genero,nit,correo_electronico);
	Obj.crear();
}

void menuClientes() {
	char genero = {};
	string nombres, apellidos, nit, correo_electronico, fechaIngreso;
	int  telefono = 0, idcliente = 0, opC = 0;
	do {
		
		system("cls");
		cout << "Catalogo de clientes" << endl;
		cout << "1.Ver Registro" << endl;
		cout << "2.Crear" << endl;
		cout << "3.Editar registro" << endl;
		cout << "4.Eliminar registro" << endl;
		cout << "5.Salir al menu principal" << endl;
		cin >> opC;

		if (opC == 1) {
			system("cls");
			cout << "<<<<<Ver registros>>>>>" << endl;
			Cliente Obj = Cliente();
			Obj.leer();
			system("pause");
		}
		if (opC == 2) {
			system("cls");
			ingresoCliente();
			system("pause");
		}
		if (opC == 3) {
			system("cls");
			Cliente Cli1 = Cliente();
			Cli1.leer();

			cout << "<<<<<Editar Cliente" << endl;
			cout << "Ingresa el id del cliente" << endl;
			cin >> idcliente;
			cin.ignore();
			cout << "Ingresa los nombres del Cliente" << endl;
			
			getline(cin, nombres);
			cout << "Ingresa los apellidos del Cliente" << endl;
			cin >> apellidos;
			cout << "Ingresa el telefono del Cliente" << endl;
			cin >> telefono;
			cout << "Ingresa el nit del Cliente" << endl;
			cin >> nit;
			cout << "Ingresa el Genero del Cliente" << endl;
			cout << "Ingresa 1.Masculino o 2.Femenino" << endl;
			cin >> genero;
			cout << "Ingresa el email del Cliente" << endl;
			cin >> correo_electronico;
			cout << "Ingresa la fecha de Ingreso del Cliente" << endl;
			cin >> fechaIngreso;
			Cliente Obj = Cliente(idcliente, nombres, apellidos, telefono, fechaIngreso, genero, nit, correo_electronico);
			Obj.actualizar();

			system("pause");
		}
		if (opC == 4) {
			system("cls");
			Cliente cl = Cliente();
			cl.leer();
			cout << "<<<<<Eliminar Puesto" << endl;
			cout << "Ingresa el Codigo del puesto a eliminar" << endl;
			cin >> idcliente;
			Cliente Obj = Cliente(idcliente, nombres, apellidos, telefono, fechaIngreso, genero, nit, correo_electronico);
			Obj.eliminar();
		}

	} while (opC != 5);

	system("pause");
}

void menuEmpleados() {
	char genero = {};
	string nombres, apellidos,direccion, DPI, fecha_nacimiento,fecha_inicio_labores, fechaIngreso;
	int  telefono = 0, idempleado = 0, opC = 0, puestos = 0;
	do {

		system("cls");
		cout << "Catalogo de Empleados" << endl;
		cout << "1.Ver Registro" << endl;
		cout << "2.Crear" << endl;
		cout << "3.Editar registro" << endl;
		cout << "4.Eliminar registro" << endl;
		cout << "5.Salir al menu principal" << endl;
		cin >> opC;

		if (opC == 1) {
			system("cls");
			cout << "<<<<<Ver registros>>>>>" << endl;
			Empleado Obj = Empleado();
			Obj.leer();
			system("pause");
		}
		if (opC == 2) {
			system("cls");

			cout << "<<<<<Ingresar Empleados" << endl;
			cout << "Ingresa los nombres del Empleado" << endl;
			getline(cin, nombres);
			getline(cin, nombres);
			cout << "Ingresa los apellidos del Empleado" << endl;
			cin >> apellidos;
			cout << "Ingresa el telefono del Empleado" << endl;
			cin >> telefono;
			cout << "Ingresa el nit del Empleado" << endl;
			cin >> DPI;
			cout << "Ingresa el Genero del Empleado" << endl;
			cout << "Ingresa 1.Masculino o 2.Femenino" << endl;
			cin >> genero;
			cout << "Ingresa la fecha de Nacimiento del Empleado" << endl;
			cin >> fecha_nacimiento;
			cout << "Ingresa la fecha de Inicio de labores del Empleado" << endl;
			cin >> fecha_inicio_labores;
			cout << "Ingresa la fecha de Ingreso del Empleado" << endl;
			cin >> fechaIngreso;

			Puesto p = Puesto();
			p.leer();

			cout << "Ingresa el Puesto" << endl;
			cin >> puestos;
			Empleado Obj = Empleado(idempleado, nombres, apellidos, telefono, fechaIngreso, genero, direccion,DPI,fecha_nacimiento,fecha_inicio_labores,puestos);
			Obj.crear();

			system("pause");

		}
		if (opC == 3) {
			system("cls");
			Empleado Cli1 = Empleado();
			Cli1.leer();

			cout << "<<<<<Editar Empleado" << endl;
			cout << "Ingresa el id: " << endl;
			cin >> idempleado;
			cout << "Ingresa los nombres del Cliente" << endl;
			getline(cin, nombres);
			getline(cin, nombres);
			cout << "Ingresa los apellidos del Empleado" << endl;
			cin >> apellidos;
			cout << "Ingresa el telefono del Empleado" << endl;
			cin >> telefono;
			cout << "Ingresa el nit del Empleado" << endl;
			cin >> DPI;
			cout << "Ingresa el Genero del Empleado" << endl;
			cout << "Ingresa 1.Masculino o 2.Femenino" << endl;
			cin >> genero;
			cout << "Ingresa la fecha de Nacimiento del Empleado" << endl;
			cin >> fecha_nacimiento;
			cout << "Ingresa la fecha de Inicio de labores del Empleado" << endl;
			cin >> fecha_inicio_labores;
			cout << "Ingresa la fecha de Ingreso del Empleado" << endl;
			cin >> fechaIngreso;
			Puesto p = Puesto();
			p.leer();

			cout << "Ingresa el Puesto" << endl;
			cin >> puestos;

			Empleado Obj = Empleado(idempleado, nombres, apellidos, telefono, fechaIngreso, genero, direccion, DPI, fecha_nacimiento, fecha_inicio_labores, puestos);
			Obj.actualizar();

			system("pause");
		}
		if (opC == 4) {
			system("cls");
			Empleado cl = Empleado();
			cl.leer();
			cout << "<<<<<Eliminar Puesto" << endl;
			cout << "Ingresa el Codigo del puesto a eliminar" << endl;
			cin >> idempleado;
			Empleado Obj = Empleado(idempleado, nombres, apellidos, telefono, fechaIngreso, genero, direccion, DPI, fecha_nacimiento, fecha_inicio_labores, puestos);
			Obj.eliminar();
		}

	} while (opC != 5);

	system("pause");
}

void menuMarcas(){
	string marcas;
	int opM = 0, idMarcas = 0;
	do {
		opM = 0;
		system("cls");
		cout << "Catalogo de Marcas" << endl;
		cout << "1.Ver Registro" << endl;
		cout << "2.Crear" << endl;
		cout << "3.Editar registro" << endl;
		cout << "4.Eliminar registro" << endl;
		cout << "5.Salir al menu principal" << endl;
		cin >> opM;

		if (opM == 1) {
			system("cls");
			cout << "<<<<<Ver registros>>>>>" << endl;
			 Marca Obj = Marca();
			 Obj.leer();
			system("pause");
		}
		if (opM == 2) {
			system("cls");
			cout << "<<<<<Ingresar Marca" << endl;
			cout << "Ingresa el nombre de la marca" << endl;
			cin >> marcas;
			Marca Obj = Marca(idMarcas, marcas);
			Obj.crear();
			system("pause");
		}
		if (opM == 3) {

			system("cls");
			Marca Obj1 = Marca();
			Obj1.leer();

			cout << "<<<<<Editar Marca" << endl;
			cout << "Ingresa el id de la marca" << endl;
			cin >> idMarcas;
			cout << "Ingresa el nombre de la marca" << endl;
			cin >> marcas;
			Marca Obj = Marca(idMarcas, marcas);
			Obj.actualizar();
			system("pause");
		}
		if (opM == 4) {

			Marca Obj1 = Marca();
			Obj1.leer();
			cout << "<<<<<Eliminar Marca" << endl;
			cout << "Ingresa el Marca del puesto a eliminar" << endl;
			cin >> idMarcas;
			Marca Obj = Marca(idMarcas, marcas);
			Obj.eliminar();
		}

	} while (opM != 5);

	system("pause");
}

void menuProductos(){
	string producto, descripcion, fecha_ingreso;
	int idMarca = 0, idProducto = 0, existencia = 0, opP = 0;
	float precio_costo = 0.0, precio_venta = 0.0;

	do {
		opP = 0;
		system("cls");
		cout << "Catalogo de productos" << endl;
		cout << "1.Ver Registro" << endl;
		cout << "2.Crear" << endl;
		cout << "3.Editar registro" << endl;
		cout << "4.Eliminar registro" << endl;
		cout << "5.Salir al menu principal" << endl;
		cin >> opP;

		if (opP == 1) {
			system("cls");
			cout << "<<<<<Ver registros>>>>>" << endl;
			Productos Obj = Productos();
			Obj.leer();
			system("pause");
		}
		if (opP == 2) {
			system("cls");
			cout << "<<<<<Ingresar Producto" << endl;
			cout << "Ingresa el nombre del Producto" << endl;
			cin >> producto;
			cout << "Ingresa Descripcion del Producto" << endl;
			cin >> descripcion;

			Productos Obj1 = Productos();
			Obj1.leer();

			cout << "ingresa el id de la marca del Producto" << endl;
			cin >> idMarca;
			cout << "Ingresa la fecha de ingreso año/mes/dia del Producto" << endl;
			cin >> fecha_ingreso;
			cout << "ingresa el precio costo del Producto" << endl;
			cin >> precio_costo;
			cout << "ingresa el precio venta del Producto" << endl;
			cin >> precio_venta;
			cout << "ingresa la existencia del Producto" << endl;
			cin >> existencia;


			Productos Obj = Productos(idProducto,producto,descripcion,fecha_ingreso,idMarca,existencia,precio_costo,precio_venta);
			Obj.crear();
			system("pause");
		}
		if (opP == 3) {

			/*system("cls");
			Puesto Obj = Puesto();
			Obj.leer();

			cout << "<<<<<Editar Puesto" << endl;
			cout << "Ingresa el id del puesto" << endl;
			cin >> idpuestos;
			cout << "Ingresa el nombre del puesto" << endl;
			cin >> puesto;
			Puesto Obj = Puesto(idpuestos, puesto);
			Obj.actualizar();
			system("pause");*/
		}
		if (opP == 4) {

		/*	Puesto Obj = Puesto();
			Obj.leer();
			cout << "<<<<<Eliminar Puesto" << endl;
			cout << "Ingresa el Codigo del puesto a eliminar" << endl;
			cin >> idpuestos;
			Puesto Obj = Puesto(idpuestos, puesto);
			Obj.eliminar();*/
		}

	} while (opP != 5);

	system("pause");

}

void menuProveedores(){}

int main()
{
	int op = 0, opA = 0, opO = 0;

	do {
		system("cls");
		menuPrincipal();
		cin >> op;
		switch (op)
		{
			case 1:
				system("cls");
				menuAdministracion();
				cin >> opA;

					switch (opA)
					{
						case 1:
							menuPuestos();
						break;
						case 2:
							menuClientes();
							break;
						case 3:
							menuEmpleados();
							break;
						case 4:
							menuMarcas();
							break;
						case 5:
							menuProductos();
							break;
						case 6:
							menuProveedores();
							break;




						default:
						break;
					};
			break;

		case 2:
			system("cls");
			cout << "Bienvendio al menu de operador" << endl;
			switch (opO)
			{
			default:
				break;
			}

			system("pause");
			break;
		default:
			break;
		}
			


			

	

			
			
	} while (op != 3);

	

}

