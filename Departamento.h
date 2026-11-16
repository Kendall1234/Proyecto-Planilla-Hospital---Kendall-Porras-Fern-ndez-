#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "ListaEmpleados.h"
using namespace std;

class Departamento {
	
private:
	string *idDepartamento;
	string *nombre;
	string *ubicacion;
	ListaEmpleados *empleados;
	
public:
	Departamento();
	Departamento(string *idDepartamento, string *nombre, string *ubicacion);
	~Departamento();
	
	void setIdDepartamento(string *idDepartamento);
	string getIdDepartamento();
	
	void setNombre(string *nombre);
	string getNombre();
	
	void setUbicacion(string *ubicacion);
	string getUbicacion();
	
	void agregarEmpleado(Empleado *emp);
	ListaEmpleados* getEmpleados();
	
	string toString();
	
	void autoGuardar(ofstream& estFile);
	static Departamento* autoLeer(ifstream& estFile);
};

#endif
