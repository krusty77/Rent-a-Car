//Lista.h
#pragma once
#include "Vehiculo.h"
#include "Bus.h"
#include "Sedan.h"
#include "DobleTraccion.h"


class ListaVehiculo{
private:
	Vehiculo* dummy;

public:
	ListaVehiculo();
	Vehiculo* getDummy();
	void setDummy(Vehiculo*);
	void InsertarBus(string,string,string,string,int);//Vehiculo * busito = new Bus();
	void InsertarSedan(string,string,string,string,int);
	void InsertarDobleTraccion(string,string,string,string,int);
	void MostrarTodosLosVehiculos();
	void MostrarTodosLosBuses();
	void MostrarTodosLosSedanes();
	void MostrarTodosLosDobleTraccion();
	void eliminalAlFinal();
	bool isEmpty();
	void gotoxy(int,int);
	Vehiculo* getN(int);
	Vehiculo* getUltimo();
	Vehiculo* BuscarporPlaca(string);
	Vehiculo* AlquilarBus();
	Vehiculo* AlquilarSedan();
	Vehiculo* AlquilarDobleTraccion();
	bool EliminarPorPlaca(string);
	void EliminarPrimero();
	bool ValidaPlaca(string);
	int len();

	~ListaVehiculo();
};

