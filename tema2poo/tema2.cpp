#include <iostream>
#include <vector>
#include "Clienti.h"
using namespace std;
int main() {
	
	Abonament* ab = new Abonament_Premium("org", 20, 3, 4);
	Abonament* abc = new Abonament("vdf", 10, 10);
	Persoana luca;
	cin >> luca;
	Persoana alex;
	cin >> alex;
	Abonat* eu = new Abonat(luca, "10", abc);
	Persoana* al = new Persoana(10, "10", "21");
	Persoana dr;
	cin >> dr;
    cout << eu;
	Abonat abo;
	cin >> abo;
	cout << abo;
	cout << abo.getsum();
	Abonat* ab2 = new Abonat(luca, "10", abc);
	Abonat* ab3 = new Abonat(alex, "10", ab);
	//Abonat* ab4 = new Abonat(al, "10", abc);
	Clienti* list=new Clienti();
	list->pushAbonat(ab2);
	//list->pushAbonat(abo);
	list->pushAbonat(ab3);
	list->pushAbonat(new Abonat(10, "ionescu", "2501013", "30", new Abonament_Premium("tlk", 13, 5, 6)));
	list->pushAbonat(new Abonat(12345, "popescu", "25101", "07", new Abonament("orang", 10, 12)));
	list->coutAbonati();

	
}