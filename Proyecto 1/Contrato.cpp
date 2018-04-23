#include "Contrato.h"

Contrato::Contrato(){
	this->setCodContrato(0);
	this->setFechaPrestamo(f.CalcularFechaActual());
	this->sethoraPrestamo(f.CalcularHoraActual());
	this->setDiaDevoluccion(0);
	this->setMesDevoluccion(0);
	this->setDiasPrestamo(0);
	this->setEstado(true);
	this->costumer = new Cliente();
}

Contrato::Contrato(int numContrato,int dv, int mv,int dp, Cliente &c,Vehiculo *v){
	this->setCodContrato(numContrato);
	this->setEstado(true);
	this->setFechaPrestamo(f.CalcularFechaActual());
	this->sethoraPrestamo(f.CalcularHoraActual());
	this->setDiaDevoluccion(dv);
	this->setMesDevoluccion(mv);
	this->setDiasPrestamo(dp);
	this->costumer = new Cliente(c);
	this->setVehiculo(v);
}
Contrato::~Contrato(){}

Contrato::Contrato(Contrato& c){
	this->setFechaPrestamo(c.getFechaPrestamo());
	this->sethoraPrestamo(c.gethoraPrestamo());
	this->setDiaDevoluccion(c.getDiaDevoluccion());
	this->setMesDevoluccion(c.getMesDevoluccion());
	this->setDiasPrestamo(c.getDiasPrestamo());
	this->setCodContrato(c.getCodContrato());
	this->setEstado(c.getEstado());
	this->setCostumer(c.getCostumer());
	this->setVehiculo(c.getVehiculo());
}
   //Metodos Sets
void Contrato::setCodContrato(int n){this->codContrato=n;}
void Contrato::setFechaPrestamo(string pFechaPrestamo){this->fechaPrestamo=pFechaPrestamo;}//hay q buscar los metodillos q sacan las varas del sistema, modularizar, hora y fecha y pasarlas a una cadena de caracteres
void Contrato::sethoraPrestamo(string pHoraPrestamo){this->horaPrestamo=pHoraPrestamo;}
void Contrato::setDiaDevoluccion(int pFechaDevoluccion){this->diaDevoluccion =pFechaDevoluccion;}
void Contrato::setMesDevoluccion(int m){this->mesDevolucion = m;}
void Contrato::setDiasPrestamo(int dp){this->diasPrestamo = dp;}
void Contrato::setpSiguiente(Contrato* p){this->pSiguiente = p;}
void Contrato::setEstado(bool e){this->Estado = e;}
 //Metodos Gets
int Contrato::getCodContrato(){return this->codContrato;}
string Contrato::getFechaPrestamo(){return this->fechaPrestamo;}
string Contrato::gethoraPrestamo(){return this->horaPrestamo;}
int Contrato::getDiaDevoluccion(){return this->diaDevoluccion;}
int Contrato::getMesDevoluccion(){return this->mesDevolucion;}
int Contrato::getDiasPrestamo(){return this->diasPrestamo;}
bool Contrato::getEstado(){return this->Estado;}
Contrato* Contrato::getpSiguiente(){return this->pSiguiente;}

 //Metodos Alternos
