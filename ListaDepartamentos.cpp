#include "ListaDepartamentos.h"

ListaDepartamentos::ListaDepartamentos() {
	cabeza = NULL;
	actual = NULL;
	cola = NULL;
}

ListaDepartamentos::~ListaDepartamentos() {
	while (cabeza != NULL) {
		actual = cabeza;
		cabeza = cabeza->getSig();
		delete actual;
	}
	actual = NULL;
	cola = NULL;
}

bool ListaDepartamentos::vacio() {
	return cabeza == NULL;
}

int ListaDepartamentos::contar() {
	int contador = 0;
	actual = cabeza;
	while (actual != NULL) {
		contador++;
		actual = actual->getSig();
	}
	return contador;
}

void ListaDepartamentos::insertarDepartamento(Departamento* dato) {
	NodoDepartamento* nuevo = new NodoDepartamento(dato);
	if (vacio()) {
		cabeza = nuevo;
		cola = nuevo;
	} else {
		cola->setSig(nuevo);
		cola = nuevo;
	}
}

string ListaDepartamentos::eliminarDepartamento(string id) {
	if (vacio()) {
		return "La lista de departamentos esta vacia.";
	}
	
	NodoDepartamento* anterior = NULL;
	actual = cabeza;
	
	while (actual != NULL) {
		if (actual->getDato()->getIdDepartamento() == id) {
			if (actual == cabeza) {
				cabeza = cabeza->getSig();
				if (cabeza == NULL) {
					cola = NULL;
				}
			} else {
				anterior->setSig(actual->getSig());
				if (actual == cola) {
					cola = anterior;
				}
			}
			delete actual;
			actual = NULL;
			return "Departamento eliminado correctamente.";
		}
		anterior = actual;
		actual = actual->getSig();
	}
	
	return "No se encontro un departamento con ese ID.";
}

string ListaDepartamentos::modificarDepartamento(string id, Departamento* dato) {
	actual = cabeza;
	while (actual != NULL) {
		if (actual->getDato()->getIdDepartamento() == id) {
			actual->setDato(dato);
			return "Departamento modificado correctamente.";
		}
		actual = actual->getSig();
	}
	return "No se encontro un departamento con ese ID.";
}

string ListaDepartamentos::consultarDepartamento(string id) {
	actual = cabeza;
	while (actual != NULL) {
		if (actual->getDato()->getIdDepartamento() == id) {
			return actual->getDato()->toString();
		}
		actual = actual->getSig();
	}
	return "No se encontro un departamento con ese ID.";
}

string ListaDepartamentos::listarDepartamentos() {
	if (vacio()) {
		return "No hay departamentos registrados.";
	}
	stringstream ss;
	actual = cabeza;
	while (actual != NULL) {
		ss << actual->getDato()->toString() << "\n--------------------\n";
		actual = actual->getSig();
	}
	return ss.str();
}

void ListaDepartamentos::ordenarDepartamentos() {
	if (vacio() || cabeza->getSig() == NULL) {
		return;
	}
	
	bool intercambio;
	do {
		intercambio = false;
		actual = cabeza;
		while (actual->getSig() != NULL) {
			NodoDepartamento* siguiente = actual->getSig();
			if (actual->getDato()->getNombre() > siguiente->getDato()->getNombre()) {
				Departamento* temp = actual->getDato();
				actual->setDato(siguiente->getDato());
				siguiente->setDato(temp);
				intercambio = true;
			}
			actual = actual->getSig();
		}
	} while (intercambio);
}

string ListaDepartamentos::insertarPosicion(int posicion, Departamento* dato) {
	int total = contar();
	if (posicion < 1 || posicion > total + 1) {
		return "Posicion invalida.";
	}
	
	if (posicion == total + 1) {
		insertarDepartamento(dato);
		return "Departamento insertado correctamente.";
	}
	
	NodoDepartamento* nuevo = new NodoDepartamento(dato);
	if (posicion == 1) {
		nuevo->setSig(cabeza);
		cabeza = nuevo;
		if (cola == NULL) {
			cola = nuevo;
		}
		return "Departamento insertado en la primera posicion.";
	}
	
	actual = cabeza;
	for (int i = 1; i < posicion - 1; i++) {
		actual = actual->getSig();
	}
	nuevo->setSig(actual->getSig());
	actual->setSig(nuevo);
	return "Departamento insertado correctamente.";
}

Departamento* ListaDepartamentos::buscarPorId(string id) {
	actual = cabeza;
	while (actual != NULL) {
		if (actual->getDato()->getIdDepartamento() == id) {
			return actual->getDato();
		}
		actual = actual->getSig();
	}
	return NULL;
}

NodoDepartamento* ListaDepartamentos::getCabeza() {
	return cabeza;
}
