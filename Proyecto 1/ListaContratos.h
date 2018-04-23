#pragma once
#include "Contrato.h"

class ListaContratos{
private:
	Contrato* dummy;
	Contrato* aux;

public:
	ListaContratos();
	Contrato* getDummy();
	void setDummy(Contrato*);
	void InsertarContrato(Contrato&);
	void MostarContratosActivos();
	void MostarContratosInactivos();
	void MostarTodosLosContratos(int);
	bool DesactivarPorCodigoContrato(int);
	bool isEmpty();
	Contrato* getUltimo();
	Contrato* BuscarCodContrato(int);
	bool ValidaCodContrato(int);
	void gotoxy(int,int);

	~ListaContratos();


};