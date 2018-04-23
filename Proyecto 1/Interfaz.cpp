//Interfaz.cpp
#include "Interfaz.h"
#include "Windows.h"
#include <iostream>
using namespace std;

Interfaz::Interfaz(){}
Interfaz::~Interfaz(){}

	
void Interfaz::Presentacion(){
		cout<<endl<<endl<<endl;		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<"		:::    :::    ::::    :::        :::     "<<endl;
		cout<<"		:+:    :+:    :+:+:   :+:      :+: :+:   "<<endl;
		cout<<"		+:+    +:+    :+:+:+  +:+     +:+   +:+  "<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"		+#+    +:+    +#+ +:+ +#+    +#++:++#++: "<<endl;	
		cout<<"		+#+    +#+    +#+  +#+#+#    +#+     +#+ "<<endl;
		cout<<"		#+#    #+#    #+#   #+#+#    #+#     #+# "<<endl;
		cout<<"		 ########     ###    ####    ###     ### "<<endl;

		cout<<"		"<<endl;
		cout<<"		"<<endl;
		cout<<endl<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<"	  INTEGRANTES: "<<endl<<endl;	
		cout<<"		->EDUARDO SEQUEIRA	"<<endl;
		cout<<"		->RAFAELA HERNANDEZ "<<endl;	
		cout<<endl<<endl<<endl;
		system("pause");
}

void Interfaz::InsertarDatosEmpresa(){
		string nombre,cedula,telefono,direccion;
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
			gotoxy(22,1);
			cout<<"*** SISTEMA DE RENT- A -CAR ***"<<endl<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
			cout<<"Agregar Datos de la Empresa -->"<<endl<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			cout<<"Digite la Cedula Juridica: ";
			cin>>cedula;
			cout<<"Digite el Nombre: ";
			cin>>nombre;
			cout<<"Digite el Telefono: ";
			cin>>telefono;
			cout<<"Digite la Direccion: ";
			cin>>direccion;
			Empresa empresita (nombre,cedula,telefono,direccion);	
}


void Interfaz::MenuPrincipal(){
		int opcion=0;		
		while(opcion!=3){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			cout<<endl<<endl;
			cout<<"                                       ,,,                           "<<endl;
			cout<<"                                      (o o)                          "<<endl;
			cout<<"            =-=-=-=-=-=-=-=-=-=-=-oOOo-(_)-oOOo-=-=-=-=-=-=-=-=-=-=-="<<endl;
			cout<<"           															"<<endl;
			cout<<"                Eliga la opcion que desea ver						"<<endl;
			cout<<"            	       1. Menu de Vehiculos 							"<<endl;
			cout<<"            	       2. Menu de Contratos  			 				"<<endl;
			cout<<"            	       3. Salir											"<<endl;
			cout<<"				----->";
			gotoxy(39,15);
			cin>>opcion;
			switch(opcion){
				case 1:SubMenuVehiculos();break;
				case 2:SubMenuContratos();break;
				case 3:break;
				default:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);	
					gotoxy(20,18);
					cout<<"ERROR.... "<<opcion<<" no es una opcion valida";
					gotoxy(20,20);
					system("pause");
				break;
			}// stwitch
		}//while
}


void Interfaz::SubMenuVehiculos(){
	int opcion=0;	
	while(opcion!=5){
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<endl<<endl;		
		cout<<"                                       ,,,                           "<<endl;
		cout<<"                                      (o o)                          "<<endl;
		cout<<"            =-=-=-=-=-=-=-=-=-=-=-oOOo-(_)-oOOo-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"           															"<<endl;
		cout<<"                Eliga la opcion que desea							"<<endl;
		cout<<"            	       1. Ingresar Vehiculo Nuevo						"<<endl;
		cout<<"            	       2. Eliminar Vehiculo			 					"<<endl;
		cout<<"            	       3. Actualizar Vehiculo							"<<endl;
		cout<<"            	       4. Mostar Reporte de Vehiculo por Tipo 			"<<endl;
		cout<<"            	       5. Regresar										"<<endl;
		cout<<"				----->";
		gotoxy(39,19);
		cin>>opcion;
		switch(opcion){
			case 1:RegistarVehiculo();break;
			case 2:EliminarVehiculo();break;
			case 3:ActualizarVehiculo();break;
			case 4:MostrarVehiculos();break;
			case 5:break;
			default:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);	
				gotoxy(20,22);
				cout<<"ERROR.... "<<opcion<<" no es una opcion valida";
				gotoxy(20,23);
				system("pause");
			break;
		}// stwitch
	}//while
}

