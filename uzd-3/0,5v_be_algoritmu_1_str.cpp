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

bool Pagal_Varda_Vektoriai(const Duomenys& x, const Duomenys& y) { return x.Vardas < y.Vardas; }
bool Pagal_Varda_Listai(const Duomenys& x, const Duomenys& y) { return x.Vardas < y.Vardas; }
bool Pagal_Varda_Dekai(const Duomenys& x, const Duomenys& y) { return x.Vardas < y.Vardas; }

std::vector<Duomenys>Studentai_Vektoriai_1str_be_alg;
std::list<Duomenys>Studentai_Listai_1str_be_alg;
std::deque<Duomenys>Studentai_Dekai_1str_be_alg;
void pradedam_be_algoritmu_pirma_str(std::string pav)
{
	nuskaitymas_1str_be_alg(pav);
	InputOutput_VEKTORIUS_Pirma_Strategija_BE_ALGORITMU(pav);
	InputOutput_LISTAI_Pirma_Strategija_BE_ALGORITMU(pav);
	InputOutput_DEKAI_Pirma_Strategija_BE_ALGORITMU(pav);
}

void nuskaitymas_1str_be_alg(std::string pav)
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
			Gal_med = (x[2] + x[3])/2;

			Duomenys something = { Vardas, Pavarde, nd1,nd2,nd3,nd4,nd5,egzaminas ,Gal_vid, Gal_med};
			Studentai_Vektoriai_1str_be_alg.push_back(something);
			Studentai_Listai_1str_be_alg.push_back(something);
			Studentai_Dekai_1str_be_alg.push_back(something);
		}
	}

}

void InputOutput_VEKTORIUS_Pirma_Strategija_BE_ALGORITMU(std::string pav)
{
	
	
	std::vector<Duomenys>Vargsiukai;
	std::vector<Duomenys>Kietiakai;
	
	// SORTAS PAGAL VARDUS
	std::sort(Studentai_Vektoriai_1str_be_alg.begin(), Studentai_Vektoriai_1str_be_alg.end(), Pagal_Varda_Vektoriai);
	auto start1 = std::chrono::high_resolution_clock::now();
	

	for (auto i : Studentai_Vektoriai_1str_be_alg) {
		if (i.galutinis_vidurkis < 5)
			{
				Vargsiukai.push_back(i);
			}
		else if (i.galutinis_vidurkis >= 5)
			{
				Kietiakai.push_back(i);
			}
	}
		
		
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

	for (auto i : Kietiakai)
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
		fr.width(20); fr << std::left << "Kietiakas";

		fr << std::endl;
	}
	for (auto i : Vargsiukai)
	{
		//SPAUSDINIMAS VARGSIUKUS
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
		fr.width(20); fr << std::left << "Vargsiukas";
		fr << std::endl;
	}
	fr.close();
}
void InputOutput_DEKAI_Pirma_Strategija_BE_ALGORITMU(std::string pav)
{
	
	
	std::deque<Duomenys>Vargsiukai;
	std::deque<Duomenys>Kietiakai;
	
	// SORTAS PAGAL VARDUS

	std::sort(Studentai_Dekai_1str_be_alg.begin(), Studentai_Dekai_1str_be_alg.end(), Pagal_Varda_Dekai);
	auto start2 = std::chrono::high_resolution_clock::now();

	for (auto i : Studentai_Dekai_1str_be_alg)
	{
		if (i.galutinis_vidurkis < 5)
		{
			Vargsiukai.push_back(i);
		}
		else if (i.galutinis_vidurkis >= 5)
		{
			Kietiakai.push_back(i);
		}
	}
	auto finish2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed2 = finish2 - start2;
	std::cout << "Programos vykdymo laikas su dekais: " << elapsed2.count() << " s\n";

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

	for (auto i : Kietiakai)
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
		fr.width(20); fr << std::left << "Kietiakas";

		fr << std::endl;
	}
	for (auto i : Vargsiukai)
	{
		//SPAUSDINIMAS VARGSIUKUS
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
		fr.width(20); fr << std::left << "Vargsiukas";
		fr << std::endl;
	}
	fr.close();
}
void InputOutput_LISTAI_Pirma_Strategija_BE_ALGORITMU(std::string pav)
{	
	std::list<Duomenys>Vargsiukai;
	std::list<Duomenys>Kietiakai;
	
	
	// SORTAS PAGAL VARDUS
	Studentai_Listai_1str_be_alg.sort(Pagal_Varda_Listai);
	auto start3 = std::chrono::high_resolution_clock::now();
	
	for (auto i : Studentai_Listai_1str_be_alg)
	{
		if (i.galutinis_vidurkis < 5)
		{
			Vargsiukai.push_back(i);
		}
		else if (i.galutinis_vidurkis >= 5)
		{
			Kietiakai.push_back(i);
		}
	}
	auto finish3 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed3 = finish3 - start3;
	std::cout << "Programos vykdymo laikas su listais: " << elapsed3.count() << " s\n";
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

	for (auto i : Kietiakai)
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
		fr.width(20); fr << std::left << "Kietiakas";

		fr << std::endl;
	}
	for (auto i : Vargsiukai)
	{
		//SPAUSDINIMAS VARGSIUKUS
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
		fr.width(20); fr << std::left << "Vargsiukas";
		fr << std::endl;
	}
	fr.close();
}