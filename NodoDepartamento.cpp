#include "NodoDepartamento.h"

NodoDepartamento::NodoDepartamento(Departamento* dato) {
	this->dato = dato;
	this->sig = NULL;
}

NodoDepartamento::~NodoDepartamento() {
	// No se borra dato porque la relacion es de agregacion
}

void NodoDepartamento::setDato(Departamento* dato) {
	this->dato = dato;
}

Departamento* NodoDepartamento::getDato() {
	return this->dato;
}

void NodoDepartamento::setSig(NodoDepartamento* sig) {
	this->sig = sig;
}

NodoDepartamento* NodoDepartamento::getSig() {
	return this->sig;
}
