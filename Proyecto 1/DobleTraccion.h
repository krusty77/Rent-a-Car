//DobleTraccion.h
#pragma once
#include "Vehiculo.h"

class DobleTraccion:public Vehiculo{
private:
	string tipoCombustible;
public:
	DobleTraccion();
	DobleTraccion(string,string,string,string,int);
	DobleTraccion(DobleTraccion*);
	virtual void Copy(DobleTraccion*);
	~DobleTraccion();

	int geteoCombustible();
	void seteoCombustible(int);
	void setTipoCombustible(int);//1 va a ser Gasolina super, 2 Gasolina regular, y 3 diesel
	string getTipoCombustible();
	virtual void Modificar(int);
	virtual int tipo();
	virtual void toString(int);
};