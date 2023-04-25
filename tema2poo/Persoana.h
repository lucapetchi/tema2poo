#pragma once
#include "Abonament.h"
using namespace std;

class Persoana
{
protected:
	int id;
	string nume;
	string cnp;
	static int nr_persoane;
public:
	Persoana();
	Persoana(const int id, const string, const string cnp);
	Persoana(const Persoana& pers);
	~Persoana();
	virtual void GetInfo();
	virtual void SetInfo();
	static void NrPers();
	friend ostream& operator<<(ostream& COUT, Persoana& pers);
	friend istream& operator>>(istream& CIN,  Persoana& pers);
	Persoana& operator=(const Persoana& Pers);
	

};
class Abonat :public Persoana {
private:
	string nr_telefon;
	Abonament* x;
	static int nr_abonati;
	static int safety;

public:
	Abonat();
	Abonat(const int Id, const string& Nume, const string& Cnp, const string& Telefon, Abonament* ab);
	Abonat(const Persoana& pers, const string& tel, Abonament* ab);
	Abonat(const Abonat& ab);
	~Abonat();
	void GetInfo() override;
	void SetInfo() override;
	void NrPers() ;
	float getsum();
	friend ostream& operator<<(ostream& COUT, Abonat& ab);
	friend istream& operator>>(istream& CIN, Abonat& ab);
	Abonat& operator=(const Abonat& Pers);
	int gettype();

	
};

