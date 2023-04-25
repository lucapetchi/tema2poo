#include "Clienti.h"
int Clienti::safety_clienti = 0;


Clienti::Clienti() {

}
Clienti::Clienti(const Clienti& cl) {
	*this = cl;
}
Clienti::Clienti(const vector<Abonat*>& Abonati) {
	abonati = Abonati;
}
Clienti::~Clienti() {
	if (safety_clienti > 0){
		for (int i = 0; i <= abonati.size(); i++)
			delete abonati[i];
	}
}


float Clienti::castigtotal(){
	float castigtotal = 0;
	for (int i = 0; i <= abonati.size(); i++) {
		castigtotal += abonati[i]->getsum();
	}
	return castigtotal;
}	
void Clienti::nrAbonatiP() {
	int nr_abonatip = 0;
	for (int i = 0; i <= abonati.size(); i++) {
		if (typeid(abonati[i]) == typeid(Abonament_Premium)) {
			nr_abonatip++;
		}
		
	}
	cout << "Numarul abonatilor premium: " << nr_abonatip << endl;
}
void Clienti::coutAbonati() {
	cout << "Afisare clienti" << endl;
	for (int i = 0; i < abonati.size(); i++) {
		
		abonati[i]->GetInfo();
		cout << endl;
	}
}
void Clienti::pushAbonat(Abonat* ab) {
	abonati.push_back(ab);
}