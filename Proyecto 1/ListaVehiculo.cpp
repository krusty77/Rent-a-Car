#include "ListaVehiculo.h"

ListaVehiculo::ListaVehiculo(){
	this->setDummy(NULL);

}

void ListaVehiculo::setDummy(Vehiculo* pDummy){this->dummy=pDummy;}

Vehiculo* ListaVehiculo::getDummy(){return this->dummy;}

bool ListaVehiculo::isEmpty(){
	if(this->getDummy()==NULL)
		return true;
	else
		return false;
}


Vehiculo* ListaVehiculo::getUltimo(){
	Vehiculo * aux = NULL;				//inicializo aux
	if(!(this->isEmpty())){				//si la lista no esta vacia
		for(aux = this->getDummy(); aux->getPSiguiente()!=NULL; aux=aux->getPSiguiente()){}//recorro la madre hasta q quede en el ultimo mae
	}
	return aux;//retorno el aux q es el que quedo apuntando al ultimo mae
}

	
int ListaVehiculo::len(){
	int n = 0;//iniacilizo el contador
	for(Vehiculo * aux = this->getDummy(); aux!=NULL; aux=aux->getPSiguiente()){n++;}//recorro la madre e incremento el contador
	return n;//devuelvo la cantidad de elementos
}

Vehiculo* ListaVehiculo::AlquilarBus(){
if(!(this->isEmpty())){
		bool encontrado=false;
		Vehiculo* aux;
		for(aux = this->getDummy(); aux!=NULL; aux=aux->getPSiguiente()){//recorro la madre hasta q encuentre la posision deseada
			if(aux->tipo() == 3 && aux->getAlquilado()==false){
				encontrado=true;
				aux->setAlquilado(true);
				break;
				
			}
		}
		if(encontrado==true)
			return aux;
		else
			return NULL;
	}
	else{return NULL;}//si no escupo un null
}

