#include<iostream>
#include<string>
using namespace std;


class DispozitivMedical {
private:
		const int idDispozitiv;
		static int nrDispozitive;

		char* nume;
		string tip;
		float pret;
		int luniGarantie;

		int nrDimensiuni;
		float* dimensiuni;

public:

	//getteri si setteri

	int getIdDispozitiv() {
		return this->idDispozitiv;
	}

	static int getNrDispozitive() {
		return nrDispozitive;
	}

	float getPret() {
		return this->pret;
	}

	string getTip() {
		return this->tip;
	}

	int getLuniGarantie(){
		return this->luniGarantie;
	}

	int getNrDimensiuni() {
		return this->nrDimensiuni;
	}

	char* getNume() {
		return this->nume;
	}

	void setPret(float pret) {
		if (pret >= 0) {
			this->pret = pret;
		}
	}

	void setTip(string tip) {
		this->tip = tip;
	}

	void setNume(const char* nume)
	{
		if (nume != nullptr && strlen(nume) > 0) {
			if (this->nume != nullptr) {
				delete[] this->nume;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
	}

	void setDimensiuni(int nrDimensiuni, const float* dimensiuni) {
		if (nrDimensiuni > 0 && dimensiuni != nullptr) {
			if (this->dimensiuni != nullptr) {
				delete[] this->dimensiuni;
			}
			this->nrDimensiuni = nrDimensiuni;
			this->dimensiuni = new float[nrDimensiuni];
			for (int i = 0; i < nrDimensiuni; i++) {
				this->dimensiuni[i] = dimensiuni[i];
			}
		}
	}

	//constructor implicit
	DispozitivMedical() : idDispozitiv(++nrDispozitive) {
		this->nume = nullptr;
		this->tip = "neidentificat";
		this->pret = 0;
		this->luniGarantie = 0;
		this->dimensiuni = nullptr;
	}
	//constructor cu toti parametrii
	DispozitivMedical(const char* nume, string tip, float pret, int luniGarantie, int nrDimensiuni, const float* dimensiuni) : idDispozitiv(++nrDispozitive) {
		if (nume != nullptr) {
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else {
			this->nume = nullptr;
		}
		this->tip = tip;
		this->pret = pret;
		this->luniGarantie = luniGarantie;
		if (nrDimensiuni > 0 && dimensiuni != nullptr) {
			this->nrDimensiuni = nrDimensiuni;
			this->dimensiuni = new float[nrDimensiuni];
			for (int i = 0; i < nrDimensiuni; i++) {
				this->dimensiuni[i] = dimensiuni[i];
			}
		}
		else
		{
			this->nrDimensiuni = 0;
			this->dimensiuni = nullptr;
		}
	}
	

};


int DispozitivMedical::nrDispozitive = 0;









int main() {

}