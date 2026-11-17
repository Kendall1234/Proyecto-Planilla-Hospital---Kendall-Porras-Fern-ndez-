#ifndef COMPROBANTEPLANILLA_H
#define COMPROBANTEPLANILLA_H

#include "Empleado.h"
#include <sstream>
#include <iomanip>

class ComprobantePlanilla {
private:
	string *idComprobante;
	string *fechaPago;
	Empleado *empleado;
	double *salarioBruto;
	double *deduccionCCSS;
	double *impuestoRenta;
	double *salarioNeto;
	bool *pagado;
	
public:
	ComprobantePlanilla();
	ComprobantePlanilla(string* idComprobante, string* fechaPago, Empleado* empleado);
	virtual ~ComprobantePlanilla();
	
	void setIdComprobante(string* idComprobante);
	string getIdComprobante();
	
	void setFechaPago(string* fechaPago);
	string getFechaPago();
	
	void setEmpleado(Empleado* empleado);
	Empleado* getEmpleado();
	
	double getSalarioBruto();
	double getDeduccionCCSS();
	double getImpuestoRenta();
	double getSalarioNeto();
	
	void setPagado(bool* pagado);
	bool getPagado();
	
	double calcularDeduccionCCSS();
	double calcularImpuestoRenta();
	void calcularMontos();
	void procesarPago();
	string toString();
};

#endif
