#include "funkcijos.h"

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
std::vector<int> skivedimas(int &n)
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
std::vector<int> generavimas (int &n)
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
Studentas vivedimas( int &n, char &ranka, char &mediana)
{
    Studentas a;
    std::string vardas, pavarde;
    std::vector<int> nd;
    int pzmsk, egzas, galas; 
    std::cout << "Iveskite " << n+1 << "-ojo studento varda ir pavarde ";
    std::cin >> vardas >> pavarde;       
    a.setvarpar( vardas, pavarde );
    if (ranka == 'r') nd = skivedimas(n);
    else nd = generavimas(n);  
    std::cout << "Iveskite " << n+1 << "-ojo studento egzamino bala ";
    std::cin >> egzas;
    patikrint(egzas);
    a.setpazymiai(nd,egzas); 
    a.galutiniz (mediana);         
    return a;
}

Studentas eilutinejimas(int &k, char &mediana, std::string &ei)
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
void skaitymasfailo( std::vector<Studentas> &a, char &mediana, std::string failopavadinimas )
{    
    int k = 0, nd = 0 ;
    std::string vardas, pavarde, eilute, kiek; 
    std::ifstream fd;
    
    fd.open (failopavadinimas);
    if (!fd.is_open()) 
    {
        std::cout << "KLAIDA:: NERA TOKIO FAILO, todel viska veskite ranka :) " << std::endl;
        ivedinejimas(a, mediana);
        return; 
    }
    getline (fd, eilute);
    std::istringstream na(eilute);    
    while ( na >> kiek ) nd++;
    nd = nd - 3;    
    fd.clear();
    fd.seekg (0, std::ios::beg);
    while ( getline (fd, eilute) )
    {
        a.push_back(eilutinejimas( nd, mediana,  eilute ));    
        k++;
    }
}

void ivedinejimas(std::vector<Studentas> &a,  char &mediana)
{
    char ranka;
    int n;
    std::cout << "Kiek studentu vesite? ";
    std::cin >> n;
    skpatikrinimas(n);
    std::cout << "Ar pazymius vesite ranka ar generuoti atsitiktinai? ('r' - ranka; 'g' - generuoti) ";
    std::cin >> ranka;
    cpatikrinimas(ranka, 'r','g');   
    for (int i = 0; i < n; i++)
    a.push_back(vivedimas(i, ranka, mediana));
}

// cia ivedinejimo pradzia 
std::vector<Studentas> nuskaitymas (int &n, char &failai)
{    
    char ivedimas, mediana;
    std::cout << "Ar norite genruoti 5 studentu failus ? ('t' - taip; 'n' - ne )";
    std::cin >> failai;
    cpatikrinimas(failai, 't','n'); 
    if (failai == 'n') 
    {
    std::cout << "Ar vesite studentus ranka ar skaitysite viska is failo? ('i' - irasymas; 'f' - failas )";
    std::cin >> ivedimas;
    cpatikrinimas(ivedimas, 'i','f'); 
    }
    std::cout << "Skaiciuoti namu darbu pazymiu vidurki ar mediana?  ('m' - mediana; 'v' - vidurki) ";
    std::cin >> mediana; 
    cpatikrinimas(mediana, 'm','v'); 
    std::vector<Studentas> a;

    if (failai == 't') tekstogeneravimas (a, mediana);
    else if (ivedimas == 'f') skaitymasfailo(a, mediana, "Studentai.txt");
    else ivedinejimas(a, mediana);

    n = a.size();     
    return a;  
}

bool alfa(Studentas &a, Studentas &b)
{
    return a.getvar() < b.getvar();
}

// duomenu isvedimo funkcija/
void isvedimas( std::vector<Studentas> &a, int &n, std::string failovardas)
{
    std::ofstream fr ("Rez"  + failovardas);   
    std::string br (70, '-');
    fr << std::left << std::setw(25) << "Vardas" << std::left << std::setw(25) << "Pavarde" << std::right << std::setw(10) << "Metinis" << std::endl;        
    fr << br << std::endl;
    sort(a.begin(), a.end()-1, alfa);
    for (int i = 0; i < n; i++)    
    fr << std::left << std::setw(25) << a[i].getvar() << std::left << std::setw(25) << a[i].getpav() << std::right << std::setw(8) << std::fixed << std::setprecision(2) << a[i].getpazymiai() << std::endl;             
    fr.close();
}