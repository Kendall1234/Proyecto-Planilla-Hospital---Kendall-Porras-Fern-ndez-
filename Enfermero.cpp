#include "Enfermero.h"

Enfermero::Enfermero() : Empleado() {
	areaAsignada = new string();
	turnosNocturnos = new int;
}

Enfermero::Enfermero(string *id, string *nombre, double *salarioBase, string *turno, double *horasExtra, string *areaAsignada, int *turnosNocturnos)
	: Empleado(id, nombre, salarioBase, turno, horasExtra) {
	
	this->areaAsignada = new string(*areaAsignada);
	this->turnosNocturnos = new int(*turnosNocturnos);
}

Enfermero::~Enfermero() {
	
	delete areaAsignada;
	delete turnosNocturnos;
}

void Enfermero::setAreaAsignada(string *areaAsignada) { *this->areaAsignada = *areaAsignada; }
string Enfermero::getAreaAsignada() { return *areaAsignada; }

void Enfermero::setTurnosNocturnos(int *turnosNocturnos) { *this->turnosNocturnos = *turnosNocturnos; }
int Enfermero::getTurnosNocturnos() { return *turnosNocturnos; }

double Enfermero::calcularSalarioBruto() {
	// Fórmula: Salario base + (horas extra * 1.5) + (turnos nocturnos * 33% de recargo)
	double base = *salarioBase;
	double valorHora = base / 160; // Asumiendo 160 horas al mes
	double extras = (*horasExtra) * valorHora * 1.5;
	double pagoTurnos = (*turnosNocturnos) * valorHora * 1.33; // 33% de recargo (CCSS)
	return base + extras + pagoTurnos;
}

string Enfermero::toString() {
	stringstream ss;
	ss << "--- ENFERMERO ---" << endl;
	ss << Empleado::toString();
	ss << "Area Asignada: " << *areaAsignada << endl;
	ss << "Turnos Nocturnos: " << *turnosNocturnos << endl;
	return ss.str();
}

void Enfermero::autoGuardar(ofstream& estFile) {
	Empleado::autoGuardar(estFile);
	estFile << *areaAsignada << endl
		<< *turnosNocturnos << endl;
}

Enfermero* Enfermero::autoLeer(ifstream& estFile) {
	string idLeido, nombreLeido, turnoLeido, areaLeida;
	double salarioBaseLeido, horasExtraLeido;
	int turnosLeidos;
	
	if (!(estFile >> idLeido)) { return NULL; }
	if (!(estFile >> nombreLeido)) { return NULL; }
	if (!(estFile >> salarioBaseLeido)) { return NULL; }
	if (!(estFile >> turnoLeido)) { return NULL; }
	if (!(estFile >> horasExtraLeido)) { return NULL; }
	
	if (!(estFile >> areaLeida)) { return NULL; }
	if (!(estFile >> turnosLeidos)) { return NULL; }
	
	string *pId = new string(idLeido);
	string *pNombre = new string(nombreLeido);
	double *pSalario = new double(salarioBaseLeido);
	string *pTurno = new string(turnoLeido);
	double *pHoras = new double(horasExtraLeido);
	string *pArea = new string(areaLeida);
	int *pTurnos = new int(turnosLeidos);
	
	Enfermero* enf = new Enfermero(pId, pNombre, pSalario, pTurno, pHoras, pArea, pTurnos);
	
	delete pId;
	delete pNombre;
	delete pSalario;
	delete pTurno;
	delete pHoras;
	delete pArea;
	delete pTurnos;
	
	return enf;
}
