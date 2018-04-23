//Empresa.h
#pragma once
#include <sstream>
#include<iostream>
#include<string.h>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Empresa{
private:
	string nombre;
	string cedula_juridica;
	string telefono;
	string direccion; 


public:
	Empresa();
	Empresa(string,string,string,string);
   ~Empresa();
	//Metodos Sets		
	void setNombre(string);
	void setCedula_juridica(string);
	void setTelefono(string);
	void setDireccion(string);	
	
   //Metodos Gets	
	string getNombre();
	string getCedula_juridica();
	string getTelefono();
	string getDireccion();	
	string toString();
};