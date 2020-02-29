#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <iomanip>
#include "Studentas.h"
#include "funkcijos.h"
#include <sstream>

int main()
{
    int n;
    std::vector<Studentas> stud = nuskaitymas(n); 
    isvedimas(stud, n);    
    return 0;
} 