Vehiculo* ListaVehiculo::AlquilarSedan(){
if(!(this->isEmpty())){
		bool encontrado=false;
		Vehiculo* aux;
		for(aux = this->getDummy(); aux!=NULL; aux=aux->getPSiguiente()){//recorro la madre hasta q encuentre la posision deseada
			if(aux->tipo() == 1 && aux->getAlquilado()==false){
				encontrado=true;
				aux->setAlquilado(true);
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

Vehiculo* ListaVehiculo::AlquilarDobleTraccion(){
if(!(this->isEmpty())){
		bool encontrado=false;
		Vehiculo* aux;
		for(aux = this->getDummy(); aux!=NULL; aux=aux->getPSiguiente()){//recorro la madre hasta q encuentre la posision deseada
			if(aux->tipo() == 2 && aux->getAlquilado()==false){
				encontrado=true;
				aux->setAlquilado(true);
				break;
			}
		}
		if(encontrado==true)
			return aux;
		else
			return NULL;
	}
	else{return NULL;}//si no escupo un null
}



Vehiculo* ListaVehiculo::BuscarporPlaca(string n){
	if(!(this->isEmpty())){
		bool encontrado=false;
		Vehiculo* aux;
		for(aux = this->getDummy(); aux!=NULL; aux=aux->getPSiguiente()){//recorro la madre hasta q encuentre la posision deseada
			if(aux->getNumeroDePlaca() == n){
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

void ListaVehiculo::InsertarBus(string np,string ma,string mo,string c,int na){
	Vehiculo* busito = new Bus(np,ma,mo,c,na);//inializo aux
	if(this->isEmpty()){
		this->setDummy(busito);//lo pongo en la primera posisicion
	}else
		this->getUltimo()->setPSiguiente(busito);//sino al ultimo lo pongo a ver al nuevo
	
	busito->setPSiguiente(NULL);//y al nuevo lo pongo a ver a NULL
}

void ListaVehiculo::InsertarSedan(string np,string ma,string mo,string c,int npt){
	Vehiculo* sedancito = new Sedan(np,ma,mo,c,npt);//inializo aux
	if(this->isEmpty()){// si la madre esta vacia
		this->setDummy(sedancito);//lo pongo en la primera posisicion
	}else
		this->getUltimo()->setPSiguiente(sedancito);//sino al ultimo lo pongo a ver al nuevo
	
	sedancito->setPSiguiente(NULL);//y al nuevo lo pongo a ver a NULL
}

void ListaVehiculo::InsertarDobleTraccion(string np,string ma,string mo,string c,int tg){
	Vehiculo* dobleTraccioncito = new DobleTraccion(np,ma,mo,c,tg);//inializo aux
	if(this->isEmpty()){// si la madre esta vacia
		this->setDummy(dobleTraccioncito);//lo pongo en la primera posisicion
	}else
		this->getUltimo()->setPSiguiente(dobleTraccioncito);//sino al ultimo lo pongo a ver al nuevo
	
	dobleTraccioncito->setPSiguiente(NULL);//y al nuevo lo pongo a ver a NULL
}


bool ListaVehiculo::EliminarPorPlaca(string np){
	Vehiculo *aux=this->getDummy();
	if(this->isEmpty())
		return false;
	else if(this->getDummy()->getPSiguiente()==NULL && this->getDummy()->getNumeroDePlaca()==np){//si es el primero
		this->EliminarPrimero();
			return true;
	}else if(this->getUltimo()->getNumeroDePlaca()==np){//si es el ultimo
		this->eliminalAlFinal();
		return true;
	}else if(this->len()>=2){
		Vehiculo *aux;
		Vehiculo *anterior;
		int i=1;
		for(aux = this->getDummy(); aux->getPSiguiente()!=NULL; aux=aux->getPSiguiente()){
			if(aux->getNumeroDePlaca()==np)
				break;
			i++;
		}
		if(this->getDummy()->getNumeroDePlaca()==np){
			this->EliminarPrimero();
			return true;
		}else{
		aux = this->getN(i);
		anterior = this->getN(i-1);
		anterior->setPSiguiente(aux->getPSiguiente());
		delete aux;
		return true;
		}
	}else		
		return false;
}

void ListaVehiculo::EliminarPrimero(){
	if(this->isEmpty()!=true){
	Vehiculo *aux=this->getDummy();
	this->setDummy(aux->getPSiguiente());
	delete aux;
	}
}


Vehiculo* ListaVehiculo::getN(int n){//obtengo el elemento n q me de la gana de la madre
		if(n>0 && n<=this->len() && !(this->isEmpty())){//si n es mayor a 0, y n es menor que la cantidad de elementos y en la lista hay algo
			Vehiculo *aux = this->getDummy();//pongo al aux a ver al primer elemento
			for(int i=1; i!=n; i++){//recorro la madre hasta q encuentre la posision deseada
				aux = aux->getPSiguiente();//avanzo en la lista
			}
			return aux;// retorno el n elemento
		}else{return NULL;}//si no escupo un null
	}


void ListaVehiculo::eliminalAlFinal(){
	if(this->isEmpty() == true){
		cout<<"La lista esta vacia"<<endl;
	}else{
		int n = this->len();
		Vehiculo* aux = this->getN(n);
		Vehiculo* anterior = this->getN(n-1);
		anterior->setPSiguiente(aux->getPSiguiente());
		delete aux;
	}
}
	
void ListaVehiculo::MostrarTodosLosVehiculos(){
	Vehiculo* aux=NULL;
	int i=4;
	string tipo;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	gotoxy(22,1);
	cout<<"*** REPORTE DE TODOS LOS VEHICULOS ***";
	for(aux = this->getDummy(); aux!=NULL; aux=aux->getPSiguiente()){
		aux->toString(i);	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);	
		gotoxy(58,3);cout<<"Tipo              ";
		tipo= typeid(*aux).name();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);		
		gotoxy(58,i);
		if(tipo=="class Sedan")
			cout<<"Sedan";
		else if(tipo=="class Bus")
			cout<<"Bus";			
		else 
			cout<<"Doble Traccion";
		i++;
	}
}
	
void ListaVehiculo::MostrarTodosLosBuses(){
	Vehiculo* aux;
	int i=4;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	gotoxy(25,1);
	cout<<"*** REPORTE DE BUSES ***";
	for(aux = this->getDummy(); aux!=NULL; aux=aux->getPSiguiente()){
		if(aux->tipo()==3){
			aux->toString(i);
			i++;
		}			
	}
}

void ListaVehiculo::MostrarTodosLosDobleTraccion(){
	Vehiculo* aux;
	int i=4;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	gotoxy(22,1);
	cout<<"*** REPORTE DE DOBLE TRACCION ***";
	for(aux = this->getDummy(); aux!=NULL; aux=aux->getPSiguiente()){
		if(aux->tipo()==2){
			aux->toString(i);
			i++;
		}
			
	}
}

void ListaVehiculo::MostrarTodosLosSedanes(){
	Vehiculo* aux=NULL;
	int i=4;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	gotoxy(25,1);
	cout<<"*** REPORTE DE SEDANES ***";
	for(aux = this->getDummy(); aux!=NULL; aux=aux->getPSiguiente()){
		if(aux->tipo()==1){
			aux->toString(i);
			i++;
		}
	}
}

void ListaVehiculo::gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



bool ListaVehiculo::ValidaPlaca(string placa){
      if(this->isEmpty()== true){
            return true;
      }else{
            Vehiculo* aux;
            for(aux = this->getDummy(); aux!=NULL; aux = aux->getPSiguiente()){
                  if(aux->getNumeroDePlaca() == placa){
                        return false;
                        break;
                  }
            }
            return true;
      }
}


ListaVehiculo::~ListaVehiculo(){}
	