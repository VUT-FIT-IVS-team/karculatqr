# Karculatqr
## Návod
### Instalace 
Rozbalte archiv. Spusťte soubor `install.sh`. Ten bude vyžadovat sudo heslo.
### Ovládání
Aplikace obsahuje tlačítka označené číslicemi a matematickými operacemi (popsáno níže). Stlačením číslice se zadá do kalkulačky a při stisknutí tlačítka matematické operace se zadané číslo uloží do paměti kalkulačky a započne se zadávání dalšího čísla. Při stisknutí tlačítka `=` proběhne operace mezi uloženým a zadaným číslem a výsledek bude uložen a zobrazen na displeji kalkulačky. Při stisknutí jiné operace proběhne výpočet stejně, jako při stisknutí tlačítka `=` kdy je možné rovnou zadat další číslo pro právě stisknutou operaci. 

Některé operace jsou unární – jejich výsledek nepřepisuje uložené číslo.
#### Sčítaní
Sečte předešlé a aktuální číslo.
#### Odčítání
Odečte od předešlého čísla aktuální.
#### Násobení
Vynásobí předešlé a aktuální číslo.
#### Dělení
Vydělí od předešlého čísla aktuální. 

Nelze dělit nulou.
#### Faktoriál (unární)
Z aktuálně zadaného čísla vypočte faktoriál a ponechá předchozí zadané či vypočítané číslo v paměti kalkulačky.
#### Mocnina
Předešlé číslo se stane bázou mocniny a aktuální číslo se stane exponentem mocniny.
#### Odmocnina
Před zmáčknutím operace odmocniny je třeba zadat číslo, které je žádáno odmocnit a po zmáčknutí operace odmocnina je třeba zadat číslo, které je n-tá odmocnina
#### Přepnutí do radiánů/stupňů
Po stistknutí tlačítka přepne režim kalkulačky do radiánů nebo stupňů. Text tlačítka reprezentuje aktuální režim.
#### Sinus (unární)
Vypočítá sinus zadaného čísla a ponechá předchozí zadané či vypočítané číslo v paměti kalkulačky.
#### Cosinus (unární)
Vypočítá cosinus zadaného čísla a ponechá předchozí zadané či vypočítané číslo v paměti kalkulačky.
#### Tangens (unární)
Vypočítá tangens zadaného čísla a ponechá předchozí zadané či vypočítané číslo v paměti kalkulačky.

Nelze vypočítat tangens z ±90 stupňů a odpovídajích opakování těchto hodnot (270, -270, ...)
### Odinstalace
Stačí spustit skript `uninstall_karculatqr`. Nachází se v adresáři `/usr/bin/`, který by měl být v `PATH`. Podobně jako instalátor, také vyžaduje zadání sudo hesla.
