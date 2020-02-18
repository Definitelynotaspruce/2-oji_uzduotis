#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <iomanip>

struct studentas
{
    std::string vardas, pavarde;
    std::vector<int> paz;
    int egz;
    int pskc = 0;
    double galutinis;
};

// cia patikrina ar ivede neneigiama skaiciu studentu ir ar ne raide
void skpatikrinimas (int &n)
{
    while(!n || n < 0)
    {
        std::cout << "KLAIDA: IVESKITE NORMALU SKAICIU :) ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin >> n;
    }
}

// cia patikrina ar ivede tinkamas raides
void cpatikrinimas(char &a, char b, char c)
{
    while( a !=b && a!=c )
    {
        std::cout << "KLAIDA: IVESKITE NORMALIA RAIDE :) ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin >> a;
    }
}

// cia patikrina ar ivede skaicius nuo 1 iki 10
void patikrint (int &sk )
{       
    while( sk < 0 || sk > 10 || std::cin.fail() )
    {
        std::cout << "KLAIDA: IVESKITE NORMALU SKAICIU NUO 1 IKI 10 :)\n ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin >> sk;
    }
}

// cia funkcija kur ivedinet studento pazymius
std::vector<int> skivedimas(int n)
{
    int sk;
    std::vector<int> s;
    std::cout << "Ivedinekite " << n+1 << "-ojo studento pazymius (veskite 0 kad sustotumet) " << std::endl;
    do
    {   std::cin >> sk;
        patikrint(sk);
        s.push_back(sk);
    }   while ( sk );
    return s;    
}

// cia random skaiciuku generavimas 
std::vector<int> generavimas (int n)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> Skaicius(1, 10);
	std::uniform_int_distribution<> pazym_sk(3, 10); // naudojamas pazymiu skaiciui sugeneruot

    std::vector<int> s;
    for (int i = 0; i < pazym_sk(gen); i++)
    {  
        s.push_back(Skaicius(gen));
    }
    return s;
}

// cia medianai apskaiciuoti
double mmediana (int n, std::vector<int> sk)
{
    std::sort(sk.begin(), sk.end());
    if (n % 2 != 0)  return (double)sk[n / 2];  
    return (double)(sk[(n - 1) / 2] + sk[n / 2]) / 2.0; 
}

// cia vidurkiui apskaiciuoti
double vidurkis (int n, std::vector<int> sk )
{
    double suma;
    for (int i = 0; i < n; i++)
    {
        suma+=sk[i];
    }
    return suma/n;
}

// sita funkcija studentu informacijos ivedinejimui
studentas vivedimas( int n, char ranka, char mediana)
{
    studentas b;
    std::cout << "Iveskite " << n+1 << "-ojo studento varda ";
    std::cin >> b.vardas;    
    std::cout << "Iveskite " << n+1 << "-ojo studento pavarde ";
    std::cin >> b.pavarde;

    if (ranka == 'r') b.paz = skivedimas(n);
    else b.paz = generavimas(n);

    b.pskc = b.paz.size();

    std::cout << "Iveskite " << n+1 << "-ojo studento egzamino bala ";
    std::cin >> b.egz;
    patikrint(b.egz);

    if (b.pskc == 0 ) b.galutinis = b.egz*0.6;
    else if (mediana == 'm') b.galutinis = mmediana(b.pskc, b.paz)*0.4 + b.egz*0.6;
    else b.galutinis = vidurkis(b.pskc, b.paz);
        
    return b;
}

// cia ivedinejimo pradzia 
std::vector<studentas> nuskaitymas (int &n)
{    
    char ranka, mediana;
    std::cout << "Kiek studentu vesite? ";
    std::cin >> n;
    skpatikrinimas(n);
     std::cout << "Ar pazymius vesite ranka ar generuoti atsitiktinai? ('r' - ranka; 'g' - generuoti) ";
    std::cin >> ranka;
    cpatikrinimas(ranka, 'r','g');
    std::cout << "Skaiciuoti namu darbu pazymiu vidurki ar mediana?  ('m' - mediana; 'v' - vidurki) ";
    std::cin >> mediana; 
    cpatikrinimas(mediana, 'm','v');  
    std::vector<studentas> a;
    for (int i = 0; i < n; i++)
    {
        a.push_back(vivedimas(i, ranka, mediana));
    }  
    return a;  
}

// duomenu isvedimo funkcija
void isvedimas( std::vector<studentas> a, int n)
{
    std::string br(70, '-');
    std::cout << br<<std::endl;
    std::cout << "Vardas \t Pavarde \t" << std::fixed  << std::setprecision(2) <<  "Galutinis pazymys" << std::endl;
    std::cout << br<<std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i].vardas << "\t" << a[i].pavarde << "\t\t\t" << a[i].galutinis << std::endl;
    }
}

int main()
{
    int n;
    std::vector<studentas> stud = nuskaitymas(n); 
    isvedimas(stud, n);    
    return 0;

}