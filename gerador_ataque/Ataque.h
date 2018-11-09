#include<iostream>
#include "stdafx.h"
#pragma once

using namespace std;

class Ataque
{
public:
	Ataque();
	~Ataque();
	Ataque(int ataque);

	void setAtaque(int ataque);
	int getAtaque() { return ataque; }
private:
	int ataque;
};

