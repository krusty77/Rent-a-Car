///Vehiculo.cpp
#include "Vehiculo.h"


Vehiculo::Vehiculo(){
	this->setNumeroDePlaca("Indefinido");
	this->setMarca("Indefinido");
	this->setModelo("Indefinido");
	this->setColor("Indefinido");
	this->setAlquilado(false);
	this->setPSiguiente(NULL);
}
Vehiculo::Vehiculo(string pNumeroDePlaca,string pMarca,string pModelo,string pColor, Vehiculo* pSig){
	this->setNumeroDePlaca(pNumeroDePlaca);
	this->setMarca(pMarca);
	this->setModelo(pModelo);
	this->setColor(pColor);
	this->setPSiguiente(NULL);
	this->setAlquilado(false);
}

Vehiculo::Vehiculo(Vehiculo *v){this->Copy(v);}

void Vehiculo::Copy(Vehiculo *v){
	this->setNumeroDePlaca(v->getNumeroDePlaca());
	this->setMarca(v->getMarca());
	this->setModelo(v->getModelo());
	this->setColor(v->getColor());
	this->setAlquilado(v->getAlquilado());
}

void Vehiculo::setNumeroDePlaca(string pNumeroDePlaca){this->numPlaca=pNumeroDePlaca;}
void Vehiculo::setMarca(string pMarca){this->marca=pMarca;}
void Vehiculo::setModelo(string pModelo){this->modelo=pModelo;}
void Vehiculo::setColor(string pColor){this->color=pColor;}
void Vehiculo::setPSiguiente(Vehiculo* pSig){this->pSiguiente = pSig;}
void Vehiculo::setAlquilado(bool a){this->alquilado=a;}

string Vehiculo::getNumeroDePlaca(){return this->numPlaca;}
string Vehiculo::getMarca(){return this->marca;}
string Vehiculo::getModelo(){return this->modelo;}
string Vehiculo::getColor(){return this->color;}
Vehiculo* Vehiculo::getPSiguiente(){return this->pSiguiente;}
bool Vehiculo::getAlquilado(){return this->alquilado;}
int Vehiculo::tipo(){return 0;}

void Vehiculo::Modificar(int p){}

void Vehiculo::toString(int i){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	gotoxy(1,3);cout<<"Numero de Placa";
	gotoxy(22,3);cout<<"Marca";
	gotoxy(34,3);cout<<"Modelo";
	gotoxy(46,3);cout<<"Color";	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
	Vehiculo::gotoxy(1,i);cout<<this->getNumeroDePlaca();
	Vehiculo::gotoxy(22,i);cout<<this->getMarca();
	Vehiculo::gotoxy(34,i);cout<<this->getModelo();
	Vehiculo::gotoxy(46,i);cout<<this->getColor();
}

void Vehiculo::gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Vehiculo::~Vehiculo(){}