void Interfaz::RegistarVehiculo(){
	string numPlaca,marca,modelo,color;
	int numPuertas,numAientos,opcion=0,tpoCombustible;
	while(opcion!=4){
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
		cout<<endl<<endl;
		cout<<"                                       ,,,                           "<<endl;
		cout<<"                                      (o o)                          "<<endl;
		cout<<"            =-=-=-=-=-=-=-=-=-=-=-oOOo-(_)-oOOo-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"           															"<<endl;
		cout<<"                Eliga el tipo de Vehiculo que desea Ingresar			"<<endl;
		cout<<"            	       1. Sedan				 							"<<endl;
		cout<<"            	       2. Doble Traccion	  			 				"<<endl;
		cout<<"            	       3. Bus											"<<endl;
		cout<<"            	       4. Regresar										"<<endl;
		cout<<"				----->";
		gotoxy(39,17);
		cin>>opcion;		
		if(opcion<4){	
			system("cls");
			do{				
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
				cout<<"Digite el Numero de Placa: ";
				cin>>numPlaca;
				if(this->lv.ValidaPlaca(numPlaca)==false){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
					cout<<"LA PLACA "<<numPlaca<<" YA ESTA EN NUESTROS REGISTROS FAVOR DIGITE OTRA PLACA "<<endl<<endl;
				}
			}while(this->lv.ValidaPlaca(numPlaca)==false);
			cout<<"Digite la Marca: ";
			cin>>marca;
			cout<<"Digite el Modelo: ";
			cin>>modelo;
			cout<<"Digite el color del Vehiculo: ";
			cin>>color;
		}
		switch(opcion){
			case 1:	
				cout<<"Digite el Numero de Numero de Puertas: ";
				cin>>numPuertas;	
				lv.InsertarSedan(numPlaca,marca,modelo,color,numPuertas);
			break;
			case 2:
				cout<<"Digite el Tipo de Combustible-->"<<endl;
				cout<<" 1 para GASOLINA SUPER "<<endl;
				cout<<" 2 para GASOLINA REGULAR"<<endl;				
				cout<<" 3 para DIESEL"<<endl;
				cout<<"  -->";
				cin>>tpoCombustible;	
				lv.InsertarDobleTraccion(numPlaca,marca,modelo,color,tpoCombustible);	
			break;
			case 3:
				cout<<"Digite el Numero de Asientos: ";
				cin>>numAientos;	
				lv.InsertarBus(numPlaca,marca,modelo,color,numAientos);	
			break;
			case 4: break;
			default: 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				gotoxy(20,19);
				cout<<"ERROR.... "<<opcion<<" no es una opcion valida";
				gotoxy(20,21);
				system("pause");
				break;
			}// stwitch
	
	}//while
}


void Interfaz::EliminarVehiculo(){	
		system("cls");
		if(lv.isEmpty()==false){
		string numPlaca;
		lv.MostrarTodosLosVehiculos();
		cout<<endl<<endl;
		do{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			cout<<"Digite la placa del vehiculo que desea eliminar: ";	
			cin>>numPlaca;
			if(this->lv.BuscarporPlaca(numPlaca)==NULL){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);	
				cout<<"LA PLACA "<<numPlaca<<" NO EXISTE EN NUESTROS REGISTROS FAVOR DIGITE OTRA PLACA "<<endl<<endl;
			}
		}while(this->lv.BuscarporPlaca(numPlaca)==NULL);
		
		if(lv.EliminarPorPlaca(numPlaca)==true){
			system("cls");
			lv.MostrarTodosLosVehiculos();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<endl<<endl<<"El Vehiculo con la Placa "<<numPlaca<<"  ha sido Eliminado"<<endl;
			}
		}
	else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<endl<<endl<<"ERROR...  NO EXISTE NINGUN VEHICULO PARA ELIMINAR ";	
		}
	cout<<endl;system("pause");
	
}

