#include "Empleado.h"

Empleado::Empleado() {
	
	id = new string();
	nombre = new string();
	salarioBase = new double;
	turno = new string();
	horasExtra = new double;
}

Empleado::Empleado(string *id, string *nombre, double *salarioBase, string *turno, double *horasExtra) {
	
	this->id = new string(*id);
	this->nombre = new string(*nombre);
	this->salarioBase = new double(*salarioBase);
	this->turno = new string(*turno);
	this->horasExtra = new double(*horasExtra);
}

Empleado::~Empleado() {
	
	delete id;
	delete nombre;
	delete salarioBase;
	delete turno;
	delete horasExtra;
}

void Empleado::setId(string *id) { *this->id = *id; }
string Empleado::getId() { return *id; }

void Empleado::setNombre(string *nombre) { *this->nombre = *nombre; }
string Empleado::getNombre() { return *nombre; }

void Empleado::setSalarioBase(double *salarioBase) { *this->salarioBase = *salarioBase; }
double Empleado::getSalarioBase() { return *salarioBase; }

void Empleado::setTurno(string *turno) { *this->turno = *turno; }
string Empleado::getTurno() { return *turno; }

void Empleado::setHorasExtra(double *horasExtra) { *this->horasExtra = *horasExtra; }
double Empleado::getHorasExtra() { return *horasExtra; }

// Cálculo del Salario Neto con deducciones reales (CCSS 10.83% + Renta)
double Empleado::calcularSalarioNeto() {
	double bruto = calcularSalarioBruto();
	double cargasSociales = bruto * 0.1083; // 10.83% CCSS
	double temp = bruto;
	double impuestoRenta = 0.0;
	
	if (temp > 4727000.0) {
		impuestoRenta += (temp - 4727000.0) * 0.25;
		temp = 4727000.0;
	}
	if (temp > 2364000.0) {
		impuestoRenta += (temp - 2364000.0) * 0.20;
		temp = 2364000.0;
	}
	if (temp > 1347000.0) {
		impuestoRenta += (temp - 1347000.0) * 0.15;
		temp = 1347000.0;
	}
	if (temp > 918000.0) {
		impuestoRenta += (temp - 918000.0) * 0.10;
	}
	
	return bruto - cargasSociales - impuestoRenta;
}

string Empleado::toString() {
	
	stringstream ss;
	
	ss << "ID: " << *id << endl;
	ss << "Nombre: " << *nombre << endl;
	ss << "Salario Base: " << *salarioBase << endl;
	ss << "Turno: " << *turno << endl;
	ss << "Horas Extra: " << *horasExtra << endl;
	
	return ss.str();
}

void Empleado::autoGuardar(ofstream& estFile) {
	
	estFile << *id << endl
		<< *nombre << endl
		<< *salarioBase << endl
		<< *turno << endl
		<< *horasExtra << endl;
	
}

Empleado* Empleado::autoLeer(ifstream& estFile) {
	
	string idLeido, nombreLeido, turnoLeido;
	double salarioBaseLeido, horasExtraLeido;
	
	if (!(estFile >> idLeido)) { return NULL; }
	if (!(estFile >> nombreLeido)) { return NULL; }
	if (!(estFile >> salarioBaseLeido)) { return NULL; }
	if (!(estFile >> turnoLeido)) { return NULL; }
	if (!(estFile >> horasExtraLeido)) { return NULL; }
	
	
	return NULL; 
}
