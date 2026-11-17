#include "ListaEmpleados.h"

ListaEmpleados::ListaEmpleados() {
	cabeza = NULL;
	actual = NULL;
	cola = NULL;
}

ListaEmpleados::~ListaEmpleados() {
	actual = cabeza;
	NodoEmpleado *aux = NULL;
	while (actual != NULL) {
		aux = actual;
		actual = actual->getSig();
		delete aux;
	}
}

bool ListaEmpleados::vacio() {
	return cabeza == NULL;
}

int ListaEmpleados::contar() {
	actual = cabeza;
	int contador = 0;
	while (actual != NULL) {
		contador++;
		actual = actual->getSig();
	}
	return contador;
}

void ListaEmpleados::insertarEmpleado(Empleado* dato) {
	NodoEmpleado *aux = new NodoEmpleado(dato);
	if (vacio()) {
		cabeza = aux;
		cola = aux;
	} else {
		cola->setSig(aux);
		cola = aux;
	}
}

string ListaEmpleados::eliminarEmpleado(string id) {
	if (vacio()) {
		return "La lista esta vacia";
	}
	
	actual = cabeza;
	NodoEmpleado *aux = NULL;
	bool bandera = false;
	
	if (id == cabeza->getDato()->getId()) {
		aux = cabeza;
		cabeza = cabeza->getSig();
		if (cabeza == NULL) {
			cola = NULL;
		}
		delete aux;
		return "Empleado eliminado";
	} else {
		while (actual->getSig() != NULL) {
			if (id == actual->getSig()->getDato()->getId()) {
				aux = actual->getSig();
				actual->setSig(aux->getSig());
				if (aux == cola) {
					cola = actual;
				}
				delete aux;
				bandera = true;
				return "Empleado eliminado";
			} else {
				actual = actual->getSig();
			}
		}
		if (!bandera) {
			return "El empleado no esta en la lista";
		}
	}
	return "";
}

string ListaEmpleados::modificarEmpleado(string id, Empleado* dato) {
	if (vacio()) {
		return "La lista esta vacia";
	}
	
	actual = cabeza;
	bool bandera = false;
	
	while (actual != NULL) {
		if (id == actual->getDato()->getId()) {
			actual->setDato(dato);
			bandera = true;
			return "Empleado modificado";
		} else {
			actual = actual->getSig();
		}
	}
	if (!bandera) {
		return "Empleado no encontrado";
	}
	return "";
}

string ListaEmpleados::consultarEmpleado(string id) {
	if (vacio()) {
		return "La lista esta vacia";
	}
	
	actual = cabeza;
	bool bandera = false;
	
	while (actual != NULL) {
		if (id == actual->getDato()->getId()) {
			bandera = true;
			return actual->getDato()->toString();
		} else {
			actual = actual->getSig();
		}
	}
	if (!bandera) {
		return "Empleado no encontrado";
	}
	return "";
}

string ListaEmpleados::listarEmpleados() {
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

void ListaEmpleados::ordenarEmpleados() {
	if (vacio() || cabeza->getSig() == NULL) {
		return;
	}
	
	bool intercambio;
	do {
		intercambio = false;
		actual = cabeza;
		
		while (actual->getSig() != NULL) {
			if (actual->getDato()->getSalarioBase() > actual->getSig()->getDato()->getSalarioBase()) {
				Empleado *temp = actual->getDato();
				actual->setDato(actual->getSig()->getDato());
				actual->getSig()->setDato(temp);
				intercambio = true;
			}
			actual = actual->getSig();
		}
	} while (intercambio);
}

string ListaEmpleados::insertarPosicion(int posicion, Empleado* dato) {
	NodoEmpleado *nuevo = new NodoEmpleado(dato);
	
	if (vacio() || posicion <= 1) {
		nuevo->setSig(cabeza);
		cabeza = nuevo;
		if (cola == NULL) {
			cola = nuevo;
		}
		return "Empleado insertado al inicio";
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
	
	return "Empleado insertado en la posicion";
}

Empleado* ListaEmpleados::buscarPorId(string id) {
	actual = cabeza;
	while (actual != NULL) {
		if (actual->getDato()->getId() == id) {
			return actual->getDato();
		}
		actual = actual->getSig();
	}
	return NULL;
}

NodoEmpleado* ListaEmpleados::getCabeza() {
	return cabeza;
}