void Interfaz::ActualizarVehiculo(){
int opcion=0;
	if(lv.isEmpty()==false){
		while(opcion!=4){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			cout<<endl<<endl;
			cout<<"                                       ,,,                           "<<endl;
			cout<<"                                      (o o)                          "<<endl;
			cout<<"            =-=-=-=-=-=-=-=-=-=-=-oOOo-(_)-oOOo-=-=-=-=-=-=-=-=-=-=-="<<endl;
			cout<<"           															"<<endl;
			cout<<"                Eliga el tipo de Vehiculo para Actualizar			"<<endl;
			cout<<"            	       1. Sedan				 							"<<endl;
			cout<<"            	       2. Doble Traccion	  			 				"<<endl;
			cout<<"            	       3. Bus											"<<endl;
			cout<<"            	       4. Regresar										"<<endl;
			cout<<"				----->";
			gotoxy(39,17);
			cin>>opcion;
			if(opcion>0 && opcion<4)
				system("cls");		
			switch(opcion){
				case 1:ActualizarSedan();break;
				case 2:ActualizarDobleTraccion();break;
				case 3:ActualizarBus();break;
				case 4:break;
				default:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
					gotoxy(20,19);
					cout<<"ERROR.... "<<opcion<<" no es una opcion valida";
					gotoxy(20,21);
					system("pause");
				break;			
				
			}// stwitch			
		}//while
	}
	else{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<endl<<endl<<"ERROR...  NO EXISTE NINGUN VEHICULO PARA ACTUALIZAR "<<endl<<endl;	
		system("pause");
	}
}

void Interfaz::ActualizarSedan(){
	int numPuertas,opcion = 0;
	string marca,modelo,color,np;
	lv.MostrarTodosLosSedanes();
	cout<<endl<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	cout<<"Digite la placa del vehiculo que desea Actualizar: ";	
	cin>>np;
	if(lv.BuscarporPlaca(np)!=NULL){
		while(opcion!=5){
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
		cout<<"                                       ,,,                           "<<endl;
		cout<<"                                      (o o)                          "<<endl;
		cout<<"            =-=-=-=-=-=-=-=-=-=-=-oOOo-(_)-oOOo-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"           															"<<endl;
		cout<<"                Eliga el tipo de Atributo para Actualizar			"<<endl;
		cout<<"            	       1. Marca				 							"<<endl;
		cout<<"            	       2. Modelo	        			 				"<<endl;
		cout<<"            	       3. Color											"<<endl;
		cout<<"            	       4. Numero de Puertas								"<<endl;
		cout<<"            	       5. Regresar										"<<endl;
		cout<<"				----->";
		gotoxy(39,17);
		cin>>opcion;
		if(opcion<5)
			system("cls");
		switch(opcion){
			case 1:	
				cout<<"Digite la nueva marca: ";
				cin>>marca;	
				lv.BuscarporPlaca(np)->setMarca(marca);
			break;
			case 2:
				cout<<"Digite el nuevo modelo: ";
				cin>>modelo;	
				lv.BuscarporPlaca(np)->setModelo(modelo);	
			break;
			case 3:
				cout<<"Digite el nuevo color: ";
				cin>>color;	
				lv.BuscarporPlaca(np)->setColor(color);	
			break;
			case 4:
				cout<<"Digite el numero de puertas: ";
				cin>>numPuertas;	
				lv.BuscarporPlaca(np)->Modificar(numPuertas);
			break;
			case 5: break;
			default: 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				gotoxy(20,19);
				cout<<"ERROR.... "<<opcion<<" no es una opcion valida";
				gotoxy(20,21);
				system("pause");
				break;
			}// stwitch			
			if(opcion<5){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
			cout<<"Atributo Modificado..."<<endl<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			system("pause");		
			}
		}//while
	}
	else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<endl<<endl<<"ERROR...  No existe Ningun Vehiculo con la Placa "<<np<<"";
		cout<<endl<<endl;system("pause");
	}	
}



