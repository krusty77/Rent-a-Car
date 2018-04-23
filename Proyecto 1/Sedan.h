//Sedan.h
#pragma once
#include "Vehiculo.h"
class Sedan:public Vehiculo{
private:
	int numeroPuertas;

public:
	Sedan();
	Sedan(string,string,string,string,int);
	Sedan(Sedan*);
	virtual void Copy(Sedan*);

	void setNumeroPuertas(int);
	int getNumeroPuertas();
	void Modificar(int);
	virtual int tipo();
	virtual void toString(int);
	~Sedan();
};