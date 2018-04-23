#include "Bus.h"

Bus::Bus(){	
	this->setNumeroDeAsientos(0);
}
Bus::Bus(string pNumeroDePlaca,string pMarca,string pModelo,string pColor, int pNumeroDeAsientos){
	this->setNumeroDePlaca(pNumeroDePlaca);
	this->setMarca(pMarca);
	this->setModelo(pModelo);
	this->setColor(pColor);
	this->setNumeroDeAsientos(pNumeroDeAsientos);
}
Bus::~Bus(){}

Bus::Bus(Bus* b){
	this->Copy(b);
}

void Bus::Copy(Bus* b){
	Vehiculo::Copy(b);
	this->setNumeroDeAsientos(b->getNumeroDeAsientos());
}

void Bus::setNumeroDeAsientos(int pNumeroDeAsientos){this->numeroDeAsientos=pNumeroDeAsientos;}
int Bus::getNumeroDeAsientos(){return this->numeroDeAsientos;}

int Bus::tipo(){return 3;}

void Bus::Modificar(int na){
	this->setNumeroDeAsientos(na);
}

void Bus::toString(int i){
	Vehiculo::toString(i);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	gotoxy(58,3);cout<<"Numero Asientos";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
	gotoxy(58,i);cout<<this->getNumeroDeAsientos();
}
