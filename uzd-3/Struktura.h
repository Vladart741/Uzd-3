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
std::vector<double>pazymiai;
double egzaminas;
double galutinis_vidurkis;
double galutinis_mediana;
};*/

class Zmogus
{
protected:
	std::string Vardas;
	std::string Pavarde;
};


class Studentai : public Zmogus
{
private:
	double egzaminas;
	std::vector<double>pazymiai;
	double galutinis_balas;

public:

	Studentai() : egzaminas(0), galutinis_balas(0) {}

	void Set_gal_bal(double x)
	{
		galutinis_balas = x;
	}

	
	std::string vardas_get() const { return Vardas; }
	std::string pavarde_get() const { return Pavarde; }
	double egzaminas_get() const { return egzaminas; }
	std::vector<double> pazymiai_get() const { return pazymiai; }
	double galutinis_get() const { return galutinis_balas; }
	void nuskaityti(std::istream &fd);

	friend bool operator+(const Studentai &Student, const Studentai &Student2);
	friend bool operator-(const Studentai &Student, const Studentai &Student2);
	friend bool operator<(const Studentai &Student, const Studentai &Student2);
	friend bool operator>(const Studentai &Student, const Studentai &Student2);

};




#endif
