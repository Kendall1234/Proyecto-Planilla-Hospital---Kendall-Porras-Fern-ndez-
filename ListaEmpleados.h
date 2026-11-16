#ifndef LISTAEMPLEADOS_H
#define LISTAEMPLEADOS_H

#include "NodoEmpleado.h"

class ListaEmpleados {
private:
	NodoEmpleado *cabeza;
	NodoEmpleado *actual;
	NodoEmpleado *cola;
	
public:
	ListaEmpleados();
	~ListaEmpleados();
	
	bool vacio();
	int contar();
	void insertarEmpleado(Empleado* dato);
	string eliminarEmpleado(string id);
	string modificarEmpleado(string id, Empleado* dato);
	string consultarEmpleado(string id);
	string listarEmpleados();
	void ordenarEmpleados();
	string insertarPosicion(int posicion, Empleado* dato);
};

#endif
