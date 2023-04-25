#include <iostream>
#include <vector>
#include "Abonament.h"
using namespace std;

int Abonament::nr_ab = 0;
int Abonament_Premium::nr_abp = 0;
void Abonament::SetInfo() {
	cout << "Informatiile pentru abonamentul standard: " << endl;
	cout << "Numele abonamentului:" << endl;
	cin >> this->nume_abonament;
	cout << "Pretul abonamentului:" << endl;
	cin >> this->pret;
	cout << "Perioada abonamentului: " << endl;
	cin >> this->perioada;
	
}
Abonament::Abonament() {
	nr_ab++;
}
Abonament::Abonament(const string& numeab, const float pret, const int perioada)
	:nume_abonament(nume_abonament), pret(pret), perioada(perioada) 
{
	nr_ab++;
	
}
Abonament::Abonament(const Abonament& original):nume_abonament(original.nume_abonament),pret(original.pret),perioada(original.perioada) {
	nr_ab++;
	//constructor copiere
}
void Abonament::GetInfo() {
	cout << "Nume abonament: " << nume_abonament << endl;
	cout << "Pret abonament: " << pret << endl;
	cout << "Perioada abonament: " << perioada << endl;
}

ostream& operator<<(ostream& COUT, Abonament& abonament) {
	COUT << "Nume abonament" << abonament.nume_abonament << endl;
	COUT << "Pret abonament: " << abonament.pret << endl;
	COUT << "Perioada abonament: " << abonament.perioada << endl;
	return COUT;
}
istream& operator>>(istream& CIN, Abonament& abonament) {
	cout << "Nume abonament: " << endl;
	CIN >> abonament.nume_abonament;
	cout << "Pret abonament: " << endl;
	CIN >> abonament.pret;
	cout << "Perioada abonament: " << endl;
	CIN >> abonament.perioada;
	return CIN;
}
Abonament& Abonament:: operator=(const Abonament& ab) {
	
		this->nume_abonament = ab.nume_abonament;
		this->pret = ab.pret;
		this->perioada = ab.perioada;
		return *this;
	}


float Abonament::GetSum() {
	return(float)(this->pret * this->perioada);
}
void Abonament::nrAb() {
	cout << "Numarul abonamentelor standard este:" << nr_ab;
}
Abonament::~Abonament() {
	if (nr_ab > 0)
		nr_ab--;
	//cout << "Destructor called";

//////
//////
}


//


Abonament_Premium::Abonament_Premium() {
	nr_abp++;
}

Abonament_Premium::Abonament_Premium(const string nume_abonament, const float pret, int perioada, int reducere) :Abonament(nume_abonament, pret, perioada) {
	nr_abp++;
}
Abonament_Premium::Abonament_Premium(const Abonament& abonament, const int reducere) :Abonament(abonament), reducere(reducere) {
	nr_abp++;

}

Abonament_Premium::Abonament_Premium(const Abonament_Premium& original):reducere(original.reducere),Abonament(original) {
	nr_abp++;
	//constructor copiere abonament premium
}

istream& operator>>(istream& CIN, Abonament_Premium& abonamentp) {
	cout << "Nume abonament: " << endl;
	CIN >> abonamentp.nume_abonament;
	cout << "Pret abonament: " << endl;
	CIN >> abonamentp.pret;
	cout << "Perioada abonament: " << endl;
	CIN >> abonamentp.perioada;
	cout << "Reducerea: " << endl;
	CIN >> abonamentp.reducere;
	return CIN;
}

ostream& operator<<(ostream& COUT, Abonament_Premium& abonamentp) {
	COUT << "Nume abonament" << abonamentp.nume_abonament << endl;
	COUT << "Pret abonament: " << abonamentp.pret << endl;
	COUT << "Perioada abonament: " << abonamentp.perioada << endl;
	COUT << "Reducerea:" << abonamentp.reducere << endl;
	return COUT;
}

Abonament_Premium& Abonament_Premium:: operator=(const Abonament_Premium& ab) {
	this->nume_abonament = ab.nume_abonament;
	this->pret = ab.pret;
	this->perioada = ab.perioada;
	this->reducere = ab.reducere;
	return *this;
}

Abonament_Premium::~Abonament_Premium() {
	//cout << "Destructor called" << endl;
	nr_abp--;
}
float Abonament_Premium::GetSum() {
	return(float)(((float)this->pret - this->reducere) * this->perioada);
}
void Abonament_Premium::GetInfo() {
	cout << "Nume abonament: " << nume_abonament << endl;
	cout << "Pret abonament: " << pret << endl;
	cout << "Perioada abonament: " << perioada << endl;
	cout << "Reducere: " << reducere << endl;
}
void Abonament_Premium::SetInfo() {
	cout << "Informatiile pentru abonamentul premium: " << endl;
	cout << "Numele abonamentului :" << endl;
	cin >> this->nume_abonament;
	cout << "Pretul abonamentului:" << endl;
	cin >> this->pret;
	cout << "Perioada abonamentului: " << endl;
	cin >> this->perioada;
	cout << "Reducerea abonamentului premium:" << endl;
	cin >> this->reducere;

}
void Abonament_Premium::nrAb() {
	cout << "Numarul abonamentelor premium este:" << nr_abp;
}
void Abonament_Premium::nrAbTotal() {
	cout << "Numarul total de abonamente este: " << nr_ab + nr_abp;
}