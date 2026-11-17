#include "NodoPlanilla.h"

NodoPlanilla::NodoPlanilla(Planilla* dato) {
	this->dato = dato;
	this->sig = NULL;
}

NodoPlanilla::~NodoPlanilla() {
	// No se borra dato porque el nodo solo enlaza el puntero
}

void NodoPlanilla::setDato(Planilla* dato) {
	this->dato = dato;
}

Planilla* NodoPlanilla::getDato() {
	return this->dato;
}

void NodoPlanilla::setSig(NodoPlanilla* sig) {
	this->sig = sig;
}

NodoPlanilla* NodoPlanilla::getSig() {
	return this->sig;
}