void Interfaz::ActualizarBus(){
	int numAsientos, opcion = 0;
	string marca,modelo,color,np;
	lv.MostrarTodosLosBuses();
	cout<<endl<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	cout<<"Digite la placa del vehiculo que desea Actualizar: ";	
	cin>>np;
	if(lv.BuscarporPlaca(np)!=NULL){
		while(opcion!=5){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			cout<<"                                       ,,,                           "<<endl;
			cout<<"                                      (o o)                          "<<endl;
			cout<<"            =-=-=-=-=-=-=-=-=-=-=-oOOo-(_)-oOOo-=-=-=-=-=-=-=-=-=-=-="<<endl;
			cout<<"           															"<<endl;
			cout<<"                Eliga el tipo de Atributo para Actualizar			"<<endl;
			cout<<"            	       1. Marca				 							"<<endl;
			cout<<"            	       2. Modelo	        			 				"<<endl;
			cout<<"            	       3. Color											"<<endl;
			cout<<"            	       4. Numero de Asientos							"<<endl;
			cout<<"            	       5. Regresar										"<<endl;
			cout<<"				----->";
			gotoxy(39,17);
			cin>>opcion;
			if(opcion<5)
				system("cls");
			switch(opcion){
				case 1:	
					cout<<"Digite la nueva marca: ";
					cin>>marca;	
					lv.BuscarporPlaca(np)->setMarca(marca);
				break;
				case 2:
					cout<<"Digite el nuevo modelo: ";
					cin>>modelo;	
					lv.BuscarporPlaca(np)->setModelo(modelo);	
				break;
				case 3:
					cout<<"Digite el nuevo color: ";
					cin>>color;	
					lv.BuscarporPlaca(np)->setColor(color);	
				break;
				case 4:
					cout<<"Digite el numero de asientos: ";
					cin>>numAsientos;	
					lv.BuscarporPlaca(np)->Modificar(numAsientos);	
				break;
				case 5: break;
				default: 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
					gotoxy(20,19);
					cout<<"ERROR.... "<<opcion<<" no es una opcion valida";
					gotoxy(20,21);
					system("pause");
					break;
			}// stwitch			
			if(opcion<5){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
			cout<<"Atributo Modificado..."<<endl<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			system("pause");		
			}
		}//while
	}
	else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<endl<<endl<<"ERROR...  No existe Ningun Vehiculo con la Placa "<<np<<"";
		cout<<endl<<endl;system("pause");
	}	
}


void Interfaz::ActualizarDobleTraccion(){
	int tc, opcion = 0;
	string marca,modelo,color,np;
	lv.MostrarTodosLosDobleTraccion();
	cout<<endl<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	cout<<"Digite la placa del vehiculo que desea Actualizar: ";	
	cin>>np;
	if(lv.BuscarporPlaca(np)!=NULL){
	while(opcion!=5){
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
		cout<<"                                       ,,,                           "<<endl;
		cout<<"                                      (o o)                          "<<endl;
		cout<<"            =-=-=-=-=-=-=-=-=-=-=-oOOo-(_)-oOOo-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"           															"<<endl;
		cout<<"                Eliga el tipo de Atributo para Actualizar			"<<endl;
		cout<<"            	       1. Marca				 							"<<endl;
		cout<<"            	       2. Modelo	        			 				"<<endl;
		cout<<"            	       3. Color											"<<endl;
		cout<<"            	       4. Tipo de Combustible							"<<endl;
		cout<<"            	       5. Regresar										"<<endl;
		cout<<"				----->";
		gotoxy(39,17);
		cin>>opcion;
		if(opcion<5)
			system("cls");
		switch(opcion){
			case 1:	
				cout<<"Digite la nueva marca: ";
				cin>>marca;	
				lv.BuscarporPlaca(np)->setMarca(marca);
			break;
			case 2:
				cout<<"Digite el nuevo modelo: ";
				cin>>modelo;	
				lv.BuscarporPlaca(np)->setModelo(modelo);	
			break;
			case 3:
				cout<<"Digite el nuevo color: ";
				cin>>color;	
				lv.BuscarporPlaca(np)->setColor(color);	
			break;
			case 4:
				cout<<"Digite el Tipo de Combustible -->"<<endl;
				cout<<" 1 para GASOLINA SUPER"<<endl;
				cout<<" 2 para GASOLINA REGULAR"<<endl;				
				cout<<" 3 para DIESEL"<<endl;
				cout<<"  -->";
				cin>>tc;	
				lv.BuscarporPlaca(np)->Modificar(tc);	
			break;
			case 5: break;
			default: 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				gotoxy(20,19);
				cout<<"ERROR.... "<<opcion<<" no es una opcion valida";
				gotoxy(20,21);
				system("pause");
				break;
			}// stwitch			
			if(opcion<5){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
			cout<<"Atributo Modificado..."<<endl<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			system("pause");		
			}
		}//while
	}
	else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<endl<<endl<<"ERROR...  No existe Ningun Vehiculo con la Placa "<<np<<"";
		cout<<endl<<endl;system("pause");
	}	
}



