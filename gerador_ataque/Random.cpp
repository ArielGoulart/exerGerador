#include "Random.h"

Random::Random()
{
}

Random::~Random()
{
}

Random::Random(int c_mente, int c_multi, int c_adi, int mod)
{
	this->c_mente = c_mente;
	this->c_multi = c_multi;
	this->c_adi = c_adi;
	this->mod = mod;
}

double Random::rand()
{
	c_mente = (c_multi*c_mente + c_adi);
	return(double)(c_mente % mod) / (mod - 1);
}

double Random::uniform(double limInf, double limSup)
{
	double u = rand();
	return limInf + (limSup - limInf)*u;
}

double Random::exponencial(double media)
{
	double u = rand();

	return -media * log(1 - u);
}

double Random::normal(double media, double desvioPedrao)
{
	double u1 = rand();
	double u2 = rand();
	double v1, v2, w, y, x1, x2;

	v1 = 2 * u1 - 1;
	v2 = 2 * u2 - 1;

	w = pow(v1, 2) + pow(v2, 2);

	while (w > 1)
	{
		w = pow(v1, 2) + pow(v2, 2);
		if (w < 1)
		{
			break;
		}

		u1 = rand();
		u2 = rand();

		v1 = 2 * u1 - 1;
		v2 = 2 * u2 - 1;
	}

	y = sqrt((-2 * log(w)) / w);

	x1 = v1 * y;
	x2 = v2 * y;

	return media + desvioPedrao * x1;
}
