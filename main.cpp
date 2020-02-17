#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <random>

struct studentas 
{
    std::string vardas, pavarde;
    int* paz = new int[1];
    int egzas, pskc;
    double gal;

};

void apskaiciavimas (bool kas, int n, studentas *a )
{
    std::sort(a->paz, a->paz + a->pskc); // Surikiuojam pazymius
		if (kas)// Mediana
		{

			if (a->pskc % 2 == 0) //Tikrinam ar lyginis skaicius elementu ar ne
			{
				a->gal = ((double)a->paz[a->pskc / 2] + a->paz[(a->pskc / 2) - 1]) / 2;
			}
			else
			{
				a->gal = a->paz[a->pskc / 2];
			}
            
		}
		else //Vidurkis
		{
			for (int x = 0; x < a->pskc; x++)
				a->gal += a->paz[x];

			a->gal = a->gal / a->pskc;
		}

		a->gal = a->gal * 0.4 + 0.6 * a->egzas;
}

void patikrinimas (char& simbolis, char pirmas, char antras)
{
    while (!(simbolis == pirmas || simbolis == antras))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Negalime nuskaityti sito, veskite dar karta normaliai " <<std::endl;
        std::cin >> simbolis;
    }
}

void pertikrinimas (int& skaicius)
{
    while (std::cin.fail() || skaicius < 0 || skaicius > 10)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Iveskit normalu skaiciu prasau " <<std::endl;
        std::cin >> skaicius;
    }
}

void generavimas(studentas *a)
{
    int sk = 0;
    int laikinas;
    
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen( rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> Skaicius(1, 10);
	std::uniform_int_distribution<> pazym_sk(4, 10); // naudojamas pazymiu skaiciui sugeneruot 

    a->pskc = pazym_sk(gen); // Sugeneruoja pazymiu skaiciu (3-10)

		do
		{
			laikinas = Skaicius(gen);
            
			int* laikinas2 = new int[sk + 1];
			for (int k = 0; k < sk; k++) laikinas2[k] = a->paz[k];
			sk++;
			delete[] a->paz;
			a->paz = laikinas2;
			a->paz[sk - 1] = laikinas;

		} while ( sk!= a->pskc);
		
		a->egzas = Skaicius(gen); // Sugeneruojam random egzamino pazymi
}

studentas* nuskaitymas ( int &n)
{    
    std::cout << "Kiek mokiniu vesite? :))) "<<std::endl;
    std::cin >> n;
    
    studentas* a = new studentas[n];
            
    char mediana;
	std::cout << "Skaiciuoti pagal mediana ar vidurki? (m - Mediana, v - Vidurkis)" << std::endl;
    std::cin >> mediana; 
    patikrinimas (mediana, 'm', 'v');
        
    for (int i = 0; i < n; i++)
	{
		std::cout << "Iveskite " << i + 1 << "-ojo studento varda: ";
		std::cin >> (a + i)->vardas;

		std::cout << "Iveskite " << i + 1 << "-ojo studento pavarde: ";
		std::cin >> (a + i)->pavarde;
	    
        generavimas(a+i);

       apskaiciavimas(mediana, n, a+i);
                		
}
return a;
}

 void isvedimas (studentas *a, int n)
{
    std::string br(70, '-');
    std::cout << br<<std::endl;

    std::cout << std::left << std::setw(10) << " Vardas " << " " << "Pavarde" << std::left << std::setw(10); 
    std::cout << std::right << std::setw(30) << std::fixed  << std::setprecision(2) <<  " Galutinis pazymys " << std::endl;

    std::cout << br<<std::endl;

    for (int i = 0; i < n; i++)
	{
		std::cout << std::left << std::setw(10) << (a + i)->vardas << " " << (a+i)->pavarde << std::left << std::setw(10); 
        std::cout << std::right << std::setw(30) << std::fixed  << std::setprecision(2) <<  (a + i)->gal << std::endl;
        
	}
} 

int main()
{
    int n = 0;
    studentas* adr = nuskaitymas( n);
    isvedimas(adr,n);
    return 0;

}