#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <iomanip>
#include "Studentas.h"
#include "funkcijos.h"
#include <sstream>
#include "funkcijos2.h"

int main()
{
    int n;
    char a;
    std::vector<Studentas> stud = nuskaitymas(n, a); 
    std::cout << a << std::endl;
    if (a != 't') 
    {  
        isvedimas (stud, n, "rezultatai.txt"); 
    }
    return 0;
} 