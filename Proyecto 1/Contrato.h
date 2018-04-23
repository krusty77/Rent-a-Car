//Contrato.h
#pragma once
#include "Fecha.h"
#include "Cliente.h"
#include "Vehiculo.h"
#include "Sedan.h"
#include "DobleTraccion.h"
#include "Bus.h"

class Contrato{
private:
	int codContrato;
	Cliente *costumer;
	Vehiculo *carrito;//automaticamente x ser objetos estaticos llaman al constructor predeterminado de ellos si no tuvieran llaman al de x defecto
	string fechaPrestamo;
	string horaPrestamo;
	int diaDevoluccion;
	int mesDevolucion;
	int diasPrestamo;
	bool Estado;//el estado x defecto va a ser activo cada ves q uno nasca
	Contrato *pSiguiente;
	Fecha f;

public:
	Contrato();
	Contrato(int,int,int,int,Cliente&,Vehiculo*);
	Contrato(Contrato&);
	~Contrato();
   //Metodos Sets
	void setCodContrato(int);
	void setCostumer(Cliente*);
	void setVehiculo(Vehiculo*);
	void setFechaPrestamo(string);
	void sethoraPrestamo(string);
	void setDiaDevoluccion(int);
	void setMesDevoluccion(int);
	void setDiasPrestamo(int);
	void setpSiguiente(Contrato*);
	void setEstado(bool);
 //Metodos Gets
	Contrato* getpSiguiente();
	int getCodContrato();
	Cliente* getCostumer();
	Vehiculo* getVehiculo();
	string getFechaPrestamo();
	string gethoraPrestamo();
	int getDiaDevoluccion();
	int getMesDevoluccion();
	int getDiasPrestamo();
	bool getEstado();

 //Metodos Alternos
	long double calcularMontoPagarSedan(int);		//dias y //tomar en cuenta tipo de pago	
	long double calcularMontoPagarDobleTraccion(int);
	long double calcularMontoPagarBus(int);
	void DesactivarEstado();
	string toString();
	void Mostrar(int);
	void gotoxy(int,int);
};