#include <ctime>
#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h> 
using namespace std;
#pragma once

class Fecha{
public:
	Fecha();
	~Fecha();
	string CalcularHoraActual();
	string CalcularFechaActual();
	int ConvertirStringToInt(string);
	int dia();
	int mes();
	int año();
	int sumaDias(int);
	int sumaMes(int);
};