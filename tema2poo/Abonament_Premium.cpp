#include <iostream>
#include "Abonament_Premium.h"
using namespace std;


Abonament_Premium::Abonament_Premium() {}

Abonament_Premium::Abonament_Premium(const string nume_abonament, const float pret, int perioada, int reducere) :Abonament(nume_abonament, pret, perioada) {

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
Abonament_Premium::Abonament_Premium(const Abonament_Premium& abp) {
	*this = abp;
}

istream& operator<<(istream& CIN, Abonament_Premium& abonamentp) {
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
	pret = ab.pret;
	nume_abonament = ab.nume_abonament;
	perioada = ab.perioada;
	reducere = ab.reducere;
}

Abonament_Premium::~Abonament_Premium() {
	cout << "Destructor called" << endl;

}