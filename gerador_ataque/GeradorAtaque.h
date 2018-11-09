#include "Ataque.h"
#include "Processo.h"
#include "Random.h"
#pragma once

class GeradorAtaque : public Processo
{
public:
	static int cntr;

	GeradorAtaque();
	GeradorAtaque(int i, int nAtk, int tempo);
	~GeradorAtaque();
	void gerador(int i, int nAtk, int tempo);
};

