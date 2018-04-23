//Cliente.cpp
#include "Cliente.h"

Cliente::Cliente(){	
	this->setNombre("Indefinido");
	this->setCedula("Indefinido");
	this->setTelefono("Indefinido");
	this->setDirrecion("Indefinido");
	this->tpoPago = false;//x defecto el mae va a ser en efectivo, si no me lo indica el usuario
}
Cliente::Cliente(string pnombre, string pcedula, string ptelefono, string pDirrecion, bool pTipoPago){
	this->setNombre(pnombre);
	this->setCedula(pcedula);
	this->setTelefono(ptelefono);
	this->setDirrecion(pDirrecion);
	this->setTipoPago(pTipoPago);
}
Cliente::Cliente(Cliente &c){this->Copy(c);}


void Cliente::Copy(Cliente &c){
	this->setNombre(c.getNombre());
	this->setCedula(c.getCedula());
	this->setTelefono(c.getTelefono());
	this->setDirrecion(c.getDirrecion());
	this->setTipoPago(c.getTipoPago());
}
//setters y getters
void Cliente::setNombre(string pnombre){this->nombre=pnombre;}
void Cliente::setCedula(string pcedula){this->cedula=pcedula;}
void Cliente::setTelefono(string ptelefono){this->telefono=ptelefono;}
void Cliente::setDirrecion(string pDirrecion){this->direccion=pDirrecion;}
void Cliente::setTipoPago(bool pTipoPago){this->tpoPago= pTipoPago;}
string Cliente::getNombre(){return this->nombre;}
string Cliente::getCedula(){return this->cedula;}
string Cliente::getTelefono(){return this->telefono;}
string Cliente::getDirrecion(){return this->direccion;}
bool Cliente::getTipoPago(){return this->tpoPago;}
string Cliente::printTipoPago(){//este mae lo q va hacer es q va a escupir si es efectivo o tarjeta para el tostring
	string cadena;
	if(this->getTipoPago() == true)//1 si es tarjeta, va a ser true
		cadena="Tarjeta";
	else
		cadena="Efectivo";//2 si es en efectivo falseif()	
    return cadena;
}

string Cliente::toString(){
	stringstream r;
	r<<"Cliente: "<<endl<<"Descripcion: "<<endl<<"Nombre: "<<this->getNombre()<<endl<<"Cedula: "<<this->getCedula()<<endl<<"Telefono: "<<this->getTelefono()<<endl<<
		"Dirrecion: "<<this->getDirrecion()<<endl<<"Tipo de pago: "<<this->printTipoPago()<<endl;
	return r.str();
}

Cliente::~Cliente(){}