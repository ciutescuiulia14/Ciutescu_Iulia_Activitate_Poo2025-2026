#include<iostream>
using namespace std;


class MaterialTextil {
private:
	const int idBalot;
	static int nrBaloturi;

	char* denumire;
	string tip;

	float greutate;
	int lunaLivrare;
	int nrCantitati;
	float* cantitati;

public:
	//constructorul implicit
	MaterialTextil() :idBalot(++nrBaloturi) {
		this->tip = "Catifea";
		this->greutate = 0;
		this->lunaLivrare = 4;
		this->nrCantitati = 0;
		this->cantitati = nullptr;
		this->denumire = nullptr;
	}

	//constructorul cu parametrii
	MaterialTextil(const char* denumire, string tip, float greutate, int lunaLivrare, int nrCantitati, const float* cantitati) :idBalot(++nrBaloturi) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->tip = tip;
		this->greutate = greutate;
		this->lunaLivrare = lunaLivrare;
		this->nrCantitati = nrCantitati;
		this->cantitati = new float[nrCantitati];
		for (int i = 0; i < nrCantitati; i++) {
			this->cantitati[i] = cantitati[i];
		}
	}

	//constructorul de copiere
	MaterialTextil(const MaterialTextil& material) : idBalot(++nrBaloturi) {
		this->tip = material.tip;
		this->greutate = material.greutate;
		this->lunaLivrare = material.lunaLivrare;
		this->nrCantitati = material.nrCantitati;
		this->cantitati = new float[nrCantitati];
		if (material.cantitati != nullptr) {
			this->cantitati = new float[material.nrCantitati];
			for (int i = 0; i < material.nrCantitati; i++) {
				this->cantitati[i] = material.cantitati[i];
			}
		}
		else {
			this->cantitati = nullptr;
		}
		if (material.denumire != nullptr) {
			this->denumire = new char[strlen(material.denumire) + 1];
			strcpy_s(this->denumire, strlen(material.denumire) + 1, material.denumire);
		}
		else {
			this->denumire = nullptr;
		}
	}
	
	//metode de acces:getter si setter
	int getIdBalot() {
		return this->idBalot;
	}

	static int getNrBaloturi() {
		return nrBaloturi;
	}

	void setNrBaloturi(int nrBaloturi) {
		this->nrBaloturi = nrBaloturi;
	}

	void setGreutate(float greutate) {
		if (greutate > 0) {
			this->greutate = greutate;
		}
	}

	float getGreutate() {
		return this->greutate;
	}

	char* getDenumire() {
		return this->denumire;
	}

	int getLunaLivrare() {
		return this->lunaLivrare;
	}

	int getNrCantitati() {
		return this->nrCantitati;
	}

	void setDenumire(const char* denumire) {
		if (strlen(denumire) > 0) {
			if (this->denumire != nullptr) {
				delete[] this->denumire;
			}
			this->denumire = new char[strlen(denumire) + 1];
			strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		}
	}

	void setTip(string tip) {
		if (tip.length() > 0) {
			this->tip = tip;
		}
	}

	string getTip() {
		return this->tip;
	}

	void setCantitati(int nrCantitati, float* cantitati) {
		if (nrCantitati > 0) {
			this->nrCantitati = nrCantitati;
			if (this->cantitati != nullptr) {
				delete[] this->cantitati;
			}
			this->cantitati = new float[nrCantitati];
			for (int i = 0; i < nrCantitati; i++) {
				this->cantitati[i] = cantitati[i];
			}
		}
	}

	float* getCantitati() {
		return this->cantitati;
	}

	float getCantitateDeMaterial(int index) {
		if (index >= 0 && index < this->nrCantitati) {
			return this->cantitati[index];
		}
		else {
			throw "Index invalid";
		}
	}

	//operatorul =
	void operator=(const MaterialTextil& material){
		this->tip = material.tip;
		this->greutate = material.greutate;
		this->lunaLivrare = material.lunaLivrare;
		this->nrCantitati = material.nrCantitati;
		this->cantitati = new float[nrCantitati];
		if (this->cantitati != nullptr) {
			delete[]this->cantitati;
			this->cantitati = nullptr;
		}
		if (material.cantitati != nullptr) {
            this->cantitati = new float[material.nrCantitati];
			for (int i = 0; i < material.nrCantitati; i++) {
				this->cantitati[i] = material.cantitati[i];
			}
		}
		else {
			this->cantitati = nullptr;
		}
		if (this->denumire != nullptr) {
			delete[]this->denumire;
			this->denumire = nullptr;
		}
		if (material.denumire != nullptr) {
			this->denumire = new char[strlen(material.denumire) + 1];
			strcpy_s(this->denumire, strlen(material.denumire) + 1, material.denumire);
		}
		else {
			this->denumire = nullptr;
		}
	}

	void afisareMaterial() {
		cout << endl << this->getIdBalot() << ". Materialul ";
		if(this->getDenumire()!= nullptr){
			cout << this->getDenumire();
		}
		else {
			cout << " Neidentificat ";
		}
		cout << ", este de tip " << this->getTip() << " cu greutatea  " << this->getGreutate() << " kg , a fost livrat in luna a  " << this->getLunaLivrare() << " -a. Este inregistrat cu " << this->getNrCantitati() << " cantitati: ";
		if(this->getNrCantitati() >0){
			cout << " Cantitatile sunt : ";
			for (int i = 0; i < this->getNrCantitati()  -1; i++) {
				cout << " " << this->getCantitateDeMaterial(i) << ",";
			}
			cout << this->getCantitateDeMaterial(this->getNrCantitati() - 1) << ".";
		}
	}





	~MaterialTextil() {
		if (this->denumire != nullptr) {
			delete[] this->denumire;
		}
		if (this->cantitati != nullptr) {
			delete[] this->cantitati;
		}
	}

	//bool operator
	bool operator<(const MaterialTextil& mt) {
		return this->greutate < mt.greutate;
	}

	//opertor +=
	void operator+=(float valoareAdaugata) {
		if (valoareAdaugata > 0) {
			this->greutate += valoareAdaugata;
		}
	}

	//operator negatie
	bool operator!() {
		return this->lunaLivrare != 0;
	}

	//operator functie
	float operator() (int index) {
		return this->getCantitateDeMaterial(index);
	}
};

int MaterialTextil::nrBaloturi = 0;


void main() {
	float* vector = new float[4] { 1.5, 5.0, 2.7, 8.0};
	MaterialTextil m1("Ivory", "Catifea", 5, 6, 4, vector);

	try {
		cout << endl << " Cantitatea de material de la indexul 2 este: " << m1(2);
	}
	catch(int idx){
		cout << endl << idx;
	}
	catch( const char* msg){
		cout << endl << msg;
	}
	catch(...){
		cout << endl << " Eroare ";
	}
	
	cout << endl << " Id balot:  " << m1.getIdBalot();//apel constructor cu parametrii
	
	MaterialTextil m2 = m1;
	cout << endl << "Id balot : " << m2.getIdBalot();//apel constructor de copiere
	MaterialTextil m3;
	m3 = m1;
	cout << endl << "Id balot : " << m3.getIdBalot();//apel operator=

	

	if (m1 < m2) {
		cout << endl << " Materialul 1 este mai usor decat materialul 2 ";
	}
	else {
		cout << endl << " Materialul 2 nu este mai usor decat materialul 1 ";
	}

	m1 += 3.5;

	if(!m1){
		cout << endl << "Luna livrarii este 0 ";
	}
	else {
		cout << endl << "Luna livrarii nu este 0 ";
	}

	m1.afisareMaterial();



}





