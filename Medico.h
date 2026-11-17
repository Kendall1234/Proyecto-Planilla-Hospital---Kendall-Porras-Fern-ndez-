#ifndef MEDICO_H
#define MEDICO_H

#include "Empleado.h"

class Medico : public Empleado {
private:
	string *especialidad;
	int *guardiasNocturnas;
	
public:
	Medico();
	Medico(string *id, string *nombre, double *salarioBase, string *turno, double *horasExtra, string *especialidad, int *guardiasNocturnas);
	virtual ~Medico();
	
	void setEspecialidad(string *especialidad);
	string getEspecialidad();
	
	void setGuardiasNocturnas(int *guardiasNocturnas);
	int getGuardiasNocturnas();
	
	double calcularSalarioBruto() override; 
	string toString() override;
	void autoGuardar(ofstream& estFile) override;
	static Medico* autoLeer(ifstream& estFile);
};

#endif
