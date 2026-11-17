#include "ComprobantePlanilla.h"

ComprobantePlanilla::ComprobantePlanilla() {
	this->idComprobante = new string("");
	this->fechaPago = new string("");
	this->empleado = NULL;
	this->salarioBruto = new double(0.0);
	this->deduccionCCSS = new double(0.0);
	this->impuestoRenta = new double(0.0);
	this->salarioNeto = new double(0.0);
	this->pagado = new bool(false);
}

ComprobantePlanilla::ComprobantePlanilla(string* idComprobante, string* fechaPago, Empleado* empleado) {
	this->idComprobante = new string(*idComprobante);
	this->fechaPago = new string(*fechaPago);
	this->empleado = empleado;
	this->salarioBruto = new double(0.0);
	this->deduccionCCSS = new double(0.0);
	this->impuestoRenta = new double(0.0);
	this->salarioNeto = new double(0.0);
	this->pagado = new bool(false);
	
	calcularMontos();
}

ComprobantePlanilla::~ComprobantePlanilla() {
	delete idComprobante;
	delete fechaPago;
	// No se borra empleado porque la relacion es de asociacion
	delete salarioBruto;
	delete deduccionCCSS;
	delete impuestoRenta;
	delete salarioNeto;
	delete pagado;
}

void ComprobantePlanilla::setIdComprobante(string* idComprobante) {
	*this->idComprobante = *idComprobante;
}

string ComprobantePlanilla::getIdComprobante() {
	return *idComprobante;
}

void ComprobantePlanilla::setFechaPago(string* fechaPago) {
	*this->fechaPago = *fechaPago;
}

string ComprobantePlanilla::getFechaPago() {
	return *fechaPago;
}

void ComprobantePlanilla::setEmpleado(Empleado* empleado) {
	this->empleado = empleado;
	calcularMontos();
}

Empleado* ComprobantePlanilla::getEmpleado() {
	return empleado;
}

double ComprobantePlanilla::getSalarioBruto() {
	return *salarioBruto;
}

double ComprobantePlanilla::getDeduccionCCSS() {
	return *deduccionCCSS;
}

double ComprobantePlanilla::getImpuestoRenta() {
	return *impuestoRenta;
}

double ComprobantePlanilla::getSalarioNeto() {
	return *salarioNeto;
}

void ComprobantePlanilla::setPagado(bool* pagado) {
	*this->pagado = *pagado;
}

bool ComprobantePlanilla::getPagado() {
	return *pagado;
}

double ComprobantePlanilla::calcularDeduccionCCSS() {
	return (*salarioBruto) * 0.1083;
}

double ComprobantePlanilla::calcularImpuestoRenta() {
	double bruto = *salarioBruto;
	double impuesto = 0.0;
	
	if (bruto > 4727000.0) {
		impuesto += (bruto - 4727000.0) * 0.25;
		bruto = 4727000.0;
	}
	if (bruto > 2364000.0) {
		impuesto += (bruto - 2364000.0) * 0.20;
		bruto = 2364000.0;
	}
	if (bruto > 1347000.0) {
		impuesto += (bruto - 1347000.0) * 0.15;
		bruto = 1347000.0;
	}
	if (bruto > 918000.0) {
		impuesto += (bruto - 918000.0) * 0.10;
	}
	
	return impuesto;
}

void ComprobantePlanilla::calcularMontos() {
	if (empleado != NULL) {
		*salarioBruto = empleado->calcularSalarioBruto();
	} else {
		*salarioBruto = 0.0;
	}
	*deduccionCCSS = calcularDeduccionCCSS();
	*impuestoRenta = calcularImpuestoRenta();
	*salarioNeto = (*salarioBruto) - (*deduccionCCSS) - (*impuestoRenta);
}

void ComprobantePlanilla::procesarPago() {
	*pagado = true;
}

string ComprobantePlanilla::toString() {
	stringstream ss;
	ss << fixed << setprecision(2);
	ss << "Comprobante ID: " << *idComprobante << "\n";
	ss << "Fecha de Pago: " << *fechaPago << "\n";
	if (empleado != NULL) {
		ss << "Empleado: " << empleado->getNombre() << " (ID: " << empleado->getId() << ")\n";
	} else {
		ss << "Empleado: No asignado\n";
	}
	ss << "Salario Bruto: " << *salarioBruto << "\n";
	ss << "Deduccion CCSS (10.83%): -" << *deduccionCCSS << "\n";
	ss << "Impuesto de Renta: -" << *impuestoRenta << "\n";
	ss << "Salario Neto: " << *salarioNeto << "\n";
	ss << "Estado: " << (*pagado ? "PAGADO" : "PENDIENTE") << "\n";
	return ss.str();
}
