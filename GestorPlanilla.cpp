#include "GestorPlanilla.h"

GestorPlanilla::GestorPlanilla() {
	departamentos = new ListaDepartamentos();
	empleados = new ListaEmpleados();
	planillas = new ListaPlanillas();
}

GestorPlanilla::~GestorPlanilla() {
	NodoDepartamento* nodoDep = departamentos->getCabeza();
	while (nodoDep != NULL) {
		delete nodoDep->getDato();
		nodoDep = nodoDep->getSig();
	}
	delete departamentos;
	
	NodoEmpleado* nodoEmp = empleados->getCabeza();
	while (nodoEmp != NULL) {
		delete nodoEmp->getDato();
		nodoEmp = nodoEmp->getSig();
	}
	delete empleados;
	
	delete planillas;
}

void GestorPlanilla::cargarDatos() {
	cargarDepartamentos();
	cargarEmpleados();
	cargarPlanillas();
}

void GestorPlanilla::guardarDatos() {
	guardarDepartamentos();
	guardarEmpleados();
	guardarPlanillas();
}

void GestorPlanilla::cargarDepartamentos() {
	ifstream archivo("departamentos.txt");
	if (!archivo.is_open()) {
		return;
	}
	Departamento* dep = NULL;
	while ((dep = Departamento::autoLeer(archivo)) != NULL) {
		departamentos->insertarDepartamento(dep);
	}
	archivo.close();
}

void GestorPlanilla::guardarDepartamentos() {
	ofstream archivo("departamentos.txt");
	if (!archivo.is_open()) {
		return;
	}
	NodoDepartamento* actual = departamentos->getCabeza();
	while (actual != NULL) {
		actual->getDato()->autoGuardar(archivo);
		actual = actual->getSig();
	}
	archivo.close();
}

void GestorPlanilla::cargarEmpleados() {
	ifstream archivo("empleados.txt");
	if (!archivo.is_open()) {
		return;
	}
	string tipo;
	while (archivo >> tipo) {
		Empleado* emp = NULL;
		if (tipo == "MEDICO") {
			emp = Medico::autoLeer(archivo);
		} else if (tipo == "ENFERMERO") {
			emp = Enfermero::autoLeer(archivo);
		} else if (tipo == "ADMINISTRATIVO") {
			emp = Administrativo::autoLeer(archivo);
		}
		if (emp != NULL) {
			empleados->insertarEmpleado(emp);
		}
	}
	archivo.close();
}

void GestorPlanilla::guardarEmpleados() {
	ofstream archivo("empleados.txt");
	if (!archivo.is_open()) {
		return;
	}
	NodoEmpleado* actual = empleados->getCabeza();
	while (actual != NULL) {
		Empleado* emp = actual->getDato();
		if (dynamic_cast<Medico*>(emp) != NULL) {
			archivo << "MEDICO" << endl;
		} else if (dynamic_cast<Enfermero*>(emp) != NULL) {
			archivo << "ENFERMERO" << endl;
		} else if (dynamic_cast<Administrativo*>(emp) != NULL) {
			archivo << "ADMINISTRATIVO" << endl;
		}
		emp->autoGuardar(archivo);
		actual = actual->getSig();
	}
	archivo.close();
}

void GestorPlanilla::cargarPlanillas() {
	ifstream archivo("planilla.txt");
	if (!archivo.is_open()) {
		return;
	}
	string idPlanilla, periodo, fechaGen;
	bool cerrada;
	int cantComprobantes;
	
	while (archivo >> idPlanilla >> periodo >> fechaGen >> cerrada >> cantComprobantes) {
		Planilla* p = new Planilla(&idPlanilla, &periodo, &fechaGen);
		for (int i = 0; i < cantComprobantes; i++) {
			string idComp, fechaPago, idEmp;
			bool pagado;
			archivo >> idComp >> fechaPago >> idEmp >> pagado;
			Empleado* emp = empleados->buscarPorId(idEmp);
			if (emp != NULL) {
				ComprobantePlanilla* comp = new ComprobantePlanilla(&idComp, &fechaPago, emp);
				if (pagado) {
					comp->procesarPago();
				}
				p->agregarComprobante(comp);
			}
		}
		if (cerrada) {
			p->cerrarPlanilla();
		}
		planillas->insertarPlanilla(p);
	}
	archivo.close();
}

