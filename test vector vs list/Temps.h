#pragma once

#include <time.h>

class Temps
{
private:
	clock_t top;
	clock_t tempsEcoule;

public:
	Temps();
	~Temps();
	void reset();
	void start();
	void stop();
	double getTime();
	double getTimeMs();
};

