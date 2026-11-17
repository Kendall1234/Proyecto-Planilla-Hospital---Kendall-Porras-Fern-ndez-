#include "NodoComprobante.h"

NodoComprobante::NodoComprobante(ComprobantePlanilla* dato) {
	this->dato = dato;
	this->sig = NULL;
}

NodoComprobante::~NodoComprobante() {
	// No se borra dato porque el nodo solo enlaza el puntero
}

void NodoComprobante::setDato(ComprobantePlanilla* dato) {
	this->dato = dato;
}

ComprobantePlanilla* NodoComprobante::getDato() {
	return this->dato;
}

void NodoComprobante::setSig(NodoComprobante* sig) {
	this->sig = sig;
}

NodoComprobante* NodoComprobante::getSig() {
	return this->sig;
}
