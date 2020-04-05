//cia bendros funkcijos

#include "headeriai/funkcijos.h"
#include "headeriai/templatai.h"

// cia patikrina ar ivede neneigiama skaiciu studentu ir ar ne raide
void skpatikrinimas (int &n)
{
    while(!n || n < 0)
    {
        std::cout << "KLAIDA: IVESKITE TAISYKLINGA SKAICIU  ";
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
        std::cout << "KLAIDA: IVESKITE TAISYKLINGA  RAIDE " << b << " arba " << c << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin >> a;
    }
}

void c2patikrinimas(char &a, char b, char c, char d)
{
    while( a !=b && a!=c && a!=d )
    {
        std::cout << "KLAIDA: IVESKITE TAISYKLINGA  RAIDE " << b << " arba " << c << std::endl;
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
        std::cout << "KLAIDA: IVESKITE SKAICIU NUO 1 IKI 10 \n ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin >> sk;
    }
}

// cia funkcija kur ivedinet studento pazymius
std::vector<int> skaiciu_ivedimas(int &n)
{
    int sk;
    std::vector<int> s;
    std::cout << "Ivedinekite " << n+1 << "-ojo studento pazymius (veskite 0 kad sustotumet) " << std::endl;
    do
    {   std::cin >> sk;
        patikrint(sk);
        if (!sk == 0) s.push_back(sk);
    } while (sk);
    return s;    
}

// cia random skaiciuku generavimas 
std::vector<int> skaiciu_generavimas (int &n)
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

// sita funkcija studentu informacijos ivedinejimui
Studentas vardu_ivedimas( int &n, char &ranka, char &mediana)
{
    Studentas a;
    std::string vardas, pavarde;
    std::vector<int> nd;
    int pzmsk, egzas, galas; 
    std::cout << "Iveskite " << n+1 << "-ojo studento varda ir pavarde ";
    std::cin >> vardas >> pavarde;       
    a.setvarpar( vardas, pavarde );

    if (ranka == 'r') nd = skaiciu_ivedimas(n);
    else nd = skaiciu_generavimas(n);  

    std::cout << "Iveskite " << n+1 << "-ojo studento egzamino bala ";
    std::cin >> egzas;
    patikrint(egzas);
    a.setpazymiai(nd,egzas); 
    a.galutiniz (mediana);         
    return a;
}

Studentas eiluciu_skaitymas(int &k, char &mediana, std::string &ei)
{
    Studentas a;
    int egz;
    std::string naujas;
    std::string vardas, pavarde;
    std::vector<int> nd;
    std::istringstream e(ei);    
    e >> vardas >> pavarde;   
    a.setvarpar(vardas, pavarde); 
    for ( int i = 0; i < k ; i++ )
    {
        e >> naujas;
        nd.push_back(stoi(naujas));
    }   
    e >> egz;
    a.setpazymiai(nd, egz);
    a.galutiniz (mediana); 
    return a;
}

bool maziau_uz_5 ( Studentas &s)
{
    return s.getpazymiai() < 5;
}

bool daugiau_uz_5 ( Studentas &s)
{
    return s.getpazymiai() >= 5;
}