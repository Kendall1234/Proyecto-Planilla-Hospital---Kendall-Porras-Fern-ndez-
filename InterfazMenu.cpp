#include "InterfazMenu.h"

InterfazMenu::InterfazMenu() {
	gestor = new GestorPlanilla();
}

InterfazMenu::~InterfazMenu() {
	delete gestor;
}

void InterfazMenu::iniciar() {
	gestor->cargarDatos();
	int opcion = 0;
	
	do {
		mostrarMenuPrincipal();
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			opcion = -1;
		}
		
		switch (opcion) {
		case 1:
			menuEmpleados();
			break;
		case 2:
			menuDepartamentos();
			break;
		case 3:
			menuPlanillas();
			break;
		case 4:
			gestor->guardarDatos();
			cout << "\nDatos guardados correctamente. Saliendo del sistema...\n";
			break;
		default:
			cout << "\nOpcion invalida. Intente de nuevo.\n";
			break;
		}
	} while (opcion != 4);
}

void InterfazMenu::mostrarMenuPrincipal() {
	cout << "\n==========================================" << endl;
	cout << "   SISTEMA DE PLANILLA HOSPITALARIA CCSS  " << endl;
	cout << "==========================================" << endl;
	cout << "1. Gestion de Empleados" << endl;
	cout << "2. Gestion de Departamentos" << endl;
	cout << "3. Gestion de Planillas y Comprobantes" << endl;
	cout << "4. Guardar y Salir" << endl;
	cout << "==========================================" << endl;
}

void InterfazMenu::menuEmpleados() {
	int opcion = 0;
	do {
		cout << "\n--- GESTION DE EMPLEADOS ---" << endl;
		cout << "1. Registrar Medico" << endl;
		cout << "2. Registrar Enfermero" << endl;
		cout << "3. Registrar Administrativo" << endl;
		cout << "4. Consultar Empleado por ID" << endl;
		cout << "5. Listar Todos los Empleados" << endl;
		cout << "6. Eliminar Empleado" << endl;
		cout << "7. Volver al Menu Principal" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			opcion = -1;
		}
		
		if (opcion == 1 || opcion == 2 || opcion == 3) {
			string id, nombre, turno;
			double salarioBase, horasExtra;
			
			cout << "ID: ";
			cin >> id;
			cin.ignore();
			cout << "Nombre completo: ";
			getline(cin, nombre);
			cout << "Salario base: ";
			cin >> salarioBase;
			cout << "Turno (Dia/Noche/Mixto): ";
			cin >> turno;
			cout << "Horas extra: ";
			cin >> horasExtra;
			
			if (opcion == 1) {
				string especialidad;
				int guardias;
				cin.ignore();
				cout << "Especialidad: ";
				getline(cin, especialidad);
				cout << "Guardias nocturnas: ";
				cin >> guardias;
				cout << "\n" << gestor->registrarMedico(id, nombre, salarioBase, turno, horasExtra, especialidad, guardias) << endl;
			} else if (opcion == 2) {
				string area;
				int turnosNocturnos;
				cin.ignore();
				cout << "Area asignada: ";
				getline(cin, area);
				cout << "Turnos nocturnos: ";
				cin >> turnosNocturnos;
				cout << "\n" << gestor->registrarEnfermero(id, nombre, salarioBase, turno, horasExtra, area, turnosNocturnos) << endl;
			} else if (opcion == 3) {
				string puesto;
				double bonificacion;
				cin.ignore();
				cout << "Puesto: ";
				getline(cin, puesto);
				cout << "Bonificacion fija: ";
				cin >> bonificacion;
				cout << "\n" << gestor->registrarAdministrativo(id, nombre, salarioBase, turno, horasExtra, puesto, bonificacion) << endl;
			}
		} else if (opcion == 4) {
			string id;
			cout << "Ingrese ID del empleado: ";
			cin >> id;
			cout << "\n" << gestor->consultarEmpleado(id) << endl;
		} else if (opcion == 5) {
			cout << "\n" << gestor->listarEmpleados() << endl;
		} else if (opcion == 6) {
			string id;
			cout << "Ingrese ID del empleado a eliminar: ";
			cin >> id;
			cout << "\n" << gestor->eliminarEmpleado(id) << endl;
		} else if (opcion != 7) {
			cout << "\nOpcion invalida.\n";
		}
	} while (opcion != 7);
}