void GestorPlanilla::guardarPlanillas() {
	ofstream archivo("planilla.txt");
	if (!archivo.is_open()) {
		return;
	}
	NodoPlanilla* nodoP = planillas->getCabeza();
	while (nodoP != NULL) {
		Planilla* p = nodoP->getDato();
		archivo << p->getIdPlanilla() << endl
			<< p->getPeriodo() << endl
			<< p->getFechaGeneracion() << endl
			<< p->getCerrada() << endl
			<< p->getComprobantes()->contar() << endl;
		
		NodoComprobante* nodoC = p->getComprobantes()->getCabeza();
		while (nodoC != NULL) {
			ComprobantePlanilla* c = nodoC->getDato();
			string idEmp = (c->getEmpleado() != NULL) ? c->getEmpleado()->getId() : "NONE";
			archivo << c->getIdComprobante() << endl
				<< c->getFechaPago() << endl
				<< idEmp << endl
				<< c->getPagado() << endl;
			nodoC = nodoC->getSig();
		}
		nodoP = nodoP->getSig();
	}
	archivo.close();
}

string GestorPlanilla::registrarDepartamento(string id, string nombre, string ubicacion) {
	if (departamentos->buscarPorId(id) != NULL) {
		return "Error: Ya existe un departamento con ese ID.";
	}
	Departamento* dep = new Departamento(&id, &nombre, &ubicacion);
	departamentos->insertarDepartamento(dep);
	guardarDepartamentos();
	return "Departamento registrado y guardado exitosamente.";
}

string GestorPlanilla::asignarEmpleadoADepartamento(string idDep, string idEmp) {
	Departamento* dep = departamentos->buscarPorId(idDep);
	if (dep == NULL) {
		return "Error: Departamento no encontrado.";
	}
	Empleado* emp = empleados->buscarPorId(idEmp);
	if (emp == NULL) {
		return "Error: Empleado no encontrado.";
	}
	dep->agregarEmpleado(emp);
	return "Empleado asignado al departamento correctamente.";
}

string GestorPlanilla::consultarDepartamento(string id) {
	return departamentos->consultarDepartamento(id);
}

string GestorPlanilla::listarDepartamentos() {
	return departamentos->listarDepartamentos();
}

string GestorPlanilla::eliminarDepartamento(string id) {
	Departamento* dep = departamentos->buscarPorId(id);
	if (dep == NULL) {
		return "No se encontro un departamento con ese ID.";
	}
	string res = departamentos->eliminarDepartamento(id);
	delete dep;
	guardarDepartamentos();
	return res;
}

string GestorPlanilla::registrarMedico(string id, string nombre, double salarioBase, string turno, double horasExtra, string especialidad, int guardias) {
	if (empleados->buscarPorId(id) != NULL) {
		return "Error: Ya existe un empleado con ese ID.";
	}
	Medico* med = new Medico(&id, &nombre, &salarioBase, &turno, &horasExtra, &especialidad, &guardias);
	empleados->insertarEmpleado(med);
	guardarEmpleados();
	return "Medico registrado y guardado exitosamente.";
}

string GestorPlanilla::registrarEnfermero(string id, string nombre, double salarioBase, string turno, double horasExtra, string area, int turnosNocturnos) {
	if (empleados->buscarPorId(id) != NULL) {
		return "Error: Ya existe un empleado con ese ID.";
	}
	Enfermero* enf = new Enfermero(&id, &nombre, &salarioBase, &turno, &horasExtra, &area, &turnosNocturnos);
	empleados->insertarEmpleado(enf);
	guardarEmpleados();
	return "Enfermero registrado y guardado exitosamente.";
}

