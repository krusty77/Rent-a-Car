//Cliente.h
#pragma once
#include<iostream>
#include <sstream>
#include<string.h>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Cliente{
private:
	string nombre;
	string cedula;
	string telefono;
	string direccion;		 
	bool  tpoPago;			//True=Tarjeta  //False= Efectivo 
public:
	Cliente();
	Cliente(string,string,string,string, bool);
	Cliente(Cliente&);
	void Copy(Cliente&);
	void setNombre(string);
	void setCedula(string);
	void setTelefono(string);
	void setDirrecion(string);
	void setTipoPago(bool);
	string getNombre();
	string getCedula();
	string getTelefono();
	string getDirrecion();
	bool getTipoPago();
	string printTipoPago();
    string toString();
	~Cliente();
};