#include <math.h>
#pragma once
class Random
{
public:
	Random();
	~Random();
	Random(int c_mente, int c_multi, int c_adi, int mod);

	double rand();
	double uniform(double limInf, double limSup);
	double exponencial(double media);
	double normal(double media, double desvioPedrao);

	int getC_mente() { return c_mente; }
	int getC_multi() { return c_multi; }
	int getC_adi() { return c_adi; }
	int getMod() { return mod; }

private:
	unsigned int c_mente, c_multi, c_adi, mod;

};

