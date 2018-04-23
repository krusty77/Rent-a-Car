//Empresa.cpp
#include "Empresa.h"

Empresa::Empresa(){
	this->nombre = new char();
	this->cedula_juridica = new char();
	this->telefono = new char();
	this->direccion = new char();
}
Empresa::Empresa(string pnombre,string pCedula_juridica,string ptelefono,string pDirrecion){
	this->setNombre(pnombre);
	this->setCedula_juridica(pCedula_juridica);
	this->setTelefono(ptelefono);
	this->setDireccion(pDirrecion);
}
Empresa::~Empresa(){}
	//Metodos Sets		
void Empresa::setNombre(string pnombre){this->nombre=pnombre;}
void Empresa::setCedula_juridica(string pCedula_juridica){this->cedula_juridica=pCedula_juridica;}
void Empresa::setTelefono(string ptelefono){this->telefono=ptelefono;}
void Empresa::setDireccion(string pDirrecion){this->direccion=pDirrecion;}	
	
   //Metodos Gets	
string Empresa::getNombre(){return this->nombre;}
string Empresa::getCedula_juridica(){return this->cedula_juridica;}
string Empresa::getTelefono(){return this->telefono;}
string Empresa::getDireccion(){return this->direccion;}

string Empresa::toString(){	
stringstream r;
r<<"Datos Empresa"<<endl<<"Cedula: "<<this->getCedula_juridica()<<endl<<"Nombre: "<<this->getNombre()<<endl<<"Telefono: "<<this->getTelefono()<<endl<<"Direccion: "<<this->getDireccion();
return r.str();
}