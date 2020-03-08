#pragma once

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <random>
#include <iomanip>
#include "Studentas.h"
#include "funkcijos2.h"


// cia patikrina ar ivede neneigiama skaiciu studentu ir ar ne raide
void skpatikrinimas(int &n);

// cia patikrina ar ivede tinkamas raides
void cpatikrinimas(char &a, char &b, char &c);

// cia patikrina ar ivede skaicius nuo 1 iki 10
void patikrint(int &sk);

// cia funkcija kur ivedinet studento pazymius
std::vector<int> skivedimas(int &n);

// cia random skaiciuku generavimas
std::vector<int> generavimas(int &n, char &a);

// sita funkcija studentu informacijos ivedinejimui
Studentas vivedimas(int &n, char &ranka, char &mediana);

Studentas eilutinejimas(int &k, char &mediana, std::string &ei);

void skaitymasfailo(std::vector<Studentas> &a, char &mediana, std::string failopavadinimas);

void ivedinejimas(std::vector<Studentas> &a, char &mediana);

// cia ivedinejimo pradzia
std::vector<Studentas> nuskaitymas(int &n, char &failai);

bool alfa(Studentas &a, Studentas &b);

// duomenu isvedimo funkcija/
void isvedimas(std::vector<Studentas> &a, int &n, std::string failovardas);