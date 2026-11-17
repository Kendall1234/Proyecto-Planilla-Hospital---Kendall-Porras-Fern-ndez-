#ifndef INTERFAZMENU_H
#define INTERFAZMENU_H

#include "GestorPlanilla.h"
#include <iostream>

using namespace std;

class InterfazMenu {
private:
	GestorPlanilla* gestor;
	
public:
	InterfazMenu();
	virtual ~InterfazMenu();
	
	void iniciar();
	void mostrarMenuPrincipal();
	void menuEmpleados();
	void menuDepartamentos();
	void menuPlanillas();
};

#endif
