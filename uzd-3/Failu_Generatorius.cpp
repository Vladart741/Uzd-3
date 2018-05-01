#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include "Struktura.h"
#include "Funkcijos.h"
#include <iomanip>


void Failu_Generatorius(std::string pav, int n)
{
	std::ofstream fr;
	fr.open(pav);

	std::default_random_engine nr;
	std::uniform_int_distribution<int> gen1(1, 10);
	std::default_random_engine nr2;
	std::uniform_int_distribution<int> gen2(1, n);


	for (int i = 0; i < n; i++)
	{
		std::string Vardas = "Vardas";
		std::string Pavarde = "Pavarde";
		int egzaminas;
		int x = gen2(nr);
		std::string sk = std::to_string(x);

		Vardas = Vardas + sk;
		fr.width(15); fr << std::left << Vardas;

		Pavarde = Pavarde + sk;
		fr.width(15); fr << std::left << Pavarde;

		for (int j = 0; j < 5; j++)
		{
			int x = gen1(nr);
			fr.width(15); fr << std::left << x;
		}
		egzaminas = gen1(nr);
		fr.width(15); fr << std::left << egzaminas;

		fr << std::endl;

	}
	fr.close();
}