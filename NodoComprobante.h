#ifndef NODOCOMPROBANTE_H
#define NODOCOMPROBANTE_H

#include "ComprobantePlanilla.h"

class NodoComprobante {
private:
	ComprobantePlanilla* dato;
	NodoComprobante* sig;
	
public:
	NodoComprobante(ComprobantePlanilla* dato);
	virtual ~NodoComprobante();
	
	void setDato(ComprobantePlanilla* dato);
	ComprobantePlanilla* getDato();
	
	void setSig(NodoComprobante* sig);
	NodoComprobante* getSig();
};

#endif
