#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <iomanip>
#include "headeriai/Studentas.h"
#include "headeriai/funkcijos.h"
#include <sstream>
#include "headeriai/funkcijos2.h"

int main()
{
    int n;
    char a;
    std::deque<Studentas> stud = nuskaitymas(n, a); 
    if (a != 't') 
    {  
        isvedimas (stud, n, "rezultatai.txt", a); 
    }
    std::cin.get();
    return 0;
} 