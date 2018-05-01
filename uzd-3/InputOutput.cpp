#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <fstream>
#include "Struktura.h"
#include "Funkcijos.h"
#include <iomanip>
#include <chrono>

bool Pagal_Varda_Vektoriai5(const Duomenys& x, const Duomenys& y) { return x.Vardas < y.Vardas; }
bool Pagal_Varda_Listai5(const Duomenys& x, const Duomenys& y) { return x.Vardas < y.Vardas; }
bool Pagal_Varda_Dekai5(const Duomenys& x, const Duomenys& y) { return x.Vardas < y.Vardas; }

std::vector<Duomenys>Studentai_Vektoriai;
std::list<Duomenys>Studentai_Listai;
std::deque<Duomenys>Studentai_Dekai;
void pradedam_InputOutput(std::string pav)
{
	nuskaitymas(pav);
	InputOutput_VEKTORIUS(pav);
	InputOutput_LISTAI(pav);
	InputOutput_DEKAI(pav);

}
void nuskaitymas(std::string pav)
{
	std::ifstream fd;
	fd.open(pav);
	if (!fd)
	{
		std::cerr << std::endl;
		std::cerr << "Failas " << pav << " neegzistuoja." << std::endl;
		std::cerr << std::endl;
		main();
	}
	else
	{
		while (!fd.eof())
		{
			std::string Vardas;
			std::string Pavarde;
			double nd1;
			double nd2;
			double nd3;
			double nd4;
			double nd5;
			double egzaminas;
			fd >> Vardas;

			fd >> Pavarde;
			fd >> nd1 >> nd2 >> nd3 >> nd4 >> nd5;
			fd >> egzaminas;

			// SKAICIAVIMAI GAL_VID, GAL_MED IR RUSIAVIMAS
			double Gal_vid = (egzaminas*0.6) + (((nd1 + nd2 + nd3 + nd4 + nd5) / 5)*0.4);

			double Gal_med;
			double x[6];
			x[0] = nd1;
			x[1] = nd2;
			x[2] = nd3;
			x[3] = nd4;
			x[4] = nd5;
			x[5] = egzaminas;
			for (int i = 0; i < 5; i++)
			{
				for (int j = i + 1; j < 6; j++)
				{
					double a;
					if (x[i] > x[j])
					{
						a = x[i];
						x[i] = x[j];
						x[j] = a;
					}
				}
			}
			Gal_med = (x[2] + x[3]) / 2;

			Duomenys something = { Vardas, Pavarde, nd1,nd2,nd3,nd4,nd5,egzaminas, Gal_vid, Gal_med };
			Studentai_Vektoriai.push_back(something);
			Studentai_Listai.push_back(something);
			Studentai_Dekai.push_back(something);
		}
	}

}

