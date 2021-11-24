# Simplified blockchain
Supaprastintos blokų grandinės (blockchain) kūrimas. Repositorija skirta Blockchain Technology pratyboms.

## Apie supaprastintą blokų grandinę
Užduoties tikslas: Sukurti "centralizuotą" blokų grandinę (blockchain'ą) ir susimuliuoti blokų grandinės veikimą kuo natūralesnėmis sąlygomis.
Programa atitinka keliamus reikalavimus.

## Programos veikimas
[Atsidarius programą](#programos-įdiegimas-ir-naudojimasis):
1. Programa sugeneruoja 1000 tinklo vartotojų, kurie turi atitinkamus atributus.
2. Programa sugeneruoja 10000 naujų transakcijų pool'ą, kurios turi atitinkamus atributus.
3. Iš transakcijų pool'o atsitiktinai pasirenkama 100 transakcijų, kurias įdedame į naują bloką.
4. Realizuojamas naujų blokų kasimo (angl. mining) Proof-of-Work (PoW) tipo procesas, kurio tikslas yra surasti naujam blokui hash'ą, tenkinantį `Difficulty Targer` reikalavimą.
5. Suradus tokį naujo bloko hash'ą:
    * Į naują bloką priskirtas transakcijas ištrinti iš transakcijų pool'o;
    * "Įvykdyti" transakcijas, t.y., atnaujinti tinklo vartotojų balansus;
    * naują bloką pridėti prie blockchain grandinės.
6. Programa kartoja 3-5 žingsnius tol, kol yra laisvų transakcijų.

### Išvedama informacija
```
.
..
...

Block 6: 

Hash: 0063ba2b4497cc3bb334ddd5dd344c412b3445a7fc4c4dd555544444cd63333b
Timestamp: Wed Nov 23 19:59:20 2021
Version: v0.1
Merkel Root Hash: b6dc3e4e4f20617f2aa55ffa0e433bb576866e5fface1ff77554433283611be0
Number of transactions: 100
Nonce: 27277
Difficulty: 2
---------------------------------

Block 7: 

Hash: 0072a4badd0f224cc44f888087e99194ba2dde1c4f7f655ddcc66554bcfaa991
Timestamp: Wed Nov 23 19:59:20 2021
Version: v0.1
Merkel Root Hash: 1ab45e712bc5e78019922cc5ef8119935e0119a44df1233bb44dd66f09a33de0
Number of transactions: 100
Nonce: 23587
Difficulty: 2
---------------------------------

Block 8: 

Hash: 002a2b1d66c6667ff77811191f122a2040899aa80808eaa220099775bc5ddbb3
Timestamp: Wed Nov 23 19:59:20 2021
Version: v0.1
Merkel Root Hash: c812b77684822e08c4400ffbb3344ccb23a22a322e57b33bb5566778a6a6659b
Number of transactions: 100
Nonce: 28838
Difficulty: 2
---------------------------------

...
..
.
```

## Programos įdiegimas ir naudojimasis 
* Atsisiųskite naujausią programos versiją iš [Releases](https://github.com/aurimasruk/Simplified-blockchain/releases) ir ją išarchyvuokite
* Komandinėje eilutėje įveskite `g++ functions.cpp includes/hash.cpp main.cpp -o2 -o main` ir `./main`.
* Pradėjus veikti programai, įveskite reikalaujamus duomenis ir sekite nurodymus.