void Interfaz::MostrarVehiculos(){	
	int opcion=0;
	if(lv.isEmpty()==false){
		while(opcion!=4){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			cout<<endl<<endl;
			cout<<"                                       ,,,                           "<<endl;
			cout<<"                                      (o o)                          "<<endl;
			cout<<"            =-=-=-=-=-=-=-=-=-=-=-oOOo-(_)-oOOo-=-=-=-=-=-=-=-=-=-=-="<<endl;
			cout<<"           															"<<endl;
			cout<<"                Eliga el tipo de Reporte de Vehiculo					"<<endl;
			cout<<"            	       1. Sedan				 							"<<endl;
			cout<<"            	       2. Doble Traccion	  			 				"<<endl;
			cout<<"            	       3. Bus											"<<endl;
			cout<<"            	       4. Regresar										"<<endl;
			cout<<"				----->";
			gotoxy(39,17);
			cin>>opcion;
			if(opcion>0 && opcion<4)
				system("cls");		
			switch(opcion){
				case 1:lv.MostrarTodosLosSedanes();cout<<endl<<endl<<endl;system("pause");break;
				case 2:lv.MostrarTodosLosDobleTraccion();cout<<endl<<endl<<endl;system("pause");break;
				case 3:lv.MostrarTodosLosBuses();cout<<endl<<endl<<endl;system("pause");break;
				case 4:break;
				default:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
					gotoxy(20,19);
					cout<<"ERROR.... "<<opcion<<" no es una opcion valida";
					gotoxy(20,21);
					system("pause");
				break;			
				
			}// stwitch			
		}//while
	}
	else{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<endl<<endl<<"ERROR...  NO EXISTE NINGUN VEHICULO PARA MOSTRAR "<<endl<<endl;	
		system("pause");
	}
	
}


