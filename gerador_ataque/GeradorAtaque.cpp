#include "GeradorAtaque.h"



GeradorAtaque::GeradorAtaque()
{
}

GeradorAtaque::GeradorAtaque(int i,int nAtk, int tempo)
{
	t = new thread(&GeradorAtaque::gerador, this, i, nAtk, tempo);
	tempoInicial = std::chrono::system_clock::now();
}


GeradorAtaque::~GeradorAtaque()
{
}

void GeradorAtaque::gerador(int i, int nAtk, int tempo)
{
	int ataque;

	for (int i = 0; i < nAtk; i++)
	{
		std::this_thread::sleep_for(std::chrono::seconds(tempo));  //aqui o tempo pode ser substituido por exponencial(tempo)

		Processo::mu.lock();
		GeradorAtaque::cntr++;
		ataque = GeradorAtaque::cntr;  // o valor do é obtido a partir da variavel global cntr; como cntr esta sendo compartilhada entre as threads
		Processo::mu.unlock();	// o acesso a ela deve ser protegido.

		std::cout << "gerador " << i << " criou ataque " << ataque << " em " << Processo::getClock() << std::endl;

	}
		
}

int GeradorAtaque::cntr = 0;