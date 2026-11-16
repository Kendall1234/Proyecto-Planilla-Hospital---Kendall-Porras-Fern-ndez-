#ifndef LISTADEPARTAMENTOS_H
#define LISTADEPARTAMENTOS_H

#include "NodoDepartamento.h"
#include <sstream>

class ListaDepartamentos {
private:
	NodoDepartamento* cabeza;
	NodoDepartamento* actual;
	NodoDepartamento* cola;
	
public:
	ListaDepartamentos();
	virtual ~ListaDepartamentos();
	
	bool vacio();
	int contar();
	void insertarDepartamento(Departamento* dato);
	string eliminarDepartamento(string id);
	string modificarDepartamento(string id, Departamento* dato);
	string consultarDepartamento(string id);
	string listarDepartamentos();
	void ordenarDepartamentos();
	string insertarPosicion(int posicion, Departamento* dato);
	Departamento* buscarPorId(string id);
	NodoDepartamento* getCabeza();
};

#endif
