#include<iostream>
#include<string>
using namespace std;


class Medicament {

private:
	const int idMedicament;
	static int nrMedicamente;

	char* denumire;
	string categorie;
	float pret;
	int ziExpirare;


	int nrGramaje;
	float* gramaje;

public:
	//constructor implicit
	Medicament() :idMedicament(nrMedicamente++) {
		
		this->categorie = "neidentificata";
		this->pret = 0;
		this->ziExpirare = 1;
		this->nrGramaje = 0;
		this->gramaje = nullptr;
		this->denumire = nullptr;
	}
	//constructor cu toti parametrii
	Medicament(const char* denumire, string categorie, float pret, int ziExpirare, int nrGramaje, const float* gramaje) :idMedicament(nrMedicamente++) {
		if (denumire != nullptr) {
			this->denumire = new char[strlen(denumire) + 1];
			strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		}
		else {
			this->denumire = nullptr;
		}
		this->categorie = categorie;
		this->pret = pret;
		this->ziExpirare = ziExpirare;
		this->nrGramaje = nrGramaje;

		if (nrGramaje > 0 && gramaje != nullptr) {
			this->nrGramaje = nrGramaje;
			this->gramaje = new float[nrGramaje];
			for (int i = 0; i < nrGramaje; i++) {
				this->gramaje[i] = gramaje[i];
			}
		}
		else {
			this->nrGramaje = 0;
			this->gramaje = nullptr;
		}
	}







};
int Medicament::nrMedicamente = 0;

int main() {
		//Medicament m1;
		float* vectorGramaje = new float[3] { 250.0, 500.0, 1000.0 };
		Medicament m2("Paracetamol", "analgezic", 12.5, 30, 3, vectorGramaje);
		
}