void Interfaz::SubMenuContratos(){
	int opcion=0;	
	while(opcion!=5){
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
		cout<<endl<<endl;		
		cout<<"                                       ,,,                           "<<endl;
		cout<<"                                      (o o)                          "<<endl;
		cout<<"            =-=-=-=-=-=-=-=-=-=-=-oOOo-(_)-oOOo-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"           															"<<endl;
		cout<<"                Digite la opcion que desea							"<<endl;
		cout<<"            	       1. Crear Contrato Nuevo							"<<endl;
		cout<<"            	       2. Desactivar Contrato		 					"<<endl;
		cout<<"            	       3. Mostar Reporte de Contratos Activos			"<<endl;
		cout<<"            	       4. Mostar Reporte de Contatos General			"<<endl;
		cout<<"            	       5. Regresar										"<<endl;
		cout<<"				----->";
		gotoxy(39,19);
		cin>>opcion;
		switch(opcion){
			case 1:CrearContrato();	break;
			case 2:DesactivarContrato();break;
			case 3:MostarContratosActivos();break;
			case 4:MostarContratoGeneral();break;
			case 5:break;
			break;
			default:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);	
				gotoxy(20,22);
				cout<<"ERROR.... "<<opcion<<" no es una opcion valida";
				gotoxy(20,23);
				system("pause");
			break;
		}// stwitch
	}//while
}
void Interfaz::CrearContrato(){
	system("cls");
	if(lv.isEmpty()==false){
		string nombre,cedula,telefono,direccion;
		int numContrato,pago,tpoVehiculo=0,dias =0, ldia, lmes;
		bool tpoPago=false,tp=false;
		Vehiculo* vAlquilado=NULL;
		
		gotoxy(0,1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);		
		cout<<"Seleccione el tipo de Vehiculo que desea Alquilar: "<<endl;
		cout<<" 1- Sedan"<<endl;
		cout<<" 2- Doble Traccion"<<endl;
		cout<<" 3- Bus"<<endl;
		cout<<"-->";
		cin>>tpoVehiculo;
		if(tpoVehiculo==1)
			vAlquilado=lv.AlquilarSedan();
		else {
			if(tpoVehiculo==2)
			vAlquilado=lv.AlquilarDobleTraccion();
			else
			vAlquilado=lv.AlquilarBus();
		}
			

		if(vAlquilado!=NULL){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
			gotoxy(22,1);
			cout<<"*** CREAR NUEVO CONTRATO ***"<<endl<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			gotoxy(0,3);
			do{				
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
				cout<<"Digite el Numero de Contrato: ";
				cin>>numContrato;
				if(this->lc.ValidaCodContrato(numContrato)==false){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
					cout<<"EL CONTRATO "<<numContrato<<" YA ESTA EN NUESTROS REGISTROS, FAVOR DIGITE OTRO NUMERO: "<<endl<<endl;
				}
			}while(this->lc.ValidaCodContrato(numContrato)==false);			
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
			gotoxy(22,1);
			cout<<"*** CREAR NUEVO CONTRATO ***"<<endl<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
			cout<<"Agregar Datos del Cliente -->"<<endl<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			cout<<"Digite la Cedula del Cliente: ";
			cin>>cedula;
			cout<<"Digite el Nombre: ";
			cin>>nombre;
			cout<<"Digite el Telefono: ";
			cin>>telefono;
			cout<<"Digite la Direccion: ";
			cin>>direccion;
			cout<<"Digite el numero de dias a alquilar: ";
			cin>>dias;
			ldia = f.sumaDias(dias);
			lmes = f.sumaMes(dias);
			do{	
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
				cout<<"Digite el numero segun la forma de pago: "<<endl;
				cout<<"  1- Tarjeta"<<endl;
				cout<<"  2- Efectivo"<<endl;
				cout<<"-->";
				cin>>pago;
				if(pago==1 || pago==2){
					if(pago==1)
						tpoPago=true;
					else
						tpoPago=false;
					tp=true;
				}
				else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
					cout<<"LA FORMA DE PAGO "<<pago<<" ES INVALIDA, FAVOR DIGITE OTRO NUMERO"<<endl<<endl;
					tp=false;					
				}									
			}while(tp==false);		
			
			Cliente	custumer(nombre,cedula,telefono,direccion,tpoPago);	
			Contrato contratito(numContrato,ldia,lmes,dias,custumer,vAlquilado);
				lc.InsertarContrato(contratito);	
			MostarFactura(custumer,contratito,dias);
		}else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<endl<<"ERROR... El  TIPO DE VEHICULO NO ESTA DISPONIBLE PARA ALQUILAR"<<endl<<endl;
		}
	}else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<endl<<"ERROR...NO EXISTEN VEHICULOS PARA ALQUILAR"<<endl<<endl;		
	}
	system("pause");

}	



