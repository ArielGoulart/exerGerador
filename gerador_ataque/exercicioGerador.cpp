#include "stdafx.h"

#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <mutex>
#include "GeradorAtaque.h"
#include"Random.h"
#include "Fila.h"

using namespace std;

//variavel tempoInicial e funcao getClock foram reimplementadas dentro da classe Processo.
//podem ser usadas aqui para capturar a passagem de tempo dentro do main...
std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration> tempoInicial;

long getClock() 
{
	return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - tempoInicial).count();
}

int _tmain(int argc, _TCHAR* argv[])
{	
	srand(time(0));
	tempoInicial = std::chrono::system_clock::now();
	
	Random *random;
	GeradorAtaque *gAtk[10];
		
	// Aqui Começa a Gerar os Geradores de Ataque com tempos diferentes
	for (int i = 0; i < 10; i++)
	{		
		random = new Random(rand() % 10 + 72, rand() % 10 + 48271, 0, rand() % 10 + 2147483647);
		this_thread::sleep_for(std::chrono::seconds((int)(random->normal(5, 3))));


		gAtk[i] = new GeradorAtaque(i,random->normal(10,5),random->exponencial(2));
		cout << "\nJoin\n";
		gAtk[i]->join();
	}


	delete random;
	delete gAtk;
}