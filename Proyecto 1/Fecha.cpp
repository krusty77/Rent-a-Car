#include "Fecha.h"

Fecha::Fecha(){}
Fecha::~Fecha(){}

string Fecha::CalcularHoraActual(){	
        string lhora;
        stringstream a;
        time_t tSac = time(NULL);//instante actual del sistema
        struct tm* tmP = localtime(&tSac);//permite almacenar la hora
        a << tmP->tm_hour << ":" << tmP->tm_min << ":" << tmP->tm_sec;// permite separar toda la informacion y guardarla 
        lhora = a.str(); // permite convertir la hora a string
        return lhora;
}

string Fecha::CalcularFechaActual(){
		string lfecha;
		stringstream b; 
		time_t tSac = time(NULL);// instante actual
		struct tm* tmP = localtime(&tSac);
		b << tmP->tm_mday << "-" << tmP->tm_mon+1 << "-"<< tmP->tm_year+1900;
		lfecha = b.str();
		return lfecha;
}

int Fecha::ConvertirStringToInt(string f){
	int dv=0;
	dv = atoi(f.c_str());
	return dv;
}

int Fecha::dia(){
	string dia;
	int ldia = 0;
	stringstream b; 
	time_t tSac = time(NULL);// instante actual
	struct tm* tmP = localtime(&tSac);
	b<< tmP->tm_mday;
	dia = b.str();
	ldia = this->ConvertirStringToInt(dia);
	return ldia;
}
int Fecha::mes(){
	string mes;
	int lmes = 0;
	stringstream b; 
	time_t tSac = time(NULL);// instante actual
	struct tm* tmP = localtime(&tSac);
	b<< tmP->tm_mon+1;
	mes = b.str();
	lmes = this->ConvertirStringToInt(mes);
	return lmes;
}

int Fecha::año(){
	string año;
	int laño = 0;
	stringstream b; 
	time_t tSac = time(NULL);// instante actual
	struct tm* tmP = localtime(&tSac);
	b<< tmP->tm_year+1900;
	año = b.str();
	laño = this->ConvertirStringToInt(año);
	return laño;
}

int Fecha::sumaMes(int d){
	int dia = this->dia();
	int mes = this->mes();
	if(dia+d>30 && dia+d <=61){		
		return mes+1;
	}else if(dia+d<=30){		
		return mes;
	}else if(dia+d>61 && dia+d<=91){		
		return mes+2;
	}else if(dia+d>91 && dia+d<=122){
		return mes+3;
	}else if(dia+d>122 && dia+d<=153){
		return mes+4;
	}else if(dia+d>153 && dia+d<=183){		
		return mes+4;
	}else if(dia+d>183 && dia+d<=214){
		return mes+5;
	}else{return mes+6;}
}

int Fecha::sumaDias(int d){	
	int dia = this->dia();
	int mes = this->mes();
	if(dia+d<=30){
		return dia+d;
	}else if(dia+d>30 && dia+d <=61){
		return dia-d;
	}else if(dia+d>61 && dia+d<=91){		
		return dia-d;
	}else if(dia+d>91 && dia+d<=122){
		return dia-d;
	}else if(dia+d>122 && dia+d<=153){
		return dia-d;
	}else if(dia+d>153 && dia+d<=183){		
		return dia-d;
	}else if(dia+d>183 && dia+d<=214){
		return dia-d;
	}else{return dia-d;}
}