#include "headeriai/funkcijos2.h"
#include <random>
#include <fstream>
#include "headeriai/funkcijos.h"
#include <iostream>
#include <cmath>
#include <chrono>

#define FAILU_SK 5 //generuojamu failu skaicius

//      mielieji, sia is tiesu puikia diena gadintis prakeiktu c++ nenorejau, taciau likimas mane vercia daryti kitaip.
///     ta proga eilerastukas ir eglute:
////
/////            Stai penktadienis atejo
//////           Jolkai tik dabar daejo
//////           Kad ir vel ji suda male
///////          Ir per sazine jai kale
////////         Na, taciau, turiu nuvilti
/////////        Jog lengviau yra pamilti
//////////       Nei surasti ikvepimo
///////////      Ant nemylimo zaidimo
////////////     Stai todel sia grazia diena
/////////////    Man nesikepa vistiena
//////////////   Noriu biski pailseti
//////////////   Bet lol netureciau buti pavargus int the first place :)
//          
//                  THE END

bool beta(Studentas &a, Studentas &b)
{
    return a.getpazymiai() < b.getpazymiai();
}

void tekstogeneravimas (std::vector<Studentas> &a,  char &mediana)
{ 
    srand (time(NULL));    
    int pazymiusk = 10 ;
    int failusk;
    int k = 0;
    std::vector<Studentas> protingas;
    std::vector<Studentas> vargsas;
    int vidurinis;

    std::cout << "----------------------------------------------" << std::endl << std::endl;
    
    for (int z = 0; z < FAILU_SK; z++ )
    {        
        failusk = 1000*pow(10,z);
        a.reserve(failusk);
        std::ofstream dr ("students" + std::to_string(failusk) + ".txt");
        auto start = std::chrono::system_clock::now();
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
        sort(a.begin(), a.end(), beta);
        for (int i = 0; i < a.size()-1; i++ )
        {
            if ( a[i].getpazymiai() >= 5 )
            {
                vidurinis = i ;
                break;
            }
        }
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Vidurinio suradimas uztruko " << elapsed_seconds.count() << std::endl;        

        start = std::chrono::system_clock::now();
        for (int i = 0; i <= vidurinis; i++)
        {
           vargsas.push_back(a[i]);
        } 
               
        for (int i = vidurinis; i < a.size(); i++)
        {
           protingas.push_back(a[i]);
        }       
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Perrasymas i du vektorius " << elapsed_seconds.count() << std::endl;
        a.clear();
        start = std::chrono::system_clock::now();
        int kazkas = failusk - vidurinis;
        isvedimas(vargsas, vidurinis, std::to_string(failusk) + "protingi.txt", mediana);
        isvedimas(protingas, kazkas, std::to_string(failusk) + "vargsai.txt", mediana);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Isvedimas uztruko " << elapsed_seconds.count() << std::endl;
        std::cout << "----------------------------------------------" << std::endl << std::endl;
    }  

}

