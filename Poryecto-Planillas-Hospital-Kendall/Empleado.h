#ifndef EMPLEADO_H
#define EMPLEADO_H

#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

class Empleado {
	
protected:
	string *id;
	string *nombre;
	double *salarioBase;
	string *turno;
	double *horasExtra;
	
public:
	Empleado();
	Empleado(string *id, string *nombre, double *salarioBase, string *turno, double *horasExtra);
	virtual ~Empleado();
	
	void setId(string *id);
	string getId();
	
	void setNombre(string *nombre);
	string getNombre();
	
	void setSalarioBase(double *salarioBase);
	double getSalarioBase();
	
	void setTurno(string *turno);
	string getTurno();
	
	void setHorasExtra(double *horasExtra);
	double getHorasExtra();
	
	virtual double calcularSalarioBruto() = 0;
	virtual double calcularSalarioNeto();
	
	virtual string toString();
	
	virtual void autoGuardar(ofstream& estFile);
	static Empleado* autoLeer(ifstream& estFile);
};

#endif
