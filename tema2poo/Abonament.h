#pragma once
#include <iostream>
using namespace std;
class Abonament {
protected:
	string nume_abonament;
	float pret;
	int perioada;
	static int nr_ab;
public:
	
	Abonament();
	Abonament(const string& numeab, const float Pret, const int Perioada);
	Abonament(const Abonament& ab);
	~Abonament();
	virtual void GetInfo();
	virtual void SetInfo();
	virtual float GetSum();
	virtual void nrAb();
	friend ostream& operator<<(ostream& COUT, Abonament& abonament);
	friend istream& operator>>(istream& CIN, Abonament& abonament);
	
	Abonament& operator=(const Abonament& ab);
};
class Abonament_Premium : public Abonament
{
private:
	int reducere;
	static int nr_abp;
public:
	Abonament_Premium();
	Abonament_Premium(const string numeab, const float pret, const int perioada, const int reducere);
	Abonament_Premium(const Abonament& abonament, const int reducere);
	Abonament_Premium(const Abonament_Premium& abp);
	~Abonament_Premium();
	friend istream& operator>>(istream& CIN, Abonament_Premium& abonamentp);
	friend ostream& operator<<(ostream& COUT, Abonament_Premium& abonamentp);
	Abonament_Premium&  operator=(const Abonament_Premium& ab);
	float GetSum() override;
	void GetInfo() override;
	void SetInfo() override;
	void nrAb() override;
	void nrAbTotal();
	
};