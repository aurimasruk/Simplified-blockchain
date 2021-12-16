# Simplified blockchain
Supaprastintos blokų grandinės (blockchain) kūrimas. Repositorija skirta Blockchain Technology pratyboms.

## Apie supaprastintą blokų grandinę
Užduoties tikslas: Sukurti "centralizuotą" blokų grandinę (blockchain'ą) ir susimuliuoti blokų grandinės veikimą kuo natūralesnėmis sąlygomis.
Programa atitinka keliamus reikalavimus.

## Programos veikimas
[Atsidarius programą](#programos-įdiegimas-ir-naudojimasis):
1. Programa sugeneruoja 1'000 tinklo vartotojų, 10'000 naujų transakcijų pool'ą.
2. Programa sukuria 5 potencialius blokus sudarytus iš ~100 atsitiktinai parinktų transakcijų.
3. Atsitiktinai pasirinkus vieną iš penkių blokų-kandidatų su juo atliekamas kasimo procesas.

### Išvedama informacija
```
.
..
...

Block 6: 

Hash: 0063ba2b4497cc3bb334ddd5dd344c412b3445a7fc4c4dd555544444cd63333b
Timestamp: Wed Nov 23 19:59:20 2021
Version: v0.2
Merkel Root Hash: b6dc3e4e4f20617f2aa55ffa0e433bb576866e5fface1ff77554433283611be0
Number of transactions: 100
Nonce: 27277
Difficulty: 2


Block 6 transactions: 
9af70b129230014cc443c55d6498801a34dccdd67f80677ffdd88664ab2aa880  -->  97b6c81af89586a22aa7099178c9912bc5b889c5617f81199aa667781272233b
1e2e32a5923f307ff773c55d22622ab4727334812e3b3ee666655555de2eeee6  -->  3ee66196725e612ad5500dd800800885a2777ffcc7ce1119922aa22ab6944146
1156e7835efb445dd55f81191ae8801ad80aab4def7f0bb33cc55ee789bcc55d  -->  99e7ff50701eff7ff776f88086baa23cfa21123cd6e6c77ffddddbb9f0700ee6
98c90892923f433bb332b44c3c0ff7812b2112701e5de77ff880099234b88119  -->  104182913cd9edf77ff92bb3a9d77f09918223812f6e5dd5544eeddc3463322a
97b7d9ca1ab7b9d55ddc5ee6c7baa23c206556a3406e1ff7722ee99478fbb66e  -->  1156e793923f88911997099193755de793b99a3cde6e0aa22cc55ff9bc233dd5
1f3284d8a34075911993c55d34822ab4728223a34391a55ddeeaabbc56877880  -->  1e2e3efae78485800884d66e3c0cc45e1c1dde2bc8d56119922dd66f01511aa2
...
..
.
---------------------------------

Block 7: 

Hash: 0072a4badd0f224cc44f888087e99194ba2dde1c4f7f655ddcc66554bcfaa991
Timestamp: Wed Nov 23 19:59:20 2021
Version: v0.2
Merkel Root Hash: 1ab45e712bc5e78019922cc5ef8119935e0119a44df1233bb44dd66f09a33de0
Number of transactions: 100
Nonce: 23587
Difficulty: 2

Block 7 transactions:
9af81293c56345e66eef811921677f09b5eff01ab4d5c66eeddeeddc34d6655d  -->  1e2d2d335efbebe66ee81aa275933bc5dd2ccd09a5a288800ee99775bce9977f
116e6e43b452222aa222b44c42777f090f7778812a2a0ff7755ddbb9f0800ee6  -->  99dd5e4f2bc80019911c5ee6ec0bb34d0b3eef701191722aa8811ffd3477755d
1043aaabd673a919911b4dd5c4822ab4de5ff070107ff0088000088001322aa2  -->  98cb2186923f65c44cc7099187b66ef8ec3eef6f0f6e533bbaa99887ef211008
1f317f666f0c200880081aa287b33bc5dd3bbc2bca08fff7766eeddc34422119  -->  96a6bc20701d1e7ff776f88053766ef8ec10015efb08ecc44223311f56d9977f
97ba014cf895ca3bb33e7008e9d8801aa28334b454a25dd550011cc7abedd880  -->  3ee66196725e612ad5500dd800800885a2777ffcc7ce1119922aa22ab6944146
3e3050858361947f2aa5522d55daa22f41666e300b02555dd885522f2d0bb8bd  -->  99db3b403cd9fff77ffa3cc4cd1cc45e2e6112812080955ddee667781253344c
...
..
.
```

## Išvados
Nors pagrindinį programos funkcionalumą pavyko įgyvendinti, tačiau proceso, kuriame bloko kasimas vyksta fiksuotu laiku, nepavyko įgyvendinti.


## Programos įdiegimas ir naudojimasis 
* Atsisiųskite naujausią programos versiją iš [Releases](https://github.com/aurimasruk/Simplified-blockchain/releases) ir ją išarchyvuokite
* Komandinėje eilutėje įveskite `g++ functions.cpp includes/hash.cpp main.cpp -o2 -o main` ir `./main`.
* Pradėjus veikti programai, įveskite reikalaujamus duomenis ir sekite nurodymus.
