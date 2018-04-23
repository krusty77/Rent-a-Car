//Vehiculo.h
#pragma once
#include <sstream>
#include<iostream>
#include<string.h>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "Windows.h"
using namespace std;

class Vehiculo{
protected:
	string numPlaca;
	string marca;
	string modelo;
	string color;
	bool alquilado;
	Vehiculo *pSiguiente;
public:
	//CONSTRUCTORES Y DESTRUCTORES
	Vehiculo();
	Vehiculo(string,string,string,string,Vehiculo*);
	Vehiculo(Vehiculo*);
	virtual void Copy(Vehiculo*);
	//SETS Y GETS
	void setNumeroDePlaca(string);
	void setMarca(string);
	void setModelo(string);
	void setColor(string);
	void setPSiguiente(Vehiculo*);
	void setAlquilado(bool);
	string getNumeroDePlaca();
	string getMarca();
	string getModelo();
	string getColor();
	bool getAlquilado();
	Vehiculo* getPSiguiente();
	void gotoxy(int x, int y);
	
	virtual void Modificar(int);//este mae me va a modificar los atributos extras de sedan dobletraccion y bus
	virtual int tipo();//tipo 1= sedan, tipo 2 = 2traccion, tipo 3 = bus
	virtual void toString(int);
	~Vehiculo();
};