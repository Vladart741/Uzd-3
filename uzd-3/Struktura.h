#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>


#ifndef STRUKTURA_H
#define STRUKTURA_H

/*struct Duomenys
{
std::string Vardas;
std::string Pavarde;
double nd1;
double nd2;
double nd3;
double nd4;
double nd5;
double egzaminas;
double galutinis_vidurkis;
double galutinis_mediana;
};*/

class Studentai
{
private:
	std::string Vardas;
	std::string Pavarde;
	double egzaminas;
	std::vector<double>pazymiai;
	double galutinis_balas;

public:

	Studentai() : egzaminas(0), galutinis_balas(0) {}

	void Set_gal_bal(double x)
	{
		galutinis_balas = x;
	}

	
	inline std::string vardas_get() const { return Vardas; }
	inline std::string pavarde_get() const { return Pavarde; }
	inline double egzaminas_get() const { return egzaminas; }
	inline std::vector<double> pazymiai_get() const { return pazymiai; }
	inline double galutinis_get() const { return galutinis_balas; }
	void nuskaityti(std::istream &fd);

};




#endif
