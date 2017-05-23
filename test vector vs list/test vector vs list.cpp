// test vector vs list.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <iterator>
#include "Temps.h"
#include <math.h>

using namespace std;

void calcul(float* var)
{
	*var = (1.0 / (1.0 + exp(-*var * 0.1))) * 2.0 - 1.0;
}

int main()
{
	float a = 1;
	float tv, tl;
	Temps t;
	vector <float*> v;
	list<float*> l;

	cout << "initilisation ... " << endl;
	for (int i = 0; i < 1000000; i++)
	{
		v.push_back(new float(1.0));
		l.push_back(new float(1.0));
	}
	cout << "terminee" << endl;



	cout << "parcours de l ... ";
	t.reset();
	t.start();
	for (list<float*>::iterator it = l.begin(); it != l.end(); it++)
	{
		calcul(*it);
	}
	t.stop();
	tl = t.getTime();
	cout << "temps = " << tl << endl;
	


	cout << "parcours de v ... ";
	t.reset();
	t.start();
	for (int i = 0; i < 1000000; i++)
	{
		calcul(v[i]);
	}
	t.stop();
	tv = t.getTime();
	cout << "temps = " << tv << endl;

	cout << "fraction tl/tv: " << tl / tv << endl;

	

	system("pause");
	return 0;
}

