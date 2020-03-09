#pragma once

#include <string>
#include <vector>
#include <algorithm>

class Studentas
{
private:
    std::string vardas, pavarde;
    std::vector<int> paz;
    int egz;
    double galutinis;

public:
    void setvarpar(std::string &a, std::string &b);

    void setpazymiai(std::vector<int> &a, int &b);

    void galutiniz(char &a);

    std::string getvar();
    std::string getpav();

    double getpazymiai();
    double mmediana(std::vector<int> &paz);
    double vidurkis(std::vector<int> &paz);
};