void Interfaz::MostarFactura(Cliente custumer,Contrato contratito, int dias){
		system("cls");
		int tp;
		double total,monto;
		string tpoVehiculo;
		tp=contratito.getVehiculo()->tipo();
		if(tp==1){
			tpoVehiculo="Sedan";
			total=contratito.calcularMontoPagarSedan(dias);
			monto=75.00;
		}else	if(tp==2){
			tpoVehiculo="Doble Traccion";
			total=contratito.calcularMontoPagarDobleTraccion(dias);
			monto=100.00;
		}else{
			tpoVehiculo="Bus";
			total=contratito.calcularMontoPagarBus(dias);
			monto=200.00;
		}
			

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7 ); 
		// Dibujar Marco
		gotoxy(9,2);cout<<"|";gotoxy(75,2);cout<<"|";
		gotoxy(9,3);cout<<"|";gotoxy(75,3);cout<<"|";		
		gotoxy(9,4);cout<<"|";gotoxy(75,4);cout<<"|";
		gotoxy(9,5);cout<<"|";gotoxy(75,5);cout<<"|";
		gotoxy(9,6);cout<<"|";gotoxy(75,6);cout<<"|";
		gotoxy(9,7);cout<<"|";gotoxy(75,7);cout<<"|";
		gotoxy(9,8);cout<<"|";gotoxy(75,8);cout<<"|";
		gotoxy(9,9);cout<<"|";gotoxy(75,9);cout<<"|";
		gotoxy(9,10);cout<<"|";gotoxy(75,10);cout<<"|";
		gotoxy(9,11);cout<<"|";gotoxy(75,11);cout<<"|";		
		gotoxy(9,12);cout<<"|";gotoxy(75,12);cout<<"|";
		gotoxy(9,13);cout<<"|";gotoxy(75,13);cout<<"|";
		gotoxy(9,14);cout<<"|";gotoxy(75,14);cout<<"|";
		gotoxy(9,15);cout<<"|";gotoxy(75,15);cout<<"|";
		gotoxy(9,16);cout<<"|";gotoxy(75,16);cout<<"|";
		gotoxy(9,17);cout<<"|";gotoxy(75,17);cout<<"|";
		gotoxy(9,18);cout<<"|";gotoxy(75,18);cout<<"|";
		gotoxy(9,19);cout<<"|";gotoxy(75,19);cout<<"|";
		gotoxy(9,20);cout<<"|";gotoxy(75,20);cout<<"|";
		gotoxy(9,21);cout<<"|";gotoxy(75,21);cout<<"|";		
		gotoxy(9,22);cout<<"|";gotoxy(75,22);cout<<"|";
		gotoxy(9,23);cout<<"|";gotoxy(75,23);cout<<"|";
		gotoxy(9,24);cout<<"|";gotoxy(75,24);cout<<"|";
		gotoxy(9,25);cout<<"|";gotoxy(75,25);cout<<"|";

		contratito.getVehiculo()->tipo();
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7 );	
		gotoxy(9,1);
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-==-=-=";
		gotoxy(35,3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5 );
		cout<<"RENT-A-CAR";	
		gotoxy(30,5);
		cout<<"FACTURA DE CANCELACION ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8 );
		gotoxy(11,7);		
		cout<<"Codigo Prestamo: "<<contratito.getCodContrato();
		gotoxy(45,7);
		cout<<"Fecha Prestamo: "<<contratito.getFechaPrestamo();
		gotoxy(11,9);
		cout<<"Cedula Cliente: "<<custumer.getCedula();
		gotoxy(45,9);
		cout<<"Nombre: "<<custumer.getNombre();
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6 );
		gotoxy(12,12);		
		cout<<"-------------------------------------------------------------";			
		gotoxy(28,12);
		cout<<" DESCRIPCION DEL ALQUILER ";
		gotoxy(11,14);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8 );
		cout<<"Placa Vehiculo: "<<contratito.getVehiculo()->getNumeroDePlaca();
		gotoxy(45,14);
		cout<<"Tipo Vehiculo: "<<tpoVehiculo;
		gotoxy(11,16);
		cout<<"Dias Alquiler: "<<dias;
		gotoxy(45,16);
		cout<<"Fecha Devoluccion: "<<contratito.getDiaDevoluccion()<<"-"<<contratito.getMesDevoluccion()<<"-"<<f.año();
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4 );	
		gotoxy(28,19);
		cout<<"---------- TOTALES ----------";
		gotoxy(11,21);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8 );
		cout<<"Monto Desembolso: $"<<monto;
		gotoxy(11,23);
		cout<<"Total a Pagar: "<<total;
		gotoxy(9,25);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7 );	
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-==-=-="<<endl;	
	
	}

