//DobleTraccion.cpp
#include "DobleTraccion.h"


DobleTraccion::DobleTraccion(){
	this->setTipoCombustible(1);
}
DobleTraccion::DobleTraccion(string pNumeroDePlaca,string pMarca,string pModelo,string pColor, int pTipoCombustible){
	this->setNumeroDePlaca(pNumeroDePlaca);
	this->setMarca(pMarca);
	this->setModelo(pModelo);
	this->setColor(pColor);
	this->setTipoCombustible(pTipoCombustible);
}
DobleTraccion::DobleTraccion(DobleTraccion* dt){
	this->Copy(dt);
}

void DobleTraccion::Copy(DobleTraccion* dt){
	Vehiculo::Copy(dt);
	this->setTipoCombustible(dt->geteoCombustible());
}

DobleTraccion::~DobleTraccion(){}

void DobleTraccion::seteoCombustible(int c){
	if(c==1)
		this->tipoCombustible = "Gasolina Super";
	else if(c==2)
		this->tipoCombustible = "Gasolina Regular";
	else 
		this->tipoCombustible = "Diesel";
}

int DobleTraccion::geteoCombustible(){
	if(this->getTipoCombustible()== "Gasolina Super")
		return 1;
	else if(this->getTipoCombustible()== "Gasolina Regular")
		return 2;
	else 
		return 3;
}

void DobleTraccion::setTipoCombustible(int pTipoCombustible){this->seteoCombustible(pTipoCombustible);}
string DobleTraccion::getTipoCombustible(){return this->tipoCombustible;}

int DobleTraccion::tipo(){return 2;}

void DobleTraccion::Modificar(int c){
	this->setTipoCombustible(c);
}

void DobleTraccion::toString(int i){
	Vehiculo::toString(i);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	gotoxy(58,3);cout<<"Tipo Combustible";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
	gotoxy(58,i);cout<<this->getTipoCombustible();
}