string GestorPlanilla::registrarAdministrativo(string id, string nombre, double salarioBase, string turno, double horasExtra, string puesto, double bonificacion) {
	if (empleados->buscarPorId(id) != NULL) {
		return "Error: Ya existe un empleado con ese ID.";
	}
	Administrativo* adm = new Administrativo(&id, &nombre, &salarioBase, &turno, &horasExtra, &puesto, &bonificacion);
	empleados->insertarEmpleado(adm);
	guardarEmpleados();
	return "Administrativo registrado y guardado exitosamente.";
}

string GestorPlanilla::consultarEmpleado(string id) {
	return empleados->consultarEmpleado(id);
}

string GestorPlanilla::listarEmpleados() {
	return empleados->listarEmpleados();
}

string GestorPlanilla::eliminarEmpleado(string id) {
	Empleado* emp = empleados->buscarPorId(id);
	if (emp == NULL) {
		return "El empleado no esta en la lista.";
	}
	string res = empleados->eliminarEmpleado(id);
	delete emp;
	guardarEmpleados();
	return res;
}

string GestorPlanilla::crearPlanilla(string idPlanilla, string periodo, string fechaGeneracion) {
	if (planillas->buscarPorId(idPlanilla) != NULL) {
		return "Error: Ya existe una planilla con ese ID.";
	}
	Planilla* p = new Planilla(&idPlanilla, &periodo, &fechaGeneracion);
	planillas->insertarPlanilla(p);
	guardarPlanillas();
	return "Planilla creada exitosamente.";
}

string GestorPlanilla::generarComprobanteIndividual(string idPlanilla, string idComprobante, string fechaPago, string idEmpleado) {
	Planilla* p = planillas->buscarPorId(idPlanilla);
	if (p == NULL) {
		return "Error: Planilla no encontrada.";
	}
	if (p->getCerrada()) {
		return "Error: La planilla ya esta cerrada.";
	}
	Empleado* emp = empleados->buscarPorId(idEmpleado);
	if (emp == NULL) {
		return "Error: Empleado no encontrado.";
	}
	ComprobantePlanilla* comp = new ComprobantePlanilla(&idComprobante, &fechaPago, emp);
	p->agregarComprobante(comp);
	guardarPlanillas();
	return "Comprobante generado y agregado a la planilla:\n" + comp->toString();
}

string GestorPlanilla::generarPlanillaGeneral(string idPlanilla, string fechaPago) {
	Planilla* p = planillas->buscarPorId(idPlanilla);
	if (p == NULL) {
		return "Error: Planilla no encontrada.";
	}
	if (p->getCerrada()) {
		return "Error: La planilla ya esta cerrada.";
	}
	if (empleados->vacio()) {
		return "Error: No hay empleados registrados para generar planilla.";
	}
	NodoEmpleado* actual = empleados->getCabeza();
	int contador = 1;
	while (actual != NULL) {
		Empleado* emp = actual->getDato();
		string idComp = idPlanilla + "-C" + to_string(contador);
		ComprobantePlanilla* comp = new ComprobantePlanilla(&idComp, &fechaPago, emp);
		p->agregarComprobante(comp);
		contador++;
		actual = actual->getSig();
	}
	guardarPlanillas();
	return "Planilla general generada para " + to_string(contador - 1) + " empleados.";
}

string GestorPlanilla::procesarPagoPlanilla(string idPlanilla) {
	Planilla* p = planillas->buscarPorId(idPlanilla);
	if (p == NULL) {
		return "Error: Planilla no encontrada.";
	}
	p->cerrarPlanilla();
	guardarPlanillas();
	return "Pago procesado y planilla cerrada exitosamente.";
}

string GestorPlanilla::consultarPlanilla(string idPlanilla) {
	return planillas->consultarPlanilla(idPlanilla);
}

string GestorPlanilla::listarPlanillas() {
	return planillas->listarPlanillas();
}
