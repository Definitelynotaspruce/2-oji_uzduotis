#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <iomanip>
#include <sstream>

class studentas
{
    private:
    std::string vardas, pavarde;
    std::vector<int> paz;
    int egz;
    double galutinis;

    public:
    void setvarpar (std::string a, std::string b)
    {
        vardas = a;
        pavarde = b;
    }
    void setpazymiai (std::vector<int> a, int b )
    {
        paz = a;
        egz = b;
    }   
    void galutiniz ( char a )
    {
        if (paz.size() == 0 ) galutinis = egz*0.6;
        else if (a == 'm') galutinis = mmediana(paz)*0.4 + egz*0.6;
        else galutinis = vidurkis( paz)*0.4 + egz*0.6;
    } 
    std::string getvar() {return vardas; }
    std::string getpav() {return pavarde;}
    double getpazymiai() {return galutinis;}    
    double mmediana(  std::vector<int> paz);
    double vidurkis(  std::vector<int> paz);
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
        if (!sk == 0) s.push_back(sk);
    } while (sk);
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
double studentas::mmediana ( std::vector<int> sk)
{
    std::sort(sk.begin(), sk.end());
    if (sk.size() % 2 != 0)  return (double)sk[sk.size() / 2];  
    return (double)(sk[(sk.size() - 1) / 2] + sk[sk.size() / 2]) / 2.0; 
}

// cia vidurkiui apskaiciuoti
double studentas::vidurkis ( std::vector<int> sk )
{
    double suma;
    for (int i = 0; i < sk.size(); i++) suma+=sk[i];
    return suma/sk.size();
}

// sita funkcija studentu informacijos ivedinejimui
studentas vivedimas( int n, char ranka, char &mediana)
{
    studentas a;
    std::string vardas, pavarde;
    std::vector<int> nd;
    int pzmsk, egzas, galas; 
    std::cout << "Iveskite " << n+1 << "-ojo studento varda ";
    std::cin >> vardas;    
    std::cout << "Iveskite " << n+1 << "-ojo studento pavarde ";
    std::cin >> pavarde;
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

studentas eilutinejimas(int k, char mediana, std::string ei)
{
    studentas a;
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
void skaitymasfailo( std::vector<studentas> &a, char mediana )
{    
    int k = 0, nd = 0 ;
    int skaciukas[20];
    std::string vardas, pavarde, eilute, kiek; 
    std::ifstream fd;
    fd.open ("Studentai.txt");
    if (!fd.is_open()) { std::cout << "KLAIDA:: NERA TOKIO FAILO " << std::endl; return; }
    getline (fd, eilute);
    std::istringstream na(eilute);    
    while ( na >> kiek ) nd++;
    nd = nd - 3;    
    while ( getline (fd, eilute) )
    {
        a.push_back(eilutinejimas( nd, mediana,  eilute ));    
        k++;
    }
}

void ivedinejimas(std::vector<studentas> &a,  char &mediana)
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
std::vector<studentas> nuskaitymas (int &n)
{    
    char ivedimas, mediana;
    std::cout << "Ar vesite studentus ranka ar skaitysite viska is failo? ('i' - irasymas; 'f' - failas )";
    std::cin >> ivedimas;
    cpatikrinimas(ivedimas, 'i','f'); 
    std::cout << "Skaiciuoti namu darbu pazymiu vidurki ar mediana?  ('m' - mediana; 'v' - vidurki) ";
    std::cin >> mediana; 
    cpatikrinimas(mediana, 'm','v'); 
    std::vector<studentas> a;
    if (ivedimas == 'f') skaitymasfailo(a, mediana);
    else ivedinejimas(a, mediana);
    n = a.size();    
    return a;  
}

bool alfa(studentas a, studentas b)
{
    return a.getvar() < b.getvar();
}

// duomenu isvedimo funkcija/
void isvedimas( std::vector<studentas> a, int n)
{
    std::ofstream fr ("pazymiai.txt");
    std::string br(70, '-');
    fr << br<<std::endl;
    fr << std::left << std::setw(25) << "Vardas" << std::left << std::setw(25) << "Pavarde" << std::right << std::setw(10) << "Pazymiai" << std::endl;        
    fr << br << std::endl;
    sort(a.begin(), a.end()-1, alfa);
    for (int i = 0; i < n; i++)    
    fr << std::left << std::setw(25) << a[i].getvar() << std::left << std::setw(25) << a[i].getpav() << std::right << std::setw(8) << std::fixed << std::setprecision(2) << a[i].getpazymiai() << std::endl;             
      
} 

int main()
{
    int n;
    char med;
    std::vector<studentas> stud = nuskaitymas(n); 
    isvedimas(stud, n);    
    return 0;
}   