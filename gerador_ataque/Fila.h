//Fila na verdade não precisa ser de Ataques, a fila será somente para a recarga de escudos
//Mudar Ataque para Escudo

#pragma once
#include <queue>
#include "Ataque.h"
#include <mutex>

using namespace std;

class Fila
{
	queue <Ataque *> fila;
	mutex queueMutex;

public:
	Fila();
	~Fila();
	void insert(Ataque *a);
	Ataque* getFirst();
	bool isEmpty();

};


