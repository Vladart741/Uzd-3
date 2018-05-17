#include "Struktura.h"

#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

void Failu_Generatorius(std::string pav, int n);
double vidurkis(std::vector <double> pazymiai);
double mediana(double egzaminas, std::vector<double> pazymiai);
void Sortas(std::vector<Studentai> &Student);
bool vargsiukai_atranka(Studentai &Student);
bool kietiakai_atranka(Studentai &Student);
bool rusiavimas_pagal_varda(const Studentai &x, const Studentai &y);

#endif

template <typename T>
void nuskaitymas(T &Studentas,int n, std::string pav)
{
	std::ifstream fd(pav);
	for(int i=0; i<n; i++)
	{
		Studentai Student;
		Student.nuskaityti(fd);
		Studentas.push_back(Student);
	}
}

template <typename T>
void Sortas(T &Student)
{
	std::sort(Student.begin(), Student.end(), rusiavimas_pagal_varda);
}

template <typename T>
T KietiakaiSort(T &Student)
{
	std::vector<Studentai>::iterator it;
	it = std::stable_partition(Student.begin(), Student.end(), kietiakai_atranka);
	T Kietiakai(it, Student.end());
	return Kietiakai;
}

template <typename T>
T VargsiukaiSort(T &Student)
{
	std::vector<Studentai>::iterator it;
	it = std::stable_partition(Student.begin(), Student.end(), vargsiukai_atranka);
	T Vargsiukai(it, Student.end());
	return Vargsiukai;
}

template <typename T>

void Spausdinimas(T &Kietiakai, T &Vargsiukai)
{
	std::ofstream fr("rez.txt");
	for (auto i : Kietiakai)
	{
		fr << i.vardas_get() << " " << i.pavarde_get() <<" "<< i.galutinis_get() << " Kietiakas" << std::endl;
	}
	for (auto i : Vargsiukai)
	{
		fr << i.vardas_get() << " " << i.pavarde_get() << " " << i.galutinis_get() << " Vargsiukas" << std::endl;
	}
}



