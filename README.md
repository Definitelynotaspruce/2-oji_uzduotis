# 2-oji_uzduotis

ANTROJI OOP UŽDUOTIS - programa, apskaičiuojanti studentų metinį vidurkį

## PROGRAMOS VEIKIMO EIGA

1. Vartotojas pasirenka, ar generuos 5 failus ar tęs paprastą programos darbą:
   *  't' arba 'n'
2. Vartotojas pasirenka, ar duomenis ves pats ar skaitys iš failo:
   *  'i' arba 'f'
3. Pasirenkama, ar bus skaičiuojama namų darbų mediana ar vidurkis :
   *  'v' arba 'm'
   
Jeigu vartotojas paririnkęs, jog duomenis ves ranka:

4. Įvedamas studentų kiekis
   * skaičius
5. Pasirenkama, ar pažymiai bus vedami ranka ar generuojami atsitiktinai: 
   *  'r' arba 'g'
6. Vedamas vardas bei pavardė
7. Įvedamas egzamino balas

8. Vyksta skaičiavimas pagal formulę:
    * Galutinis rezultatas = (vidurkis arba mediana) * 0.4 + (egzamino balas) * 0.6;
    
## Kaip paleisti programą?

1. Atsisiųsti norimą release
2. Atsisiusti ir isidiegti C++ kompiliatorių (pvz GNU)
2. Atsidaryti terminalą toje atsisiųsto failo vietoje ir įrašyti komandą "make" (nuo v0.3)
3. Rašyti ./main arba main.exe (jei Windows)

# v1.0 analizė

- Programa iš prieš tai buvusių trijų skirtingų sulipdyta į vieną
- Naudojami  "template"
- Naudojami 4 skirtingi konteinerių atskyrimo būdai skirtingais algoritmais
- Pridėtas "exception"

## Pirmoji strategija
Studentai iš vieno bendro konteinerio perrašomi į du kitus atskirus naudojant remove_copy_if bei copy_if algoritmus, vėliau bendras konteineris ištrinamas.

## Antroji strategija
Tik vargsai studentai yra perrašomi iš bendro studentų konteinerio naudojant remove_copy_if funkciją, vėliau vargšai yra ištrinami.

## Trečioji strategija
Naudojant stable_partition algoritmą studentai išskirstomi į dvi dalis, vėliau naudojant copy algoritmą nukopijuojami vargšai studentai , jie ištrinami iš bendro studentų konteinerio.

## Ketvirtoji strategija
Studentai iš vieno bendro konteinerio perrašomi į du kitus atskirus naudojant remove_copy_if bei copy_if algoritmus, tačiau vėliau bendras konteineris nėra ištrinamas (praktiškai tas pats kaip ir pirmoji strategija, tik dėl įdomumo, neefektyvu)

## Rezultatų lentelė (spartos analizė)

|Studentų kiekis =    10000000       |Vektorius |Deque  |List
|-----------------------------|----------|------------|------------|
|Pirmoji strategija |8.7|5.8| 6.9|
|Antroji strategija |4.4|4.1| 4.2|
|Trečioji strategija |8.86|7.85| 8.6|
|Ketvirtoji strategija |7.33|5| 5.9|

|Studentų kiekis =    1000000      |Vektorius |Deque  |List
|-----------------------------|----------|------------|------------|
|Pirmoji strategija |0.76|0.57| 0.68|
|Antroji strategija |  0.43|0.45| 0.43|
|Trečioji strategija |0.76|0.74| 0.97|
|Ketvirtoji strategija |0.64|0.51| 0.6|

## Išvados:
Antroji strategija man buvo efektyviausia, konteinerių išskirstymo greitis akivaizdžiai trumpesnis nei visų kitų.
 
# Kiti release 

# <br />[v0.5](https://github.com/Definitelynotaspruce/2-oji_uzduotis/releases/tag/v0.5) 

- Trys atskiros programos Vector, List bei Deque konteinerių veikimo spartos analizei
- Matuojamas studentų nuskaitymas bei padalinimas

## v0.5 spartos analizė
Naudojamo kompiuterio parametrai: Intel core i5 7th gen, 8gb RAM, SSD.
### Vector

|Funkcija                     |n = 1000    |n = 10000     |n = 100000    |n = 1000000   |n = 10000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Nuskaitymas |0 s|0.04 s|0.4 s|3.7 s|37 s|
|Padalinimas|0 s|0.01 s|0.31 s|5 s|55 s|

### List

|Funkcija                     |n = 1000    |n = 10000     |n = 100000    |n = 1000000   |n = 10000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Nuskaitymas|0 s|0.04 s|0.5 s|4.5 s|42 s|
|Padalinimas|0 s|0.02s|0.23 s|2.3 s|30 s|

### Deque

|Funkcija                     |n = 1000    |n = 10000     |n = 100000    |n = 1000000   |n = 10000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Nuskaitymas|0 s|0.04 s|0.5s|3.7 s|38 s|
|Padalinimas|0 s|0.02|0.1 s|4 s|43 s|

### Išvados
Efektyviausiai veikė list konteineris, greičio skirtumas akivaizdžiai matomas. Vector konteineris buvo lėčiausias.

# <br />[v0.4](https://github.com/Definitelynotaspruce/2-oji_uzduotis/releases/tag/v0.4) 

- Penkių studentų .txt failų generavimas bei nuskaitymas naudojant vektorius
- Studentai rūšiuojami į du atskirus vektorius pagal metinį vidurkį (mažiau už 5 bei daugiau už 5)
- Programa veikimo metu atlieka spartos analizę (matuojami nuskaitymo, splitinimo, skirstymo greičiai) 

# <br />[v0.3](https://github.com/Definitelynotaspruce/2-oji_uzduotis/releases/tag/v0.3) 

- Programos failai suskirstyti į headerius
- Pridėtas Makefile

# <br />[v0.2](https://github.com/Definitelynotaspruce/2-oji_uzduotis/releases/tag/v0.2)

- Programa gali nuskaityti duomenis iš duoto failo
- Rezultatai vedami į .txt failą "pažymiai.txt"
- Išvedimas lygiuojamas

# <br />[v0.1](https://github.com/Definitelynotaspruce/2-oji_uzduotis/releases/tag/v0.1) 

- Apskaiciuojamas studentu namu darbu pazymiu vidurkis/mediana
- Rezultatai pateikiami lentelės forma