void InputOutput_VEKTORIUS(std::string pav)
{
	auto start1 = std::chrono::high_resolution_clock::now();

	// SORTAS PAGAL VARDUS
	std::sort(Studentai_Vektoriai.begin(), Studentai_Vektoriai.end(), Pagal_Varda_Vektoriai5);


	auto finish1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed1 = finish1 - start1;
	std::cout << "Programos vykdymo laikas su vektoriais: " << elapsed1.count() << " s\n";


	std::ofstream fr;
	fr.open("Rezultatai_Vektoriai.txt");

	fr.width(15); fr << std::left << "Pavarde";
	fr.width(15); fr << std::left << "Vardas";
	fr.width(15); fr << std::left << "ND-1";
	fr.width(15); fr << std::left << "ND-2";
	fr.width(15); fr << std::left << "ND-3";
	fr.width(15); fr << std::left << "ND-4";
	fr.width(15); fr << std::left << "ND-5";
	fr.width(15); fr << std::left << "Egzaminas";
	fr.width(20); fr << std::left << "Galutinis-vidurkis";
	fr.width(20); fr << std::left << "Galutinis-mediana";
	fr.width(20); fr << std::left << "Kategorija";
	fr << std::endl;

	for (auto i : Studentai_Vektoriai)
	{
		fr.width(15); fr << std::left << i.Pavarde;
		fr.width(15); fr << std::left << i.Vardas;
		fr.width(15); fr << std::left << i.nd1;
		fr.width(15); fr << std::left << i.nd2;
		fr.width(15); fr << std::left << i.nd3;
		fr.width(15); fr << std::left << i.nd4;
		fr.width(15); fr << std::left << i.nd5;
		fr.width(15); fr << std::left << i.egzaminas;
		fr.width(20); fr << std::left << std::setprecision(3) << i.galutinis_vidurkis;
		fr.width(20); fr << std::left << i.galutinis_mediana;

		fr << std::endl;
	}

	fr.close();
}
void InputOutput_DEKAI(std::string pav)
{
	auto start1 = std::chrono::high_resolution_clock::now();

	std::deque<Duomenys>Vargsiukai;
	std::deque<Duomenys>Kietiakai;
	// SORTAS PAGAL VARDUS
	std::sort(Studentai_Dekai.begin(), Studentai_Dekai.end(), Pagal_Varda_Dekai5);
	
	auto finish1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed1 = finish1 - start1;
	std::cout << "Programos vykdymo laikas su dekais: " << elapsed1.count() << " s\n";

	std::ofstream fr;
	fr.open("Rezultatai_Dekai.txt");

	fr.width(15); fr << std::left << "Pavarde";
	fr.width(15); fr << std::left << "Vardas";
	fr.width(15); fr << std::left << "ND-1";
	fr.width(15); fr << std::left << "ND-2";
	fr.width(15); fr << std::left << "ND-3";
	fr.width(15); fr << std::left << "ND-4";
	fr.width(15); fr << std::left << "ND-5";
	fr.width(15); fr << std::left << "Egzaminas";
	fr.width(20); fr << std::left << "Galutinis-vidurkis";
	fr.width(20); fr << std::left << "Galutinis-mediana";
	fr.width(20); fr << std::left << "Kategorija";
	fr << std::endl;

	for (auto i :Studentai_Dekai)
	{
		fr.width(15); fr << std::left << i.Pavarde;
		fr.width(15); fr << std::left << i.Vardas;
		fr.width(15); fr << std::left << i.nd1;
		fr.width(15); fr << std::left << i.nd2;
		fr.width(15); fr << std::left << i.nd3;
		fr.width(15); fr << std::left << i.nd4;
		fr.width(15); fr << std::left << i.nd5;
		fr.width(15); fr << std::left << i.egzaminas;
		fr.width(20); fr << std::left << std::setprecision(3) << i.galutinis_vidurkis;
		fr.width(20); fr << std::left << i.galutinis_mediana;

		fr << std::endl;
	}
	
	fr.close();
}
void InputOutput_LISTAI(std::string pav)
{
	
	auto start1 = std::chrono::high_resolution_clock::now();

	// SORTAS PAGAL VARDUS
	Studentai_Listai.sort(Pagal_Varda_Listai5);
	
	auto finish1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed1 = finish1 - start1;
	std::cout << "Programos vykdymo laikas su listais: " << elapsed1.count() << " s\n";
	std::ofstream fr;
	fr.open("Rezultatai_Listai.txt");

	fr.width(15); fr << std::left << "Pavarde";
	fr.width(15); fr << std::left << "Vardas";
	fr.width(15); fr << std::left << "ND-1";
	fr.width(15); fr << std::left << "ND-2";
	fr.width(15); fr << std::left << "ND-3";
	fr.width(15); fr << std::left << "ND-4";
	fr.width(15); fr << std::left << "ND-5";
	fr.width(15); fr << std::left << "Egzaminas";
	fr.width(20); fr << std::left << "Galutinis-vidurkis";
	fr.width(20); fr << std::left << "Galutinis-mediana";
	fr.width(20); fr << std::left << "Kategorija";
	fr << std::endl;

	for (auto i : Studentai_Listai)
	{
		//SPAUSDINIMAS KIETAKUS
		fr.width(15); fr << std::left << i.Pavarde;
		fr.width(15); fr << std::left << i.Vardas;
		fr.width(15); fr << std::left << i.nd1;
		fr.width(15); fr << std::left << i.nd2;
		fr.width(15); fr << std::left << i.nd3;
		fr.width(15); fr << std::left << i.nd4;
		fr.width(15); fr << std::left << i.nd5;
		fr.width(15); fr << std::left << i.egzaminas;
		fr.width(20); fr << std::left << std::setprecision(3) << i.galutinis_vidurkis;
		fr.width(20); fr << std::left << i.galutinis_mediana;

		fr << std::endl;
	}
	fr.close();
}