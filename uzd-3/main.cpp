#include <iostream>
#include <vector>
#include "Funkcijos.h"
#include <chrono>
#include <fstream>

int main()
{
	std::string pav;
	int n;

	std::cout << "Iveskite:" << std::endl;

	std::cout << "(1) jei norite sugeneruoti nauja faila." << std::endl;
	std::cout << "(2) jei norite nuskatityti egzistuojanti faila." << std::endl;
	std::cout << "(3) jei norite sugeneruoti ir nuskaityti nauja faila." << std::endl;
	std::cout << "(4) jei norite nuskatityti egzistuojanti faila pagal PIRMA STRATEGIJA" << std::endl;
	std::cout << "(5) jei norite nuskatityti egzistuojanti faila pagal ANTRA STRATEGIJA" << std::endl;

pradzia:
	std::string ats;
	std::cin >> ats;
	if (ats == "2")
	{
		std::cout << "Iveskite failo pavadinima: ";
		std::cin >> pav;
		pradedam_InputOutput(pav);

		system("pause");
	}
	else if (ats == "3")
	{
		pav = "Duomenys.txt";
		std::cout << "Iveskite failo dydi: ";
		std::cin >> n;


		Failu_Generatorius(pav, n);
		pradedam_InputOutput(pav);

		system("pause");
	}
	else if (ats == "1")
	{
		std::cout << "Iveskite failo pavadinima: ";
		std::cin >> pav;
		pav = pav + ".txt";
		std::cout << "Iveskite failo dydi: ";
		std::cin >> n;

		Failu_Generatorius(pav, n);
		std::cout << std::endl;
		std::cout << "Sugeneruota sekmingai." << std::endl;
		std::cout << std::endl;
		main();
	}
	else if (ats == "4")
	{
		std::cout << "Jei norite nuskaityti 1 faila naudojant algoritmus, iveskite (1) " << std::endl;
		std::cout << "Jei norite nuskaityti 1 faila be algoritmu, iveskite (2) " << std::endl;
	taskas:
		std::cin >> ats;
		if (ats == "1")
		{
			std::cout << "Iveskite failo pavadinima: ";
			std::cin >> pav;
			pradedam_su_algoritmais_pirma_str(pav);		

			system("pause");
		}
		else if (ats == "2")
		{
			std::cout << "Iveskite failo pavadinima: ";
			std::cin >> pav;
			pradedam_be_algoritmu_pirma_str(pav);
			system("pause");
		}
		else
		{
			std::cout << "SKAICIU (1) Jei norite nuskaityti 1 faila naudojant algorimus" << std::endl;
			std::cout << "SKAICIU (2) Jei norite nuskaityti 1 faila be algoritmu" << std::endl;
			goto taskas;
		}
	}
	else if (ats == "5")
	{
		std::cout << "Jei norite nuskaityti 1 faila naudojant algoritmus, iveskite (1) " << std::endl;
		std::cout << "Jei norite nuskaityti 1 faila be algoritmu, iveskite (2) " << std::endl;
	taskas2:
		std::cin >> ats;
		if (ats == "1")
		{
			std::cout << "Iveskite failo pavadinima: ";
			std::cin >> pav;
			pradedam_su_algoritmais_antra_str(pav);
			system("pause");
		}
		else if (ats == "2")
		{
			std::cout << "Iveskite failo pavadinima: ";
			std::cin >> pav;
			pradedam_be_algoritmu_antra_str(pav);

			system("pause");
		}
		
		else
		{
			std::cout << "SKAICIU (1) Jei norite nuskaityti 1 faila naudojant algorimus" << std::endl;
			std::cout << "SKAICIU (2) Jei norite nuskaityti 1 faila be algoritmu" << std::endl;
			goto taskas2;
		}
	}


	else
	{
		std::cout << "Iveskite:<" << std::endl;
		std::cout << "SKAICIU (1) jei norite nuskatityti egzistuojanti faila." << std::endl;
		std::cout << "SKAICIU (2) jei norite sugeneruoti nauja faila." << std::endl;
		std::cout << "SKAICIU (3) jei norite sugeneruoti ir nuskaityti nauja faila." << std::endl;
		std::cout << "SKAICIU (4) jei norite nuskatityti egzistuojanti faila pagal PIRMA STRATEGIJA" << std::endl;
		std::cout << "SKAICIU (5) jei norite nuskatityti egzistuojanti faila pagal ANTRA STRATEGIJA" << std::endl;
		goto pradzia;
	}



	return 0;
}