void InterfazMenu::menuDepartamentos() {
	int opcion = 0;
	do {
		cout << "\n--- GESTION DE DEPARTAMENTOS ---" << endl;
		cout << "1. Registrar Departamento" << endl;
		cout << "2. Asignar Empleado a Departamento" << endl;
		cout << "3. Consultar Departamento por ID" << endl;
		cout << "4. Listar Todos los Departamentos" << endl;
		cout << "5. Eliminar Departamento" << endl;
		cout << "6. Volver al Menu Principal" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			opcion = -1;
		}
		
		if (opcion == 1) {
			string id, nombre, ubicacion;
			cout << "ID Departamento: ";
			cin >> id;
			cin.ignore();
			cout << "Nombre del departamento: ";
			getline(cin, nombre);
			cout << "Ubicacion (piso/ala): ";
			getline(cin, ubicacion);
			cout << "\n" << gestor->registrarDepartamento(id, nombre, ubicacion) << endl;
		} else if (opcion == 2) {
			string idDep, idEmp;
			cout << "ID Departamento: ";
			cin >> idDep;
			cout << "ID Empleado: ";
			cin >> idEmp;
			cout << "\n" << gestor->asignarEmpleadoADepartamento(idDep, idEmp) << endl;
		} else if (opcion == 3) {
			string id;
			cout << "Ingrese ID del departamento: ";
			cin >> id;
			cout << "\n" << gestor->consultarDepartamento(id) << endl;
		} else if (opcion == 4) {
			cout << "\n" << gestor->listarDepartamentos() << endl;
		} else if (opcion == 5) {
			string id;
			cout << "Ingrese ID del departamento a eliminar: ";
			cin >> id;
			cout << "\n" << gestor->eliminarDepartamento(id) << endl;
		} else if (opcion != 6) {
			cout << "\nOpcion invalida.\n";
		}
	} while (opcion != 6);
}

void InterfazMenu::menuPlanillas() {
	int opcion = 0;
	do {
		cout << "\n--- GESTION DE PLANILLAS Y COMPROBANTES ---" << endl;
		cout << "1. Crear Nueva Planilla" << endl;
		cout << "2. Generar Comprobante Individual" << endl;
		cout << "3. Generar Planilla General (todos los empleados)" << endl;
		cout << "4. Procesar Pago y Cerrar Planilla" << endl;
		cout << "5. Consultar Planilla por ID" << endl;
		cout << "6. Listar Todas las Planillas" << endl;
		cout << "7. Volver al Menu Principal" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			opcion = -1;
		}
		
		if (opcion == 1) {
			string idPlanilla, periodo, fechaGen;
			cout << "ID Planilla: ";
			cin >> idPlanilla;
			cin.ignore();
			cout << "Periodo (ej. Noviembre-2026): ";
			getline(cin, periodo);
			cout << "Fecha de generacion (DD/MM/AAAA): ";
			cin >> fechaGen;
			cout << "\n" << gestor->crearPlanilla(idPlanilla, periodo, fechaGen) << endl;
		} else if (opcion == 2) {
			string idPlanilla, idComp, fechaPago, idEmp;
			cout << "ID Planilla: ";
			cin >> idPlanilla;
			cout << "ID Comprobante: ";
			cin >> idComp;
			cout << "Fecha de pago (DD/MM/AAAA): ";
			cin >> fechaPago;
			cout << "ID Empleado: ";
			cin >> idEmp;
			cout << "\n" << gestor->generarComprobanteIndividual(idPlanilla, idComp, fechaPago, idEmp) << endl;
		} else if (opcion == 3) {
			string idPlanilla, fechaPago;
			cout << "ID Planilla: ";
			cin >> idPlanilla;
			cout << "Fecha de pago (DD/MM/AAAA): ";
			cin >> fechaPago;
			cout << "\n" << gestor->generarPlanillaGeneral(idPlanilla, fechaPago) << endl;
		} else if (opcion == 4) {
			string idPlanilla;
			cout << "ID Planilla a cerrar y pagar: ";
			cin >> idPlanilla;
			cout << "\n" << gestor->procesarPagoPlanilla(idPlanilla) << endl;
		} else if (opcion == 5) {
			string idPlanilla;
			cout << "ID Planilla: ";
			cin >> idPlanilla;
			cout << "\n" << gestor->consultarPlanilla(idPlanilla) << endl;
		} else if (opcion == 6) {
			cout << "\n" << gestor->listarPlanillas() << endl;
		} else if (opcion != 7) {
			cout << "\nOpcion invalida.\n";
		}
	} while (opcion != 7);
}
