#ifndef NODODEPARTAMENTO_H
#define NODODEPARTAMENTO_H

#include "Departamento.h"

class NodoDepartamento {
	
private:
	Departamento* dato;
	NodoDepartamento* sig;
	
public:
	NodoDepartamento(Departamento* dato);
	virtual ~NodoDepartamento();
	
	void setDato(Departamento* dato);
	Departamento* getDato();
	
	void setSig(NodoDepartamento* sig);
	NodoDepartamento* getSig();
};

#endif
