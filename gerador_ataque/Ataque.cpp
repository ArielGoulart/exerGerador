#include "Ataque.h"

Ataque::Ataque()
{
}

Ataque::~Ataque()
{
	cout << "destruct " << this->ataque << endl;
}

Ataque::Ataque(int ataque)
{
	this->ataque = ataque;
}

void Ataque::setAtaque(int ataque)
{
	this->ataque = ataque;
}
