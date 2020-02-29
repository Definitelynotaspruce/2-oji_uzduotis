#include "Studentas.h"

void Studentas::setvarpar(std::string a, std::string b)
{
    vardas = a;
    pavarde = b;
}
void Studentas::setpazymiai(std::vector<int> a, int b)
{
    paz = a;
    egz = b;
}
void Studentas::galutiniz(char a)
{
    if (paz.size() == 0)
        galutinis = egz * 0.6;
    else if (a == 'm')
        galutinis = mmediana(paz) * 0.4 + egz * 0.6;
    else
        galutinis = vidurkis(paz) * 0.4 + egz * 0.6;
}
std::string Studentas::getvar() { return vardas; }
std::string Studentas::getpav() { return pavarde; }
double Studentas::getpazymiai() { return galutinis; }

// cia medianai apskaiciuoti
double Studentas::mmediana ( std::vector<int> sk)
{
    std::sort(sk.begin(), sk.end());
    if (sk.size() % 2 != 0)  return (double)sk[sk.size() / 2];  
    return (double)(sk[(sk.size() - 1) / 2] + sk[sk.size() / 2]) / 2.0; 
}

// cia vidurkiui apskaiciuoti
double Studentas::vidurkis ( std::vector<int> sk )
{
    double suma;
    for (int i = 0; i < sk.size(); i++) suma+=sk[i];
    return suma/sk.size();
}