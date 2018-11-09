#include "stdafx.h"
#include <chrono>
#include <thread>
#include <chrono>
#include <mutex>
#include "Processo.h"


Processo::Processo()
{
}
Processo::~Processo()
{
}
long Processo::getClock(){
	return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - Processo::tempoInicial).count();
}
void  Processo::join(){
	t->join();
}