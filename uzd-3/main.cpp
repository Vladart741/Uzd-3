#include "Funkcijos.h"
#include "Struktura.h"

// O1_O2_main.cpp  
// compile with: /O1 

int main()
{
	std::string pav;
	int n;

		std::cout << "Iveskite failo pavadinima: ";
		std::cin >> pav;
		pav = pav + ".txt";
		std::cout << "Iveskite failo dydi: ";
		std::cin >> n;
		Failu_Generatorius(pav, n);
		std::cout << std::endl;
		std::cout << "Sugeneruota sekmingai." << std::endl;
		std::cout << std::endl;

		std::cout << "Vidurkis(1) ar mediana(2)?" << std::endl;
		std::string galbal;
		std::cin >> galbal;

		std::vector<Studentai> Student;
		std::vector<Studentai> Vargsiukai;
		std::vector<Studentai> Kietiakai;
		nuskaitymas(Student,n,pav);

		if (galbal == "1")
		{
			for (auto i : Student)
			{
				auto vid = vidurkis(i.egzaminas_get(), i.pazymiai_get());
				i.Set_gal_bal(vid);
			}
		}
		else if (galbal == "2")
		{
			for (auto i : Student)
			{
				auto med = mediana(i.egzaminas_get(), i.pazymiai_get());
				i.Set_gal_bal(med);
			}
		}

		
		
		Sortas(Student);

		auto start1 = std::chrono::high_resolution_clock::now();

		Kietiakai = KietiakaiSort(Student);
		Vargsiukai = VargsiukaiSort(Student);

		auto finish1 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed1 = finish1 - start1;
		std::cout << "Programos vykdymo laikas su vektoriais: " << elapsed1.count() << " s\n";
		Spausdinimas(Kietiakai, Vargsiukai);

		system("pause");
	



	return 0;
}