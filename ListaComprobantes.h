#ifndef LISTACOMPROBANTES_H
#define LISTACOMPROBANTES_H

#include "NodoComprobante.h"

class ListaComprobantes {
private:
	NodoComprobante *cabeza;
	NodoComprobante *actual;
	NodoComprobante *cola;
	
public:
	ListaComprobantes();
	~ListaComprobantes();
	
	bool vacio();
	int contar();
	void insertarComprobante(ComprobantePlanilla* dato);
	string eliminarComprobante(string id);
	string modificarComprobante(string id, ComprobantePlanilla* dato);
	string consultarComprobante(string id);
	string listarComprobantes();
	void ordenarComprobantes();
	string insertarPosicion(int posicion, ComprobantePlanilla* dato);
	
	double calcularTotalBruto();
	double calcularTotalDeducciones();
	double calcularTotalNeto();
};

#endif
