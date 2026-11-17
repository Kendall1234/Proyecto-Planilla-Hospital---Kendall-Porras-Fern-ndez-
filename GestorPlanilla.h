#ifndef GESTORPLANILLA_H
#define GESTORPLANILLA_H

#include "ListaDepartamentos.h"
#include "ListaEmpleados.h"
#include "ListaPlanillas.h"
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"
#include <fstream>

class GestorPlanilla {
private:
	ListaDepartamentos* departamentos;
	ListaEmpleados* empleados;
	ListaPlanillas* planillas;
	
public:
	GestorPlanilla();
	virtual ~GestorPlanilla();
	
	void cargarDatos();
	void guardarDatos();
	void cargarDepartamentos();
	void guardarDepartamentos();
	void cargarEmpleados();
	void guardarEmpleados();
	void cargarPlanillas();
	void guardarPlanillas();
	
	string registrarDepartamento(string id, string nombre, string ubicacion);
	string asignarEmpleadoADepartamento(string idDep, string idEmp);
	string consultarDepartamento(string id);
	string listarDepartamentos();
	string eliminarDepartamento(string id);
	
	string registrarMedico(string id, string nombre, double salarioBase, string turno, double horasExtra, string especialidad, int guardias);
	string registrarEnfermero(string id, string nombre, double salarioBase, string turno, double horasExtra, string area, int turnosNocturnos);
	string registrarAdministrativo(string id, string nombre, double salarioBase, string turno, double horasExtra, string puesto, double bonificacion);
	string consultarEmpleado(string id);
	string listarEmpleados();
	string eliminarEmpleado(string id);
	
	string crearPlanilla(string idPlanilla, string periodo, string fechaGeneracion);
	string generarComprobanteIndividual(string idPlanilla, string idComprobante, string fechaPago, string idEmpleado);
	string generarPlanillaGeneral(string idPlanilla, string fechaPago);
	string procesarPagoPlanilla(string idPlanilla);
	string consultarPlanilla(string idPlanilla);
	string listarPlanillas();
};

#endif
