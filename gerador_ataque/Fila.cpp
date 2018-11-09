#include "stdafx.h"
#include <exception>
#include <iostream>
#include <mutex>
#include "Fila.h"


Fila::Fila()
{}
Fila::~Fila()
{}

void Fila::insert(Ataque *a){
	queueMutex.lock();
	fila.push(a);
	queueMutex.unlock();
}
Ataque* Fila::getFirst(){
	Ataque *c = NULL;

	queueMutex.lock();
	if (!fila.empty()){
		c = fila.front();
		fila.pop();
	}
	queueMutex.unlock();
	return c;
}

bool Fila::isEmpty(){
	return fila.empty();
}