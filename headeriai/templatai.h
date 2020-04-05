#include <string>
#include <exception>

template <typename Container>
Container nuskaitymas (char &failai)
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
    
    Container a;

    if (failai == 't') tekstogeneravimas (a, mediana);
    else if (ivedimas == 'f') skaitymasfailo(a, mediana, "Studentai.txt");
    else ivedinejimas(a, mediana);
         
    return a;  
}

template <typename Container>
void isvedimas(Container &a, std::string failoVardas)
{
    std::ofstream fr ("Rez"  + failoVardas);   
    std::string br (70, '-');
    fr << std::left << std::setw(10) << "Vardas" << std::left << std::setw(10) << "Pavarde" << std::right << std::setw(10) << "Metinis" << std::endl;        
    fr << br << std::endl;    
    auto it = a.begin();
    while (it != a.end())
    {
        fr << std::left << std::setw(15) << (*it).getvar() << std::left << std::setw(15) << (*it).getpav() << std::right << std::setw(4) << std::fixed << std::setprecision(2) << (*it).getpazymiai() << std::endl;             
        it++;
    }     
    fr.close();
}

template <typename Container>
void skaitymasfailo( Container &a, char &mediana, std::string failopavadinimas )
{    
    int nd = 0 ; // kintamieji elementu skaiciui saugoti
    std::string vardas, pavarde, eilute, kiek; 
    std::ifstream fd;
    try
    {
        fd.open (failopavadinimas);
        if(!fd.is_open())
        {
            throw std::ios_base::failure("KLAIDA:: NERA TOKIO FAILO, todel viska veskite ranka :) ");
        }
        getline (fd, eilute);
        std::istringstream na(eilute);    
        while ( na >> kiek ) nd++;
        nd = nd - 3;    
        fd.clear(); //cia kad nusoktu i pacia pradzia
        fd.seekg (0, std::ios::beg);
        while ( getline (fd, eilute) )
        {
            a.push_back(eiluciu_skaitymas( nd, mediana,  eilute ));    
        }
        fd.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        ivedinejimas(a, mediana);
        return; 
    }
}

template <typename Container>
void ivedinejimas(Container &a,  char &mediana)
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
    a.push_back(vardu_ivedimas(i, ranka, mediana));
}

template <typename Container>
void tekstogeneravimas (Container &a,  char &mediana)
{ 
    srand (time(NULL));    
    int pazymiusk = 10 ;
    int failusk;
    int k = 0;
    Container protingas;
    Container vargsas;
    auto vidurinis = a.begin();
    std::cout << "----------------------------------------------" << std::endl << std::endl;
    
    for (int z = 0; z < FAILU_SK; z++ )
    {   
        failusk = 1000*pow(10,z);
        
        auto start = std::chrono::system_clock::now();

        std::ofstream dr ("students" + std::to_string(failusk) + ".txt");
        std::cout << "Failas " << "students" + std::to_string(failusk) + ".txt" << " atidarytas " << std::endl;

        for (int i = 0; i < failusk ; i++ )
        {
            dr << std::left << "Studentas" << std::setw(10) << rand()%100 << std::left << "Pavarde" <<  rand()%100 << std::right << std::setw(10);
    
            for (int j = 0; j < pazymiusk; j++ )
            dr <<  rand()%10 +1  << "\t" ;
        
            dr << std::endl;
        }
        dr.close();
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << std::endl << "Failo generavimas uztruko " << elapsed_seconds.count() << std::endl;   
        
        start = std::chrono::system_clock::now();        
        skaitymasfailo(a, mediana, "students" + std::to_string(failusk) + ".txt");
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Skaitymas is failo uztruko " << elapsed_seconds.count() << std::endl;

        start = std::chrono::system_clock::now(); 
        //conteineriu split funkcijos
        split_1  (a, protingas, vargsas);
        //split_2 (a, protingas, vargsas);  
        //split_3 (a, vargsas);
        //split_4 (a, protingas, vargsas);
        end = std::chrono::system_clock::now();        
        elapsed_seconds = end - start;
        std::cout << "Vektoriu perrasymas uztruko " << elapsed_seconds.count() << std::endl;           
        
        start = std::chrono::system_clock::now();        
       //int protinguSk = a.size();
        isvedimas(vargsas, std::to_string(failusk) + "vargsai.txt");
        isvedimas(protingas, std::to_string(failusk) + "protingi.txt"); 
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Isvedimas uztruko " << elapsed_seconds.count() << std::endl;
        std::cout << "----------------------------------------------" << std::endl << std::endl; 
    }  
}

template <typename Container>
void split_1(Container &studentai, Container &protingi, Container &vargsai)
{
    std::remove_copy_if ( studentai.begin(), studentai.end(), std::back_inserter(vargsai), daugiau_uz_5 );    
    std::copy_if ( studentai.begin(), studentai.end(), std::back_inserter(protingi), daugiau_uz_5 );   
    studentai.erase (studentai.begin(), studentai.end());
}

template <typename Container>
void split_2(Container &studentai, Container &protingi, Container &vargsai)
{
    std::remove_copy_if ( studentai.begin(), studentai.end(), std::back_inserter(vargsai), daugiau_uz_5 );    
    studentai.erase ( remove_if ( studentai.begin(), studentai.end(), maziau_uz_5), studentai.end() );    
}

template <typename Container>
void split_3(Container &studentai, Container &vargsai)
{
    auto it = stable_partition (studentai.begin(), studentai.end(), daugiau_uz_5);
    copy ( it , studentai.end(), std::back_inserter(vargsai));
    studentai.erase(it, studentai.end());
}

template <typename Container>
void split_4(Container &studentai, Container &protingi, Container &vargsai)
{
    std::remove_copy_if ( studentai.begin(), studentai.end(), std::back_inserter(vargsai), daugiau_uz_5 );    
    std::copy_if ( studentai.begin(), studentai.end(), std::back_inserter(protingi), daugiau_uz_5 );   
}
