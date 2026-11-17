#include "ListaPlanillas.h"

ListaPlanillas::ListaPlanillas() {
	cabeza = NULL;
	actual = NULL;
	cola = NULL;
}

ListaPlanillas::~ListaPlanillas() {
	actual = cabeza;
	NodoPlanilla *aux = NULL;
	while (actual != NULL) {
		aux = actual;
		actual = actual->getSig();
		delete aux->getDato(); // Composicion: destruye la planilla
		delete aux;
	}
}

bool ListaPlanillas::vacio() {
	return cabeza == NULL;
}

int ListaPlanillas::contar() {
	actual = cabeza;
	int contador = 0;
	while (actual != NULL) {
		contador++;
		actual = actual->getSig();
	}
	return contador;
}

void ListaPlanillas::insertarPlanilla(Planilla* dato) {
	NodoPlanilla *aux = new NodoPlanilla(dato);
	if (vacio()) {
		cabeza = aux;
		cola = aux;
	} else {
		cola->setSig(aux);
		cola = aux;
	}
}

Planilla* ListaPlanillas::buscarPorId(string id) {
	actual = cabeza;
	while (actual != NULL) {
		if (actual->getDato()->getIdPlanilla() == id) {
			return actual->getDato();
		}
		actual = actual->getSig();
	}
	return NULL;
}

string ListaPlanillas::eliminarPlanilla(string id) {
	if (vacio()) {
		return "La lista esta vacia";
	}
	
	actual = cabeza;
	NodoPlanilla *aux = NULL;
	bool bandera = false;
	
	if (id == cabeza->getDato()->getIdPlanilla()) {
		aux = cabeza;
		cabeza = cabeza->getSig();
		if (cabeza == NULL) {
			cola = NULL;
		}
		delete aux->getDato();
		delete aux;
		return "Planilla eliminada";
	} else {
		while (actual->getSig() != NULL) {
			if (id == actual->getSig()->getDato()->getIdPlanilla()) {
				aux = actual->getSig();
				actual->setSig(aux->getSig());
				if (aux == cola) {
					cola = actual;
				}
				delete aux->getDato();
				delete aux;
				bandera = true;
				return "Planilla eliminada";
			} else {
				actual = actual->getSig();
			}
		}
		if (!bandera) {
			return "La planilla no esta en la lista";
		}
	}
	return "";
}

string ListaPlanillas::modificarPlanilla(string id, Planilla* dato) {
	if (vacio()) {
		return "La lista esta vacia";
	}
	
	actual = cabeza;
	bool bandera = false;
	
	while (actual != NULL) {
		if (id == actual->getDato()->getIdPlanilla()) {
			delete actual->getDato();
			actual->setDato(dato);
			bandera = true;
			return "Planilla modificada";
		} else {
			actual = actual->getSig();
		}
	}
	if (!bandera) {
		return "Planilla no encontrada";
	}
	return "";
}

string ListaPlanillas::consultarPlanilla(string id) {
	if (vacio()) {
		return "La lista esta vacia";
	}
	
	actual = cabeza;
	bool bandera = false;
	
	while (actual != NULL) {
		if (id == actual->getDato()->getIdPlanilla()) {
			bandera = true;
			return actual->getDato()->toString();
		} else {
			actual = actual->getSig();
		}
	}
	if (!bandera) {
		return "Planilla no encontrada";
	}
	return "";
}

string ListaPlanillas::listarPlanillas() {
	if (vacio()) {
		return "La lista esta vacia";
	}
	
	actual = cabeza;
	string listado = "";
	
	while (actual != NULL) {
		listado += actual->getDato()->toString() + "\n";
		actual = actual->getSig();
	}
	return listado;
}

void ListaPlanillas::ordenarPlanillas() {
	if (vacio() || cabeza->getSig() == NULL) {
		return;
	}
	
	bool intercambio;
	do {
		intercambio = false;
		actual = cabeza;
		
		while (actual->getSig() != NULL) {
			if (actual->getDato()->getTotalNeto() > actual->getSig()->getDato()->getTotalNeto()) {
				Planilla *temp = actual->getDato();
				actual->setDato(actual->getSig()->getDato());
				actual->getSig()->setDato(temp);
				intercambio = true;
			}
			actual = actual->getSig();
		}
	} while (intercambio);
}

string ListaPlanillas::insertarPosicion(int posicion, Planilla* dato) {
	NodoPlanilla *nuevo = new NodoPlanilla(dato);
	
	if (vacio() || posicion <= 1) {
		nuevo->setSig(cabeza);
		cabeza = nuevo;
		if (cola == NULL) {
			cola = nuevo;
		}
		return "Planilla insertada al inicio";
	}
	
	actual = cabeza;
	int contador = 1;
	
	while (actual->getSig() != NULL && contador < posicion - 1) {
		actual = actual->getSig();
		contador++;
	}
	
	nuevo->setSig(actual->getSig());
	actual->setSig(nuevo);
	if (nuevo->getSig() == NULL) {
		cola = nuevo;
	}
	
	return "Planilla insertada en la posicion";
}

NodoPlanilla* ListaPlanillas::getCabeza() {
	return cabeza;
}
