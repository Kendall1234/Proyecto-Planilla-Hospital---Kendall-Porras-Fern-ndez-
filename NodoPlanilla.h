#ifndef NODOPLANILLA_H
#define NODOPLANILLA_H

#include "Planilla.h"

class NodoPlanilla {
private:
	Planilla* dato;
	NodoPlanilla* sig;
	
public:
	NodoPlanilla(Planilla* dato);
	virtual ~NodoPlanilla();
	
	void setDato(Planilla* dato);
	Planilla* getDato();
	
	void setSig(NodoPlanilla* sig);
	NodoPlanilla* getSig();
};

#endif
