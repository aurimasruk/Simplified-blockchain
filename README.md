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

Block 6

Hash: e8fdfb218665b59119981ff798fee6c4bacbbc2a0e08fee66551100f67eccbb3
Timestamp: 
Version: v0.1
Merkel Root Hash: 2c1e3d55b575d7d57ff99993bb3008880d555d222c4688800eebb885b5711135
Number of transactions: 100
Nonce: 13199
Difficulty: 2
---------------------------------

Block 7

Hash: 1afc1ada1abad6d56ee7744d0bebb33052722afcc5acd8800ffcc996d6700de0
Timestamp: 
Version: v0.1
Merkel Root Hash: 99a9100d567077e66eee78808011192b0d5556d6fe6eebb33bbaa22aab322aa2
Number of transactions: 100
Nonce: 30874
Difficulty: 2
---------------------------------

Block 8

Hash: 88a6ed1199c6aa199111aaa2a6888083bb333483b7f7bbb33ffeeaa6ab3ffbb3
Timestamp: 
Version: v0.1
Merkel Root Hash: a4725f2bb57f2cc46ee8811be9c77ff8945008b44ef13ee66ee9944ff9b55e02
Number of transactions: 100
Nonce: 22514
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
