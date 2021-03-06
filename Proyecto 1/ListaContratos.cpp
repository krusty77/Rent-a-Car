#include "ListaContratos.h"

ListaContratos::ListaContratos(){
	this->setDummy(NULL);

}

void ListaContratos::setDummy(Contrato* pDummy){this->dummy=pDummy;}

Contrato* ListaContratos::getDummy(){return this->dummy;}

bool ListaContratos::isEmpty(){
	if(this->getDummy()==NULL)
		return true;
	else
		return false;
}

Contrato* ListaContratos::getUltimo(){
	 aux = NULL;				//inicializo aux
	if(!(this->isEmpty())){				//si la lista no esta vacia
		for(aux = this->getDummy(); aux->getpSiguiente()!=NULL; aux=aux->getpSiguiente()){}//recorro la madre hasta q quede en el ultimo mae
	}
	return aux;//retorno el aux q es el que quedo apuntando al ultimo mae
}

void ListaContratos::InsertarContrato(Contrato &c){
	Contrato * contratito = new Contrato(c);
		if(this->isEmpty()){
		this->setDummy(contratito);//lo pongo en la primera posisicion
	}else
		this->getUltimo()->setpSiguiente(contratito);//sino al ultimo lo pongo a ver al nuevo
	
	contratito->setpSiguiente(NULL);//y al nuevo lo pongo a ver a NULL
}

void ListaContratos::MostarContratosActivos(){
	int i=4;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	gotoxy(25,1);
	cout<<"*** REPORTE DE CONTRATOS ACTIVOS ***";
	for(aux = this->getDummy(); aux!=NULL; aux=aux->getpSiguiente()){
		if(aux->getEstado()==true){
			aux->Mostrar(i);
			i++;
		}
	}
}

void ListaContratos::MostarContratosInactivos(){
	int i=4;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	gotoxy(25,1);
	cout<<"*** REPORTE DE CONTRATOS INACTIVOS ***";
	for(aux = this->getDummy(); aux!=NULL; aux=aux->getpSiguiente()){
		if(aux->getEstado()==false){
			aux->Mostrar(i);
			i++;	
		}
	}
}

void ListaContratos::MostarTodosLosContratos(int tp){
	int i=4;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	gotoxy(22,1);
	cout<<"*** REPORTE DE CONTRATOS ***";
	for(aux = this->getDummy(); aux!=NULL; aux=aux->getpSiguiente())
		if(aux->getVehiculo()->tipo()==tp && aux->getEstado()==true){
			aux->Mostrar(i);
			i++;
		}
			
	}

bool ListaContratos::DesactivarPorCodigoContrato(int n){
	if(!(this->isEmpty())){
		for(aux = this->getDummy(); aux!=NULL; aux=aux->getpSiguiente()){//recorro la madre hasta q encuentre la posision deseada
			if(aux->getCodContrato() == n)
				break;
			}
		aux->DesactivarEstado();
	//	aux->
		return true;
	}
	else return false;
}

bool ListaContratos::ValidaCodContrato(int cdContrato){
      if(this->isEmpty()== true){
            return true;
      }else{            
		  for(aux = this->getDummy(); aux!=NULL; aux = aux->getpSiguiente()){
                  if(aux->getCodContrato() == cdContrato){
                        return false;
                        break;
                  }
            }
            return true;
      }
}
Contrato* ListaContratos::BuscarCodContrato(int n){
	if(!(this->isEmpty())){
		bool encontrado=false;
		Contrato* aux;
		for(aux = this->getDummy(); aux!=NULL; aux=aux->getpSiguiente()){
			if(aux->getCodContrato() == n){
				encontrado=true;
				break;
			}
		}
		if(encontrado==true)
			return aux;
		else
			return NULL;
	}
	else{return NULL;}
}

void ListaContratos::gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

ListaContratos::~ListaContratos(){
}








 