#ifndef PLANILLA_H
#define PLANILLA_H

#include "ListaComprobantes.h"

class Planilla {
private:
	string* idPlanilla;
	string* periodo;
	string* fechaGeneracion;
	ListaComprobantes* comprobantes;
	double* totalBruto;
	double* totalDeducciones;
	double* totalNeto;
	bool* cerrada;
	
public:
	Planilla();
	Planilla(string* idPlanilla, string* periodo, string* fechaGeneracion);
	virtual ~Planilla();
	
	void setIdPlanilla(string* idPlanilla);
	string getIdPlanilla();
	
	void setPeriodo(string* periodo);
	string getPeriodo();
	
	void setFechaGeneracion(string* fechaGeneracion);
	string getFechaGeneracion();
	
	ListaComprobantes* getComprobantes();
	
	double getTotalBruto();
	double getTotalDeducciones();
	double getTotalNeto();
	
	void setCerrada(bool* cerrada);
	bool getCerrada();
	
	void agregarComprobante(ComprobantePlanilla* comprobante);
	void actualizarTotales();
	void cerrarPlanilla();
	string toString();
};

#endif
