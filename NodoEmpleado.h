#ifndef NODOEMPLEADO_H
#define NODOEMPLEADO_H

#include "Empleado.h"

class NodoEmpleado {
	
private:
	Empleado *dato;
	NodoEmpleado *sig;
	
public:
	NodoEmpleado(Empleado *dato);
	virtual ~NodoEmpleado();
	
	void setDato(Empleado *dato);
	Empleado* getDato();
	
	void setSig(NodoEmpleado *sig);
	NodoEmpleado* getSig();
};

#endif
