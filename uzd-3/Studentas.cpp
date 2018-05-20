#include "Struktura.h"
#include "Funkcijos.h"




void Studentai::nuskaityti(std::istream &fd)
{
	fd >> Vardas >> Pavarde;

	double x;
	for (int i = 0; i < 5; i++)
	{
		fd >> x;
		pazymiai.push_back(x);
	}
	fd >> egzaminas;
}



bool rusiavimas_pagal_varda(const Studentai &x, const Studentai &y)
{
	return x.vardas_get() < y.vardas_get();
}

void Sortas(std::vector<Studentai> &Student)
{
	std::sort(Student.begin(), Student.end(), rusiavimas_pagal_varda);
}

bool kietiakai_atranka(Studentai &Student)
{
	return Student.galutinis_get() >= 6;
}
bool vargsiukai_atranka(Studentai &Student)
{
	return Student.galutinis_get() < 6;
}

double vidurkis(double egzaminas, std::vector <double> pazymiai)
{
	auto suma = egzaminas;
	double vidurkis;

	for (size_t i = 0; i < pazymiai.size(); i++)
	{
		suma = suma + pazymiai[i];
	}
	vidurkis = suma / pazymiai.size() + 1;

	return vidurkis;
}
double mediana(double egzaminas, std::vector<double> pazymiai)
{
	double mediana;
	std::vector<double> kazkas = pazymiai;
	kazkas.push_back(egzaminas);
	std::sort(kazkas.begin(), kazkas.end());
	if (kazkas.size() % 2 == 0) {
		mediana = (kazkas[kazkas.size() / 2 - 1] + kazkas[kazkas.size() / 2]) / 2;
	}
	else mediana = kazkas[kazkas.size() / 2];

	return mediana;

}


