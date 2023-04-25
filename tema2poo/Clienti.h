#pragma once
#include "Persoana.h"
#include <vector>
using namespace std;

class Clienti
{
private:
	static int safety_clienti;
	vector<Abonat*> abonati;
public:
	Clienti();
	Clienti(const Clienti& cl);
	Clienti(const vector<Abonat*>& Abonati);
	~Clienti();
	
	float castigtotal();
	void nrAbonatiP();
	void coutAbonati();
	void pushAbonat(Abonat* ab);
	
};