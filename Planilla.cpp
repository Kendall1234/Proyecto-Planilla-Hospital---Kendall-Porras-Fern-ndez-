#include "Planilla.h"

Planilla::Planilla() {
	this->idPlanilla = new string("");
	this->periodo = new string("");
	this->fechaGeneracion = new string("");
	this->comprobantes = new ListaComprobantes();
	this->totalBruto = new double(0.0);
	this->totalDeducciones = new double(0.0);
	this->totalNeto = new double(0.0);
	this->cerrada = new bool(false);
}

Planilla::Planilla(string* idPlanilla, string* periodo, string* fechaGeneracion) {
	this->idPlanilla = new string(*idPlanilla);
	this->periodo = new string(*periodo);
	this->fechaGeneracion = new string(*fechaGeneracion);
	this->comprobantes = new ListaComprobantes();
	this->totalBruto = new double(0.0);
	this->totalDeducciones = new double(0.0);
	this->totalNeto = new double(0.0);
	this->cerrada = new bool(false);
}

Planilla::~Planilla() {
	delete idPlanilla;
	delete periodo;
	delete fechaGeneracion;
	delete comprobantes; // Composicion: Planilla destruye su ListaComprobantes
	delete totalBruto;
	delete totalDeducciones;
	delete totalNeto;
	delete cerrada;
}

void Planilla::setIdPlanilla(string* idPlanilla) {
	*this->idPlanilla = *idPlanilla;
}

string Planilla::getIdPlanilla() {
	return *idPlanilla;
}

void Planilla::setPeriodo(string* periodo) {
	*this->periodo = *periodo;
}

string Planilla::getPeriodo() {
	return *periodo;
}

void Planilla::setFechaGeneracion(string* fechaGeneracion) {
	*this->fechaGeneracion = *fechaGeneracion;
}

string Planilla::getFechaGeneracion() {
	return *fechaGeneracion;
}

ListaComprobantes* Planilla::getComprobantes() {
	return comprobantes;
}

double Planilla::getTotalBruto() {
	return *totalBruto;
}

double Planilla::getTotalDeducciones() {
	return *totalDeducciones;
}

double Planilla::getTotalNeto() {
	return *totalNeto;
}

void Planilla::setCerrada(bool* cerrada) {
	*this->cerrada = *cerrada;
}

bool Planilla::getCerrada() {
	return *cerrada;
}

void Planilla::agregarComprobante(ComprobantePlanilla* comprobante) {
	if (!(*cerrada) && comprobante != NULL) {
		comprobantes->insertarComprobante(comprobante);
		actualizarTotales();
	}
}

void Planilla::actualizarTotales() {
	*totalBruto = comprobantes->calcularTotalBruto();
	*totalDeducciones = comprobantes->calcularTotalDeducciones();
	*totalNeto = comprobantes->calcularTotalNeto();
}

void Planilla::cerrarPlanilla() {
	*cerrada = true;
	NodoComprobante* nodo = comprobantes->getCabeza();
	while (nodo != NULL) {
		nodo->getDato()->procesarPago();
		nodo = nodo->getSig();
	}
}

string Planilla::toString() {
	stringstream ss;
	ss << fixed << setprecision(2);
	ss << "========================================\n";
	ss << "PLANILLA ID: " << *idPlanilla << "\n";
	ss << "Periodo: " << *periodo << "\n";
	ss << "Fecha de Generacion: " << *fechaGeneracion << "\n";
	ss << "Estado: " << (*cerrada ? "CERRADA" : "ABIERTA") << "\n";
	ss << "Cantidad de Comprobantes: " << comprobantes->contar() << "\n";
	ss << "Total Salarios Brutos: " << *totalBruto << "\n";
	ss << "Total Deducciones: -" << *totalDeducciones << "\n";
	ss << "Total Salarios Netos: " << *totalNeto << "\n";
	ss << "========================================\n";
	ss << "DETALLE DE COMPROBANTES:\n";
	ss << comprobantes->listarComprobantes();
	return ss.str();
}
