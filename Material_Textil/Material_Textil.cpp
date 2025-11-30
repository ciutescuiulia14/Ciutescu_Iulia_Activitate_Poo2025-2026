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

};

int MaterialTextil::nrBaloturi = 0;


void main() {
	float* vector = new float[4] { 1.5, 5.0, 2.7, 8.0};
	MaterialTextil m1;


	

}







