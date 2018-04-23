//Sedan .cpp
#include "Sedan.h"

Sedan::Sedan(){
	this->setNumeroPuertas(1);//x defecto lo voy hacer de 3 puertas
	//this->setPSiguiente(NULL);
}
Sedan::Sedan(string pNumeroDePlaca,string pMarca,string pModelo,string pColor,int pNumeroPuertas){
	this->setNumeroDePlaca(pNumeroDePlaca);
	this->setMarca(pMarca);
	this->setModelo(pModelo);
	this->setColor(pColor);
	this->setNumeroPuertas(pNumeroPuertas);
}

Sedan::Sedan(Sedan* s){
	this->Copy(s);
}

void Sedan::Copy(Sedan* s){
	Vehiculo::Copy(s);
	this->setNumeroPuertas(s->getNumeroPuertas());
}

void Sedan::setNumeroPuertas(int pNumeroPuertas){
	this->numeroPuertas = pNumeroPuertas;
}
int Sedan::getNumeroPuertas(){return this->numeroPuertas;}

int Sedan::tipo(){return 1;}

void Sedan::Modificar(int np){
	this->setNumeroPuertas(np);
}

void Sedan::toString(int i){
	Vehiculo::toString(i);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	gotoxy(58,3);cout<<"Numero de Puertas";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
	gotoxy(58,i);cout<<this->getNumeroPuertas();
}
Sedan::~Sedan(){}