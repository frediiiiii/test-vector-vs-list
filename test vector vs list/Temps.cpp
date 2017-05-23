#include <iostream>
#include <stdio.h>
#include "stdafx.h"
#include "Temps.h"

using namespace std;

Temps::Temps()
{
	tempsEcoule = 0;
	top = 0;
}


Temps::~Temps()
{
}

void Temps::reset()
{
	tempsEcoule = 0;
}

void Temps::start()
{
	top = clock();
}

void Temps::stop()
{
	if (top != 0)
	{
		tempsEcoule += clock() - top;
		top = 0;
	}
	else
	{
		//cout << "OUPS : start time before stopping it" << endl;
	}
}

double Temps::getTime()
{
	return tempsEcoule / 1000.0;
}

double Temps::getTimeMs()
{
	return tempsEcoule;
}
