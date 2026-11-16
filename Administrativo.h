#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include "Empleado.h"

class Administrativo : public Empleado {
private:
	string *puesto;
	double *bonificacionFija;
	
public:
	Administrativo();
	Administrativo(string *id, string *nombre, double *salarioBase, string *turno, double *horasExtra, string *puesto, double *bonificacionFija);
	virtual ~Administrativo();
	
	void setPuesto(string *puesto);
	string getPuesto();
	
	void setBonificacionFija(double *bonificacionFija);
	double getBonificacionFija();
	
	double calcularSalarioBruto() override;
	string toString() override;
	void autoGuardar(ofstream& estFile) override;
	static Administrativo* autoLeer(ifstream& estFile);
};

#endif
