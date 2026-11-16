#include "NodoEmpleado.h"

NodoEmpleado::NodoEmpleado(Empleado *dato) {
	this->dato = dato;
	this->sig = NULL;
}

NodoEmpleado::~NodoEmpleado() {
	// No borra el dato (es Agregación)
}

void NodoEmpleado::setDato(Empleado *dato) {
	this->dato = dato;
}

Empleado* NodoEmpleado::getDato() {
	return dato;
}

void NodoEmpleado::setSig(NodoEmpleado *sig) {
	this->sig = sig;
}

NodoEmpleado* NodoEmpleado::getSig() {
	return sig;
}
