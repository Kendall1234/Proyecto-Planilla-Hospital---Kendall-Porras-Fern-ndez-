#include "Medico.h"

Medico::Medico() : Empleado() {
	especialidad = new string();
	guardiasNocturnas = new int;
}

Medico::Medico(string *id, string *nombre, double *salarioBase, string *turno, double *horasExtra, string *especialidad, int *guardiasNocturnas)
	: Empleado(id, nombre, salarioBase, turno, horasExtra) {
	
	this->especialidad = new string(*especialidad);
	this->guardiasNocturnas = new int(*guardiasNocturnas);
}

Medico::~Medico() {
	
	delete especialidad;
	delete guardiasNocturnas;
}

void Medico::setEspecialidad(string *especialidad) { *this->especialidad = *especialidad; }
string Medico::getEspecialidad() { return *especialidad; }

void Medico::setGuardiasNocturnas(int *guardiasNocturnas) { *this->guardiasNocturnas = *guardiasNocturnas; }
int Medico::getGuardiasNocturnas() { return *guardiasNocturnas; }

// Fórmula real: Salario base + (horas extra * 1.5) + (guardias * 1.5)
double Medico::calcularSalarioBruto() {
	double base = *salarioBase;
	double valorHora = base / 160; // Asumiendo 160 horas al mes
	double extras = (*horasExtra) * valorHora * 1.5; 
	double pagoGuardias = (*guardiasNocturnas) * valorHora * 1.5; 
	return base + extras + pagoGuardias;
}

string Medico::toString() {
	stringstream ss;
	ss << "--- MEDICO ---" << endl;
	ss << Empleado::toString(); // Llama al toString del padre
	ss << "Especialidad: " << *especialidad << endl;
	ss << "Guardias Nocturnas: " << *guardiasNocturnas << endl;
	return ss.str();
}

void Medico::autoGuardar(ofstream& estFile) {
	Empleado::autoGuardar(estFile); // Guarda los datos del padre
	estFile << *especialidad << endl
		<< *guardiasNocturnas << endl; // Guarda los datos extra
}

Medico* Medico::autoLeer(ifstream& estFile) {
	// Primero leemos los datos del padre
	string idLeido, nombreLeido, turnoLeido, especialidadLeido;
	double salarioBaseLeido, horasExtraLeido;
	int guardiasLeido;
	
	if (!(estFile >> idLeido)) { return NULL; }
	if (!(estFile >> nombreLeido)) { return NULL; }
	if (!(estFile >> salarioBaseLeido)) { return NULL; }
	if (!(estFile >> turnoLeido)) { return NULL; }
	if (!(estFile >> horasExtraLeido)) { return NULL; }
	
	// Luego los datos extra del médico
	if (!(estFile >> especialidadLeido)) { return NULL; }
	if (!(estFile >> guardiasLeido)) { return NULL; }
	
	// Creamos los punteros y retornamos el nuevo Medico
	string *pId = new string(idLeido);
	string *pNombre = new string(nombreLeido);
	double *pSalario = new double(salarioBaseLeido);
	string *pTurno = new string(turnoLeido);
	double *pHoras = new double(horasExtraLeido);
	string *pEspecialidad = new string(especialidadLeido);
	int *pGuardias = new int(guardiasLeido);
	
	return new Medico(pId, pNombre, pSalario, pTurno, pHoras, pEspecialidad, pGuardias);
}
