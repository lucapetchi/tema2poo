#include "Persoana.h"
#include <typeinfo>
using namespace std;
int Persoana::nr_persoane = 0;
int Abonat::nr_abonati = 0;
int Abonat::safety = 0;

Persoana::Persoana() {
	nr_persoane++;
	id = -1;
	nume = "-";
	cnp = "-";

}
Persoana::Persoana(const int Id, const string Nume, const string Cnp) {
	id = Id;
	nume = Nume;
	cnp = Cnp;
	nr_persoane++;
}
Persoana::Persoana(const Persoana& pers) {
	id = pers.id;
	nume = pers.nume;
	cnp = pers.cnp;
	nr_persoane++;
}
Persoana::~Persoana() {
	nr_persoane--;
}
ostream& operator<<(ostream& COUT, Persoana& pers) {
	COUT << "Id persoana:" << pers.id << endl;
	COUT << "Nume Persoana: " << pers.nume << endl;
	COUT << "Cnp persoana: " << pers.cnp << endl;
	return COUT;
}
istream& operator>>(istream& CIN, Persoana& pers) {
	cout << "Id persoana:" << endl;
	CIN >> pers.id;
	cout << "Nume Persoana: " << endl;
	CIN >> pers.nume;
	cout << "Cnp persoana: " << endl;
	CIN >> pers.cnp;
	return CIN;
}
void Persoana::GetInfo() {
	cout << "Id: " << id << endl;
	cout << "Nume persoana: " << nume << endl;
	cout << "CNP: " << cnp<< endl;
}
void Persoana::SetInfo() {
	cout << "Informatiile persoanei " << endl;
	cout << "Id:" << endl;
	cin >> this->id;
	cout << "Nume:" << endl;
	cin >> this->nume;
	cout << "CNP: " << endl;
	cin >> this->cnp;

}
void Persoana::NrPers() {
	cout << "Numarul abonatilor este:" << nr_persoane;
}
Persoana& Persoana::operator= (const Persoana& pers) {
	id = pers.id;
	nume = pers.nume;
	cnp = pers.cnp;
	return *this;
}

//

Abonat::Abonat() {
	nr_abonati++;
}
Abonat::Abonat(const int Id, const string& Nume, const string& Cnp, const string& Telefon, Abonament* ab)
	:Persoana(Id, Nume, Cnp), nr_telefon(Telefon), x(ab) {
	
	nr_abonati++;

}
Abonat::Abonat(const Persoana& pers, const string& tel, Abonament* ab)
	:Persoana(pers), nr_telefon(tel), x(ab) {
	nr_abonati++;
}

Abonat::Abonat(const Abonat& ab) {
	*this = ab;
	nr_abonati++;
}
Abonat::~Abonat() {
	if (safety != 0){
		delete x;
	}
	
	nr_abonati--;
}
void Abonat::GetInfo() {
	Persoana::GetInfo();
	cout << "Numar telefon: " << nr_telefon << endl;
	x->GetInfo();
}
void Abonat::SetInfo() {
	Persoana::SetInfo();
	cout << "Numar telefon: " << endl;
	cin >> nr_telefon;
	x->SetInfo();
}
void Abonat::NrPers() {
	cout << "Numarul abonatilor este:" << nr_abonati;
}
float Abonat::getsum() {
	
	return (float)(this->x->GetSum());
}
int Abonat::gettype() {
	if (typeid(*x) == typeid(Abonament)) {
		return 1;
	}
	else if (dynamic_cast<Abonament_Premium*>(x) != nullptr)
		return 2;
	else
		return 0;


}

ostream& operator<<(ostream& COUT, Abonat& ab) {
	COUT << "Id abonat:" << ab.id << endl;
    COUT << "Nume abonat: " << ab.nume << endl;
	COUT << "Cnp abonat: " << ab.cnp << endl;
	COUT<< "Numar telefon: " << ab.nr_telefon << endl;
	if (typeid(*(ab.x)) == typeid(Abonament))
		COUT << "Abonament standard: " << ab.x<<endl;
	else if (dynamic_cast<Abonament_Premium*>(ab.x) != nullptr)
		COUT << "Abonament premium: " << *(Abonament_Premium*)ab.x << endl;
	else
		COUT << "Abonament incompatibil" << endl;
	return COUT;
}

istream& operator>>(istream& CIN, Abonat& ab) {
	int nr;
	cout << "ID-ul abonatului: ";
	CIN >> ab.id;
	cout << "Numele abonatului: ";
	CIN >> ab.nume;
    cout << "CNP-ul abonatului: ";
	CIN >> ab.cnp;
	cout << "Telefon abonat: ";
	CIN >> ab.nr_telefon;
	cout << "Ce tip de abonament?"<< endl;
	cout << "Pentru abonament standard->1,pentru premium->2:" << endl;
	CIN >> nr;
	if (nr == 1) {
		ab.x = new Abonament;
		CIN >> *ab.x;
		ab.safety++;
		return CIN;

	}
	else if (nr == 2) {
		ab.x = new Abonament_Premium;
		CIN >> *(Abonament_Premium*)ab.x;
		ab.safety++;
		return CIN;
	}
	else
		cout << "???" << endl;
		return CIN;	
	
		
}
Abonat& Abonat::operator=(const Abonat& ab) {
	this->id = ab.id;
	this->nume = ab.nume;
	this->cnp = ab.cnp;
	this->nr_telefon = ab.nr_telefon;
	if (typeid (*(ab.x)) == typeid(Abonament)) {
		this->x = ab.x;
	}
	else
		if (dynamic_cast<Abonament_Premium*>(ab.x) != nullptr)
			this->x = (Abonament_Premium*)ab.x;
		else
			cout << "Abonamente incompatibile";

	
	return *this;
	
}

