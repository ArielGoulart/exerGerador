#pragma once
#include <thread>
#include <chrono>
#include <mutex>

class Processo
{

protected:

	std::thread *t;
	
public:
	std::mutex mu;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration> tempoInicial;

	Processo();
	~Processo();
	long getClock();
	void join();
};

