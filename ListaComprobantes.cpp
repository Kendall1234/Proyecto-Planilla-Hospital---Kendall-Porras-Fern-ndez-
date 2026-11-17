#include "ListaComprobantes.h"

ListaComprobantes::ListaComprobantes() {
	cabeza = NULL;
	actual = NULL;
	cola = NULL;
}

ListaComprobantes::~ListaComprobantes() {
	actual = cabeza;
	NodoComprobante *aux = NULL;
	while (actual != NULL) {
		aux = actual;
		actual = actual->getSig();
		delete aux->getDato();
		delete aux;
	}
}

bool ListaComprobantes::vacio() {
	return cabeza == NULL;
}

int ListaComprobantes::contar() {
	actual = cabeza;
	int contador = 0;
	while (actual != NULL) {
		contador++;
		actual = actual->getSig();
	}
	return contador;
}

void ListaComprobantes::insertarComprobante(ComprobantePlanilla* dato) {
	NodoComprobante *aux = new NodoComprobante(dato);
	if (vacio()) {
		cabeza = aux;
		cola = aux;
	} else {
		cola->setSig(aux);
		cola = aux;
	}
}

string ListaComprobantes::eliminarComprobante(string id) {
	if (vacio()) {
		return "La lista esta vacia";
	}
	
	actual = cabeza;
	NodoComprobante *aux = NULL;
	bool bandera = false;
	
	if (id == cabeza->getDato()->getIdComprobante()) {
		aux = cabeza;
		cabeza = cabeza->getSig();
		if (cabeza == NULL) {
			cola = NULL;
		}
		delete aux->getDato();
		delete aux;
		return "Comprobante eliminado";
	} else {
		while (actual->getSig() != NULL) {
			if (id == actual->getSig()->getDato()->getIdComprobante()) {
				aux = actual->getSig();
				actual->setSig(aux->getSig());
				if (aux == cola) {
					cola = actual;
				}
				delete aux->getDato();
				delete aux;
				bandera = true;
				return "Comprobante eliminado";
			} else {
				actual = actual->getSig();
			}
		}
		if (!bandera) {
			return "El comprobante no esta en la lista";
		}
	}
	return "";
}

string ListaComprobantes::modificarComprobante(string id, ComprobantePlanilla* dato) {
	if (vacio()) {
		return "La lista esta vacia";
	}
	
	actual = cabeza;
	bool bandera = false;
	
	while (actual != NULL) {
		if (id == actual->getDato()->getIdComprobante()) {
			delete actual->getDato();
			actual->setDato(dato);
			bandera = true;
			return "Comprobante modificado";
		} else {
			actual = actual->getSig();
		}
	}
	if (!bandera) {
		return "Comprobante no encontrado";
	}
	return "";
}

string ListaComprobantes::consultarComprobante(string id) {
	if (vacio()) {
		return "La lista esta vacia";
	}
	
	actual = cabeza;
	bool bandera = false;
	
	while (actual != NULL) {
		if (id == actual->getDato()->getIdComprobante()) {
			bandera = true;
			return actual->getDato()->toString();
		} else {
			actual = actual->getSig();
		}
	}
	if (!bandera) {
		return "Comprobante no encontrado";
	}
	return "";
}

string ListaComprobantes::listarComprobantes() {
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

void ListaComprobantes::ordenarComprobantes() {
	if (vacio() || cabeza->getSig() == NULL) {
		return;
	}
	
	bool intercambio;
	do {
		intercambio = false;
		actual = cabeza;
		
		while (actual->getSig() != NULL) {
			if (actual->getDato()->getSalarioNeto() > actual->getSig()->getDato()->getSalarioNeto()) {
				ComprobantePlanilla *temp = actual->getDato();
				actual->setDato(actual->getSig()->getDato());
				actual->getSig()->setDato(temp);
				intercambio = true;
			}
			actual = actual->getSig();
		}
	} while (intercambio);
}

string ListaComprobantes::insertarPosicion(int posicion, ComprobantePlanilla* dato) {
	NodoComprobante *nuevo = new NodoComprobante(dato);
	
	if (vacio() || posicion <= 1) {
		nuevo->setSig(cabeza);
		cabeza = nuevo;
		if (cola == NULL) {
			cola = nuevo;
		}
		return "Comprobante insertado al inicio";
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
	
	return "Comprobante insertado en la posicion";
}

double ListaComprobantes::calcularTotalBruto() {
	actual = cabeza;
	double total = 0.0;
	while (actual != NULL) {
		total += actual->getDato()->getSalarioBruto();
		actual = actual->getSig();
	}
	return total;
}

double ListaComprobantes::calcularTotalDeducciones() {
	actual = cabeza;
	double total = 0.0;
	while (actual != NULL) {
		total += (actual->getDato()->getDeduccionCCSS() + actual->getDato()->getImpuestoRenta());
		actual = actual->getSig();
	}
	return total;
}

double ListaComprobantes::calcularTotalNeto() {
	actual = cabeza;
	double total = 0.0;
	while (actual != NULL) {
		total += actual->getDato()->getSalarioNeto();
		actual = actual->getSig();
	}
	return total;
}

NodoComprobante* ListaComprobantes::getCabeza() {
	return cabeza;
}