long double Contrato::calcularMontoPagarSedan(int dias){
	long double aux = 0.0;
	if(dias<=2){//si son los dias minimos
		if(this->getCostumer()->getTipoPago()== true){//si el pago es con tarjeta
			return aux = (((2*75)+250)*0.08)+(2*75)+250;//escupa el 8% + los dias minimos * la tarifa diaria + el deposito
		}else{
			return aux = (2*75)+250;//si no escupa los dias minimos * la tarifa diaria + el deposito
		}
		}else{//si son mas de los dias minimos
			if(this->getCostumer()->getTipoPago()== true){//si el pago es con tarjeta
				return aux = (((dias*75)+250)*0.08)+(dias*75)+250;//escupa el 8% + los dias requeridos * la tarifa diaria + el deposito
			}else{return aux = (dias*75)+250;}//si no escupa los dias requeridos * la tarifa diaria + el deposito
	}
}		//dias y //tomar en cuenta tipo de pago		
long double Contrato::calcularMontoPagarDobleTraccion(int dias){
	long double aux = 0.0;
	if(dias<=2){//si son los dias minimos
		if(this->getCostumer()->getTipoPago()== true){//si el pago es con tarjeta
			return aux = (((2*100)+300)*0.08)+(2*75)+300;//escupa el 8% + los dias minimos * la tarifa diaria + el deposito
		}else{
			return aux = (2*100)+300;//si no escupa los dias minimos * la tarifa diaria + el deposito
		}
		}else{//si son mas de los dias minimos
			if(this->getCostumer()->getTipoPago()== true){//si el pago es con tarjeta
				return aux = (((dias*100)+300)*0.08)+(dias*75)+300;//escupa el 8% + los dias requeridos * la tarifa diaria + el deposito
			}else{return aux = (dias*100)+300;}//si no escupa los dias requeridos * la tarifa diaria + el deposito
	}
	}
long double Contrato::calcularMontoPagarBus(int dias){
	long double aux = 0.0;
	if(dias<=2){//si son los dias minimos
		if(this->getCostumer()->getTipoPago()== true){//si el pago es con tarjeta
			return aux = (((2*200)+400)*0.08)+(2*75)+300;//escupa el 8% + los dias minimos * la tarifa diaria + el deposito
		}else{
			return aux = (2*200)+400;//si no escupa los dias minimos * la tarifa diaria + el deposito
		}
		}else{//si son mas de los dias minimos
			if(this->getCostumer()->getTipoPago()== true){//si el pago es con tarjeta
				return aux = (((dias*200)+400)*0.08)+(dias*75)+300;//escupa el 8% + los dias requeridos * la tarifa diaria + el deposito
			}else{return aux = (dias*200)+400;}//si no escupa los dias requeridos * la tarifa diaria + el deposito
	}
	}
void Contrato::DesactivarEstado(){
		this->Estado = false;
	}
/*string Contrato::toString(){
	stringstream r;
	r<<"Codigo de prestamo: "<<this->getCodContrato()<<endl<<"Cedula del cliente: "<<this->getCostumer()->getCedula()<<endl
		<<"Placa del Vehiculo Alquilado: "<<this->getVehiculo()->getNumeroDePlaca()<<endl<<"Fecha y hora del Prestamos"<<
		this->getFechaPrestamo()<<"  "<<this->gethoraPrestamo()<<endl<<"Fecha de Devolucion: "<<this->getfechaDevoluccion()<<endl;
	return r.str();
}*/

void Contrato::Mostrar(int i){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	gotoxy(0,3);cout<<"Codigo";
	gotoxy(12,3);cout<<"Ced Cliente";
	gotoxy(26,3);cout<<"Placa Vehiculo";
	gotoxy(44,3);cout<<"Fecha Prestamo";
	gotoxy(61,3);cout<<"Fecha Devolucion";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
	gotoxy(0,i);cout<<this->getCodContrato();
	gotoxy(12,i);cout<<this->getCostumer()->getCedula();
	gotoxy(26,i);cout<<this->getVehiculo()->getNumeroDePlaca();
	gotoxy(44,i);cout<<this->getFechaPrestamo();
	gotoxy(61,i);cout<<this->getDiaDevoluccion()<<"-"<<this->getMesDevoluccion()<<"-"<<f.año();
}


void Contrato::setCostumer(Cliente* c){this->costumer = c;}
Cliente* Contrato::getCostumer(){return this->costumer;}
void Contrato::setVehiculo(Vehiculo *v){this->carrito = v;}
Vehiculo* Contrato::getVehiculo(){return this->carrito;}

void Contrato::gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}