//Bus.h
#pragma once
#include "Vehiculo.h"

class Bus:public Vehiculo{
private:
	int numeroDeAsientos;
public:
	Bus();
	Bus(string,string,string,string,int);
	Bus(Bus*);
	virtual void Copy(Bus*);
	~Bus();
	void setNumeroDeAsientos(int);
	int getNumeroDeAsientos();
	void Modificar(int);
	virtual int tipo();
	virtual void toString(int);
};