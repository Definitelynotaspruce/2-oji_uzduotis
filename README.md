# 2-oji_uzduotis

ANTROJI OOP UŽDUOTIS - programa, apskaičiuojanti studentų metinį vidurkį

## VEIKIMO PRINCIPAS

1. Vartotojas pasirenka ar generuos 5 failus ar tes normalų programos darbą 
  *vartotojas veda 't' arba 'n'
2. Vartotojas pasirenka ar duomenis ves pats ar skaitys iš failo
   * vartotojas veda 'i' arba 'f' raidę
3. Pasirenkama, ar bus skaičiuojama namų darbų mediana ar vidurkis 
   * vartotojas veda 'v' arba 'm' raidę
Jeigu vartotojas paririnkęs jog duomenis ves ranka:
4. Vartotojas įveda, kiek studentų suves (skaičius)
5. Pasirenkama, ar pažymiai bus vedami ranka ar generuojami atsitiktinai 
   * vartotojas veda 'r' arba 'g' raidę
6. Vyksta vardų bei pavardžių įvedimas

7. Vyksta skaičiavimas pagal formulę:
    * Galutinis rezultatas = (vidurkis arba mediana) * 0.4 + (egzamino balas) * 0.6;
    
## Kaip paleisti programą?

1. Atsisiųsti vėliausią release
2. Tureti GNU compileri
2. Atsidaryti terminalą toje atsisiųsto failo vietoje ir įrašyti komandą "make"
3. Rašyti ./main arba main.exe (jei Windows)

# v0.5 analizė

### Vector

|Funkcija                     |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Nuskaitymas |0 s|0.04 s|0.4 s|3.7 s|37 s|
|Padalinimas|0 s|0.01 s|0.31 s|5 s|55 s|

### List

|Funkcija                     |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Nuskaitymas|0 s|0.04 s|0.5 s|4.5 s|42 s|
|Padalinimas|0 s|0.02s|0.23 s|2.3 s|30 s|

### Deque

|Funkcija                     |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Nuskaitymas|0 s|0.04 s|0.5s|3.7 s|38 s|
|Padalinimas|0 s|0.02|0.1 s|4 s|43 s|


    
## Releases 
<br />[v0.1](https://github.com/Definitelynotaspruce/2-oji_uzduotis/releases/tag/v0.1) 
Versija numeris v0.1
* Si versija apskaiciuoja studentu namu darbu pazymiu vidurki/mediana bei pateikia rezultatus lenteles forma

<br />[v0.2](https://github.com/Definitelynotaspruce/2-oji_uzduotis/releases/tag/v0.2) 
Versija numeris v0.2
* Galima pasirinkti ar skaityti duomenis iš txt failo ar vesti ranka. Rezultatai vedami į txt failą "pazymiai.txt"

<br />[v0.3](https://github.com/Definitelynotaspruce/2-oji_uzduotis/releases/tag/v0.3) 
Versija numeris v0.3
* Funkcijos išskaidytos per kelis failus, su headeriais. Taip pat galima pasinaudoti Makefile."

<br />[v0.4](https://github.com/Definitelynotaspruce/2-oji_uzduotis/releases/tag/v0.4) 
Versija numeris v0.4
* Pridetas random failu generavimas ir ju testavimas."

<br />[v0.5](https://github.com/Definitelynotaspruce/2-oji_uzduotis/releases/tag/v0.5) 
Versija numeris v0.5
* Trys skirtingos programos versijos naudojant vektorius, deque ir listus"




