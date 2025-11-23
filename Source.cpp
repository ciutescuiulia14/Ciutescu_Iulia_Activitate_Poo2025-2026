#include<iostream>
#include<string>
using namespace std;

class Factura {
private:
	const int id;
	static int nrFacturi;


	string client;

	int nrPozitii;
	float* valori;
public:
	//constructor implicit
	Factura() : id(++nrFacturi) {
		this->client = "Anonim";
		this->nrPozitii = 0;
		this->valori = nullptr;
	}
	//constructor cu toti parametrii
	Factura(string _client, int nrPozitii, float* valori) : id(++nrFacturi) {
		client = _client;
		this->nrPozitii = nrPozitii;
		if (nrPozitii > 0 && valori != nullptr) {
			this->valori = new float[nrPozitii];
			for (int i = 0; i < nrPozitii; i++) {
				this->valori[i] = valori[i];
			}
		}
		else
		{
			this->valori = nullptr;
		}
		delete[]valori;
	}

	//constructor de copiere
	Factura(const Factura& factura) : id(++nrPozitii){
		this->client = factura.client;
		this->nrPozitii = factura.nrPozitii;
		this->valori = new float[factura.nrPozitii];
		for (int i = 0; i < factura.nrPozitii; i++) {
			this->valori[i] = factura.valori[i];
		}


	}

	const int getId() {
		return this->id;
	}

	static int getNrFacturi() {
		return nrFacturi;
	}

	static void setNrFacturi(int _nrFacturi) {
		nrFacturi = _nrFacturi;
	}

	string getClient() {
		return this->client;
	}

	void setClient(int client) {
		this->client = client;
	}

	int getNrPozitii() {
		return this->nrPozitii;
	}

	void setNrPozitii(int nrPozitii) {
		if (nrPozitii > 0) {
			this->nrPozitii = nrPozitii;
		}
		else {
			throw "Numar incorect";
		}
	}

	float* getValori() {
		float* vectorValori = new float[this->nrPozitii];
		for (int i= 0; i < nrPozitii; i++) {
			vectorValori[i] = this->valori[i];
		}
		return vectorValori;
	}

	void setValori(float* noulVectorValori, int nouaDimensiune) {
		setNrPozitii(nouaDimensiune);
		if (this->valori != nullptr) {
			delete[] this->valori;
		}
		this->valori = new float[nouaDimensiune];
		for (int i = 0; i < nouaDimensiune; i++) {
			this->valori[i] = noulVectorValori[i];
		}
		delete[] noulVectorValori;
	}

	~Factura() {
		cout << endl << "s-a apelat destructorul";
		if (this->valori != nullptr)
			delete[] this->valori;
	}

	void afisareFactura() {
		cout << this->id << ".Factura pentru clientul  " << this->client;
		if(this->nrPozitii > 0){
			cout << " are " << this->nrPozitii << " pozitii cu valorile: ";
			if (this->valori != nullptr) {
				for (int i = 0; i < this->nrPozitii; i++) {
					cout << "  " << this->valori[i];
				}
			}
		}
		cout << endl;
	}


};

int Factura::nrFacturi = 0;

int main() {
	//Factura f1;
	//cout << endl << " Noua valoare este: " << f1.getNrPozitii();
	//f1.afisareFactura();

	//Factura f2("Anonim", 3, new float[3] {300, 450, 50.2});
	//f2.afisareFactura();
	//f2.setValori(new float[3] {75, 130, 140}, 3);
	//
	////vectori de valori
	//float* vectorValori = f2.getValori();
	//for (int i = 0; i < f2.getNrPozitii(); i++) {
	//	cout << " " << vectorValori[i];
	//}
	//delete[]vectorValori;



	////vector de pointeri
	//Factura** vectorFacturi = new Factura * [3];
	//for (int i = 0; i < 3; i++) {
	////	vectorFacturi[i] = new Factura("Ionescu", i + 1, nullptr);
	//} 

	Factura factura1("Client", 3, new float[3] {200, 400, 57});
	//apel constructor de copiere
	Factura factura2 = factura1;
} 