void Interfaz::MostarContratosActivos(){
	int opcion=0;
	if(lc.isEmpty()==false)
		while(opcion!=4){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			cout<<endl<<endl;
			cout<<"                                       ,,,                           "<<endl;
			cout<<"                                      (o o)                          "<<endl;
			cout<<"            =-=-=-=-=-=-=-=-=-=-=-oOOo-(_)-oOOo-=-=-=-=-=-=-=-=-=-=-="<<endl;
			cout<<"           															"<<endl;
			cout<<"                Eliga el tipo de Contrato que desea ver				"<<endl;
			cout<<"            	       1. Sedan				 							"<<endl;
			cout<<"            	       2. Doble Traccion	  			 				"<<endl;
			cout<<"            	       3. Bus											"<<endl;
			cout<<"            	       4. Regresar										"<<endl;
			cout<<"				----->";
			gotoxy(39,17);
			cin>>opcion;
			if(opcion>0 && opcion<4)
				system("cls");		
			switch(opcion){
				case 1:lc.MostarTodosLosContratos(opcion);cout<<endl<<endl<<endl;system("pause");break;
				case 2:lc.MostarTodosLosContratos(opcion);cout<<endl<<endl<<endl;system("pause");break;
				case 3:lc.MostarTodosLosContratos(opcion);cout<<endl<<endl<<endl;system("pause");break;
				case 4:break;
				default:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
					gotoxy(20,19);
					cout<<"ERROR.... "<<opcion<<" no es una opcion valida";
					gotoxy(20,21);
					system("pause");
				break;			
				
			}// stwitch			
		}//while
	else{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<endl<<endl<<"ERROR...  NO EXISTE NINGUN CONTRATO PARA MOSTRAR "<<endl;
		system("pause");
	}
}


void Interfaz::MostarContratoGeneral(){
	if(lc.isEmpty()==false){
		int opcion=0;		
		while(opcion!=3){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			cout<<endl<<endl;		
			cout<<"                                       ,,,                           "<<endl;
			cout<<"                                      (o o)                          "<<endl;
			cout<<"            =-=-=-=-=-=-=-=-=-=-=-oOOo-(_)-oOOo-=-=-=-=-=-=-=-=-=-=-="<<endl;
			cout<<"           															"<<endl;
			cout<<"                Digite la opcion que desea							"<<endl;
			cout<<"            	       1. Mostar Reporte de Contratos Activos			"<<endl;
			cout<<"            	       2. Mostar Reporte de Contatos Inactivos			"<<endl;
			cout<<"            	       3. Salir											"<<endl;
			cout<<"				----->";
			gotoxy(39,15);
			cin>>opcion;
			if(opcion>0 && opcion<3)
				system("cls");	
			switch(opcion){
				case 1:lc.MostarContratosActivos();cout<<endl<<endl<<endl;system("pause");break;
				case 2:lc.MostarContratosInactivos();cout<<endl<<endl<<endl;system("pause");break;
				case 3:break;
				break;
				default:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);	
					gotoxy(20,22);
					cout<<"ERROR.... "<<opcion<<" no es una opcion valida";
					gotoxy(20,23);
					system("pause");
				break;
			}// stwitch
		}//while


	}
	else{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<endl<<endl<<"ERROR...  NO EXISTE NINGUN CONTRATO PARA MOSTRAR "<<endl;	
		system("pause");
	}

}

void Interfaz::DesactivarContrato(){
	if(lc.isEmpty()==false){
		int numContrato=0,tp,monto;	
		Contrato* c;
			system("cls");
			lc.MostarContratosActivos();
			cout<<endl<<endl;
			do{				
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
				cout<<"Digite el  Numero de Contrato que desea Desactivar: ";
				cin>>numContrato;
			if(this->lc.ValidaCodContrato(numContrato)==true){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
					cout<<"EL CONTRATO "<<numContrato<<" NO EXISTE EN NUESTROS REGISTROS, FAVOR DIGITE OTRO NUMERO"<<endl<<endl;
				}
			}while(this->lc.ValidaCodContrato(numContrato)==true);
	
			lc.DesactivarPorCodigoContrato(numContrato);
			
			c=lc.BuscarCodContrato(numContrato);
			tp=c->getVehiculo()->tipo();		
			if(tp==1)
				monto=75;
			else	if(tp==2)
				monto=100;
			else
				monto=200;
			
			system("cls");
			lc.MostarContratosActivos();
			cout<<endl<<endl<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"EL CONTRATO "<<numContrato<<" HA SIDO DESACTIVADO.... El MONTO DE SU DESEMBOLSO ES  $"<<monto<<".00"<<endl;
			system("pause");
	}
	else{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<endl<<endl<<"ERROR...  NO EXISTE NINGUN CONTRATO PARA DESACTIVAR "<<endl;	
		system("pause");
	}
}


void Interfaz::gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


	