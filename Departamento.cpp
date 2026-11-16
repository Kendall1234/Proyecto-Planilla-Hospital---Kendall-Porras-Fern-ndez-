#include "Departamento.h"

Departamento::Departamento() {
	idDepartamento = new string();
	nombre = new string();
	ubicacion = new string();
	empleados = new ListaEmpleados();
}

Departamento::Departamento(string *idDepartamento, string *nombre, string *ubicacion) {
	this->idDepartamento = new string(*idDepartamento);
	this->nombre = new string(*nombre);
	this->ubicacion = new string(*ubicacion);
	this->empleados = new ListaEmpleados();
}

Departamento::~Departamento() {
	delete idDepartamento;
	delete nombre;
	delete ubicacion;
	delete empleados; // Libera los nodos de la lista interna, pero NO los objetos Empleado (Agregación)
}

void Departamento::setIdDepartamento(string *idDepartamento) {
	*this->idDepartamento = *idDepartamento;
}

string Departamento::getIdDepartamento() {
	return *idDepartamento;
}

void Departamento::setNombre(string *nombre) {
	*this->nombre = *nombre;
}

string Departamento::getNombre() {
	return *nombre;
}

void Departamento::setUbicacion(string *ubicacion) {
	*this->ubicacion = *ubicacion;
}

string Departamento::getUbicacion() {
	return *ubicacion;
}

void Departamento::agregarEmpleado(Empleado *emp) {
	if (emp != NULL) {
		empleados->insertarEmpleado(emp);
	}
}

ListaEmpleados* Departamento::getEmpleados() {
	return empleados;
}

string Departamento::toString() {
	stringstream ss;
	ss << "--- DEPARTAMENTO ---" << endl;
	ss << "ID Departamento: " << *idDepartamento << endl;
	ss << "Nombre: " << *nombre << endl;
	ss << "Ubicacion: " << *ubicacion << endl;
	ss << "Cantidad de Empleados: " << empleados->contar() << endl;
	if (!empleados->vacio()) {
		ss << "Empleados asignados:" << endl;
		ss << empleados->listarEmpleados();
	}
	return ss.str();
}

void Departamento::autoGuardar(ofstream& estFile) {
	estFile << *idDepartamento << endl
		<< *nombre << endl
		<< *ubicacion << endl;
}

Departamento* Departamento::autoLeer(ifstream& estFile) {
	string idLeido, nombreLeido, ubicacionLeida;
	
	if (!(estFile >> idLeido)) { return NULL; }
	if (!(estFile >> nombreLeido)) { return NULL; }
	if (!(estFile >> ubicacionLeida)) { return NULL; }
	
	string *pId = new string(idLeido);
	string *pNombre = new string(nombreLeido);
	string *pUbicacion = new string(ubicacionLeida);
	
	Departamento *dep = new Departamento(pId, pNombre, pUbicacion);
	
	delete pId;
	delete pNombre;
	delete pUbicacion;
	
	return dep;
}
