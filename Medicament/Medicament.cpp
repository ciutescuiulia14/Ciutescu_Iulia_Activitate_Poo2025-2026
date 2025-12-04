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
	//constructorul de copiere
	Medicament(const Medicament& m) : idMedicament(++nrMedicamente) {
		this->categorie = m.categorie;
		this->pret = m.pret;
		this->ziExpirare = m.ziExpirare;
		this->nrGramaje = m.nrMedicamente;
		this->gramaje = new float[m.nrGramaje];
		if (m.gramaje != nullptr) {
			this->gramaje = new float[m.nrGramaje];
			for (int i = 0; i < m.nrGramaje; i++) {
				this->gramaje[i] = m.gramaje[i];
			}
		}
		else {
			this->gramaje = nullptr;
		}
		if (m.denumire != nullptr) {
			this->denumire = new char[strlen(m.denumire) + 1];
			strcpy_s(this->denumire, strlen(m.denumire) + 1, m.denumire);
		}
		else {
			this->denumire = nullptr;
		}
	}
	//gettri + setteri

	int getIdMedicament() {
		return this->idMedicament;
	}

	static int getNrMedicamente() {
		return nrMedicamente;
	}

	void setNrGaramaje(int nrGramaje) {
		this->nrGramaje = nrGramaje;
	}

	void setPret(float pret) {
	}

	float getPret() {
		return this->pret;
	}

	char* getDenumire() {
		return this->denumire;
	}

	int getZiExpirare() {
		return this->ziExpirare;
	}

	int getNrGramaje() {
		return this->nrGramaje;
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

	void setCagorie(string categorie) {
		this->categorie = categorie;
	}

	string getCategorie() {
		return this->categorie;
	}

	void setGramaje(int nrGramaje, float* gramaje) {
		if (nrGramaje > 0) {
		this->nrGramaje = nrGramaje;
		if (this->gramaje != nullptr) {
			delete[]this->gramaje;
		}
		this->gramaje = new float[nrGramaje];
		for (int i = 0; i < nrGramaje; i++) {
			this->gramaje[i] = gramaje[i];
		}
	}
}

	float* getGramaje() {
		return this->gramaje;
	}

	float getGramajDupaIndex(int index) {
		if(index >=0 && index < this->nrGramaje){
			return this->gramaje[index];
		}
		else {
			throw"index invalid";
		}

	}

	//operatorul =
	void operator=(const Medicament& m){
		this->categorie = m.categorie;
		this->pret = m.pret;
		this->ziExpirare = m.ziExpirare;
		this->nrGramaje = m.nrMedicamente;
		this->gramaje = new float[m.nrGramaje];
		if (this->gramaje != nullptr) {
			delete[] this->gramaje;
			this->gramaje = gramaje;
		}
		if (m.gramaje != nullptr){
			this->gramaje = new float[m.nrGramaje];
			for (int i = 0; i < m.nrGramaje; i++) {
				this->gramaje[i] = m.gramaje[i];
			}
		}
		else {
			this->gramaje = nullptr;
		}
		if (this->denumire = nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
		if (m.denumire != nullptr) {
			this->denumire = new char[strlen(m.denumire) + 1];
			strcpy_s(this->denumire, strlen(m.denumire) + 1, m.denumire);
		}
		else {
			this->denumire = nullptr;
		}
	}
	
	  

	//functia de afisare
	void afisareMedicament() {
		cout << endl << this->getIdMedicament() << ". Medicamentul ";
		if (this->getDenumire() != nullptr) {
			cout << this->getDenumire();
		}
		else {
			cout << " neindentificat";
		}
		cout << " , face parte din categoria  " << this->getCategorie() << " avand pretul de:  "
			<< this->getPret() << " , cu ziua expirarii: " << this->getZiExpirare() << " . Este inregistrat in baza de date cu  " << this->getNrGramaje() << " variante de gramaj .";
					if (this->getNrGramaje() > 0) {
			cout << "Gramajele disponibile sunt: ";
			for (int i = 0; i < this->getNrGramaje(); i++) {
				cout << " " << this->getGramajDupaIndex(i) << ", ";
			}
			cout << this->getGramajDupaIndex(this->getNrGramaje() - 1) << ".";
		}

	}



	//destructorul
	~Medicament() {
		if (this->denumire != nullptr) {
			delete[]this->denumire;
		}
	}
		
	//bool operator
	bool operator <(const Medicament& md) {
		return this->gramaje[0] < md.gramaje[0];
	}

	//operator +=
	void operator+=(float valoareAdaugata) {
		if (valoareAdaugata > 0) {
			this->pret += valoareAdaugata;
		}
	}

	//operator negatie
	bool operator!() {
		return this->ziExpirare != 0;
	}




};
int Medicament::nrMedicamente = 0;

int main() {
		
		float* vectorGramaje = new float[3] { 250.0, 500.0, 1000.0 };
		Medicament m1("Paracetamol", "analgezice", 12.5, 30, 3, vectorGramaje);
		//apel constructor cu parametrii
		cout << endl << "Id medicament : " << m1.getIdMedicament();
		//apel constructor de copiere
		Medicament m2 = m1;
		cout << endl << "Id medicament :" << m2.getIdMedicament();
		Medicament m3;
		//apel oprator=
		m3 = m1;
		cout << endl << "Id medicament: " << m3.getIdMedicament();


		//bool operator
		if (m1 < m2) {
			cout << endl << "Medicamentul 1 are gramajul mai mic decat medicamentul 2";
		}
		else {
			cout << endl << "Medicamentul 2 are gramajul mai mic decat medicamentul 1";
		}

		//op +=
		m1 += 5.0;
		cout << endl << "Noul pret al medicamentului 1 este: " << m1.getPret();

		//operator negatie
		if (!m1) {
			cout << endl << "Medicamentul nu este expirat";
		}
		else {
			cout << endl << "Medicamentul  este expirat";
		}


		//apel afisare
		m1.afisareMedicament();
}