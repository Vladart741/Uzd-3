#include<string>
#include<list>
#include<vector>
#include<deque>
#include "Struktura.h"

#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

// BENDROS
void Failu_Generatorius(std::string pav, int n);
void pradedam_be_algoritmu_antra_str(std::string pav);
void pradedam_be_algoritmu_pirma_str(std::string pav);
void pradedam_su_algoritmais_pirma_str(std::string pav);
void pradedam_su_algoritmais_antra_str(std::string pav);
void pradedam_InputOutput(std::string pav);

// 1 STRATEGIJA
void InputOutput_VEKTORIUS_Pirma_Strategija_BE_ALGORITMU(std::string pav);
void InputOutput_DEKAI_Pirma_Strategija_BE_ALGORITMU(std::string pav);
void InputOutput_LISTAI_Pirma_Strategija_BE_ALGORITMU(std::string pav);
void InputOutput_VEKTORIUS_Pirma_Strategija(std::string pav);
void InputOutput_DEKAI_Pirma_Strategija(std::string pav);
void InputOutput_LISTAI_Pirma_Strategija(std::string pav);
void nuskaitymas_1str_be_alg(std::string pav);
void nuskaitymas_1str_su_alg(std::string pav);

// 2 STRATEGIJA
void InputOutput_VEKTORIUS_Antra_Strategija_BE_ALGORITMU(std::string pav);
void InputOutput_DEKAI_Antra_Strategija_BE_ALGORITMU(std::string pav);
void InputOutput_LISTAI_Antra_Strategija_BE_ALGORITMU(std::string pav);
void InputOutput_VEKTORIUS_Antra_Strategija(std::string pav);
void InputOutput_DEKAI_Antra_Strategija(std::string pav);
void InputOutput_LISTAI_Antra_Strategija(std::string pav);
void nuskaitymas_2str_su_alg(std::string pav);
void nuskaitymas_2str_be_alg(std::string pav);

//INPUT OUTPUT
void InputOutput_VEKTORIUS(std::string pav);
void InputOutput_DEKAI(std::string pav);
void InputOutput_LISTAI(std::string pav);
void nuskaitymas(std::string pav);

int main();



#endif
