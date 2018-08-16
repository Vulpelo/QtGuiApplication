# Simple command writer
### Wymagane:
* Visual studio 2015 
* Qt w wersji 5.6.3 dla microsoft visual studio 2015
* Dodać zmienną środowiskową 'QTDIR'. O wartości ze ścieżką do katalogu Qt z odpowiednią wersją, np.'C:\Qt\5.6.3\msvc2015'
### Aktualnie działające komendy:
* Zamykanie aplikacji. Zamyka wszystkie aplikacje o podanej nazwie
```
Zamknij [nazwa_aplikacji]
```
* Uruchamianie aplikacji
```
Uruchom [nazwa_aplikacji]
```
* Wyszukiwanie
  Przeszukuje cały dysk C:
```
Znajdz pliki o nazwie [nazwa_wyszukiwania]
Znajdz pliki modyfikowane przed 30.01.2018
Znajdz pliki o nazwie "*plik*" modyfikowane po 25.03.2017
```
* Wykonanie wybranego polecenia (np. Uruchom, zamknij) po określonym czasie
```
Uruchom [nazwa_aplikacji] za 5 sekund
Zamknij [nazwa_aplikacji] za 10 min
```

```
Legenda:
[nazwa_aplikacji] - musi być uwcześniej zapisana w pliku tekstowym "slowa_zmienne.txt"
[nazwa_wyszukiwania] - podajesz nazwę pliku. W nazwie można użyć znaków specjalnych: * - dowolne znaki; ? - jakiś jeden dowolny znak. Przykłady: "*.txt" - wszystkie pliki które kończą się nazwą na .txt; "na??a.txt" - wszystkie pliki o podanej nazwie podstawiając za pytajniki dowolne znaki 
```
