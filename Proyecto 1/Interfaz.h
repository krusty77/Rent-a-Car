#include "ListaVehiculo.h"
#include "ListaContratos.h"
#include "Cliente.h"
#include "Contrato.h"
#include "Empresa.h"
#pragma once

class Interfaz{
private:
	Fecha f;
	ListaVehiculo lv;
	ListaContratos lc;
public:
	Interfaz();
	~Interfaz();
	void Presentacion();
	void InsertarDatosEmpresa();
	void MenuPrincipal();
	void SubMenuVehiculos();
	void RegistarVehiculo();
	void EliminarVehiculo();
	void ActualizarVehiculo();
	void ActualizarSedan();
	void ActualizarBus();
	void ActualizarDobleTraccion();
	void MostrarVehiculos();	
	void SubMenuContratos();
	void CrearContrato();
	void gotoxy(int,int);
	void DesactivarContrato();
	void MostarContratosActivos();
	void MostarContratoGeneral();
	void MostarFactura(Cliente,Contrato,int);
		
	
};