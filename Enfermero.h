#ifndef ENFERMERO_H
#define ENFERMERO_H

#include "Empleado.h"

class Enfermero : public Empleado {
private:
	string *areaAsignada;
	int *turnosNocturnos;
	
public:
	Enfermero();
	Enfermero(string *id, string *nombre, double *salarioBase, string *turno, double *horasExtra, string *areaAsignada, int *turnosNocturnos);
	virtual ~Enfermero();
	
	void setAreaAsignada(string *areaAsignada);
	string getAreaAsignada();
	
	void setTurnosNocturnos(int *turnosNocturnos);
	int getTurnosNocturnos();
	
	double calcularSalarioBruto() override;
	string toString() override;
	void autoGuardar(ofstream& estFile) override;
	static Enfermero* autoLeer(ifstream& estFile);
};

#endif
