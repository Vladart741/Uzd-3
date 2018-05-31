#include "Funkcijos.h"
#include "Struktura.h"
#include <gtest/gtest.h>

TEST(auto, Vidurkio_testas)
{
	std::vector<double>kazkas;
	for (int i = 5; i < 10; i++)
	{
		kazkas.push_back(i);
	}
	auto vid = vidurkis(10, kazkas);

	EXPECT_EQ(7.5, vid);
}
TEST(auto, Medianos_testas)
{
	std::vector<double>kazkas;
	for (int i = 5; i < 10; i++)
	{
		kazkas.push_back(i);
	}
	auto med = mediana(10, kazkas);
	EXPECT_EQ(7.5, med);
}

int main(int argc, char* argv[])
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
		
		start:
		std::cout << "Vidurkis(1) ar mediana(2)?" << std::endl;
		std::string galbal;
		std::cin >> galbal;

		std::vector<Studentai> Student;
		std::vector<Studentai> Vargsiukai;
		std::vector<Studentai> Kietiakai;
		nuskaitymas(Student,n,pav);

		if (galbal == "1")
		{
			for(auto i = 0; i != Student.size(); i++)
			{
				auto vid = vidurkis(Student[i].egzaminas_get(), Student[i].pazymiai_get());
				Student[i].Set_gal_bal(vid);
			}
		}
		else if (galbal == "2")
		{
			for (auto i = 0; i != Student.size(); i++)
			{
				auto med = mediana(Student[i].egzaminas_get(), Student[i].pazymiai_get());
				Student[i].Set_gal_bal(med);
			}
		}
		else
		{
			goto start;
		}		
		
		Sortas(Student);

		auto start1 = std::chrono::high_resolution_clock::now();

		Kietiakai = KietiakaiSort(Student);
		Vargsiukai = VargsiukaiSort(Student);

		auto finish1 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed1 = finish1 - start1;
		std::cout << "Programos vykdymo laikas su vektoriais: " << elapsed1.count() << " s\n";
		Spausdinimas(Kietiakai, Vargsiukai);

		
	
		testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
		system("pause");


	return 0;
}
