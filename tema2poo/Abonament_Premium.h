#pragma once
#include "Abonament.h"
using namespace std;

class Abonament_Premium : public Abonament
{
private:
	int reducere;
public:
	Abonament_Premium();
	Abonament_Premium(const string numeab, const float pret, const int perioada, const int reducere);
	Abonament_Premium(const Abonament& abonament, const int reducere);
	Abonament_Premium(const Abonament_Premium& abp);
	~Abonament_Premium();
	friend istream& operator<<(istream& CIN, Abonament_Premium& abonamentp);
	friend ostream& operator<<(ostream& COUT, Abonament_Premium& abonamentp);
	float GetSum();
	void GetInfo();
};