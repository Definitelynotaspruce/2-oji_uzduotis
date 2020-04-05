#pragma once

#include "Studentas.h"
#include <list>
#include <deque>
#include <iostream>
#include <sstream>
#include <fstream>
#include <random>
#include <iomanip>
#include <random>
#include <cmath>
#include <chrono>

#define FAILU_SK 5 //generuojamu failu skaicius

// cia patikrina ar ivede neneigiama skaiciu studentu ir ar ne raide
void skpatikrinimas(int &n);

// cia patikrina ar ivede tinkamas raides
void cpatikrinimas(char &a, char b, char c);
void c2patikrinimas(char &a, char b, char c, char d);

// cia patikrina ar ivede skaicius nuo 1 iki 10
void patikrint(int &sk);

// cia funkcija kur ivedinet studento pazymius
std::vector<int> skaiciu_ivedimas(int &n);

// cia random skaiciuku generavimas
std::vector<int> skaiciu_generavimas(int &n, char &a);

// sita funkcija studentu informacijos ivedinejimui
Studentas vardu_ivedimas(int &n, char &ranka, char &mediana);

Studentas eiluciu_skaitymas(int &k, char &mediana, std::string &ei);

bool alfa(Studentas &a, Studentas &b);
bool beta(Studentas &a, Studentas &b);
bool maziau_uz_5 ( Studentas &s);
bool daugiau_uz_5 ( Studentas &s);

