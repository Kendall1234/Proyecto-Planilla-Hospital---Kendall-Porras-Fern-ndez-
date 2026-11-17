#ifndef LISTAPLANILLAS_H
#define LISTAPLANILLAS_H

#include "NodoPlanilla.h"

class ListaPlanillas {
private:
	NodoPlanilla *cabeza;
	NodoPlanilla *actual;
	NodoPlanilla *cola;
	
public:
	ListaPlanillas();
	~ListaPlanillas();
	
	bool vacio();
	int contar();
	void insertarPlanilla(Planilla* dato);
	Planilla* buscarPorId(string id);
	string eliminarPlanilla(string id);
	string modificarPlanilla(string id, Planilla* dato);
	string consultarPlanilla(string id);
	string listarPlanillas();
	void ordenarPlanillas();
	string insertarPosicion(int posicion, Planilla* dato);
	NodoPlanilla* getCabeza();
};

#endif
