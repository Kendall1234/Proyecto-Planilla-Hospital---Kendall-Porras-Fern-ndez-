#include "Administrativo.h"

Administrativo::Administrativo() : Empleado() {
	puesto = new string();
	bonificacionFija = new double;
}

Administrativo::Administrativo(string *id, string *nombre, double *salarioBase, string *turno, double *horasExtra, string *puesto, double *bonificacionFija)
	: Empleado(id, nombre, salarioBase, turno, horasExtra) {
	this->puesto = new string(*puesto);
	this->bonificacionFija = new double(*bonificacionFija);
}

Administrativo::~Administrativo() {
	delete puesto;
	delete bonificacionFija;
}

void Administrativo::setPuesto(string *puesto) { *this->puesto = *puesto; }
string Administrativo::getPuesto() { return *puesto; }

void Administrativo::setBonificacionFija(double *bonificacionFija) { *this->bonificacionFija = *bonificacionFija; }
double Administrativo::getBonificacionFija() { return *bonificacionFija; }

double Administrativo::calcularSalarioBruto() {
	// Fórmula: Salario base + Bonificación Fija + (Horas extra * 1.5)
	double base = *salarioBase;
	double valorHora = base / 160; // Asumiendo 160 horas al mes
	double extras = (*horasExtra) * valorHora * 1.5;
	return base + *bonificacionFija + extras;
}

string Administrativo::toString() {
	stringstream ss;
	ss << "--- ADMINISTRATIVO ---" << endl;
	ss << Empleado::toString();
	ss << "Puesto: " << *puesto << endl;
	ss << "Bonificacion Fija: " << *bonificacionFija << endl;
	return ss.str();
}

void Administrativo::autoGuardar(ofstream& estFile) {
	Empleado::autoGuardar(estFile);
	estFile << *puesto << endl
		<< *bonificacionFija << endl;
}

Administrativo* Administrativo::autoLeer(ifstream& estFile) {
	string idLeido, nombreLeido, turnoLeido, puestoLeido;
	double salarioBaseLeido, horasExtraLeido, bonificacionLeida;
	
	if (!(estFile >> idLeido)) { return NULL; }
	if (!(estFile >> nombreLeido)) { return NULL; }
	if (!(estFile >> salarioBaseLeido)) { return NULL; }
	if (!(estFile >> turnoLeido)) { return NULL; }
	if (!(estFile >> horasExtraLeido)) { return NULL; }
	
	if (!(estFile >> puestoLeido)) { return NULL; }
	if (!(estFile >> bonificacionLeida)) { return NULL; }
	
	string *pId = new string(idLeido);
	string *pNombre = new string(nombreLeido);
	double *pSalario = new double(salarioBaseLeido);
	string *pTurno = new string(turnoLeido);
	double *pHoras = new double(horasExtraLeido);
	string *pPuesto = new string(puestoLeido);
	double *pBonificacion = new double(bonificacionLeida);
	
	return new Administrativo(pId, pNombre, pSalario, pTurno, pHoras, pPuesto, pBonificacion);
}
