# Simple command writer
### Wymagane:
* Visual studio 2015 
* Qt w wersji 5.6.3 dla microsoft visual studio 2015
* Dodać zmienną środowiskową 'QTDIR'. O wartości ze ścierzką do katalogu Qt z odpowiednią wersją, np.'C:\Qt\5.6.3\msvc2015'
### Aktualnie działające komendy:
* Zamykanie aplikacji. Zamyka wszystkie aplikacje o podanej nazwie
```
Zamknij [nazwa_aplikacji]
```
* Uruchamianie aplikacji
```
Uruchom [nazwa_aplikacji]
```
* Wykonanie wybranego polecenia (np. Uruchom, zamknij) po określonym czasie
```
Uruchom [nazwa_aplikacji] za 5 sekund
Zamknij [nazwa_aplikacji] za 10 min
```
```
Legenda:
[nazwa_aplikacji] - musi być uwcześniej zapisana w pliku tekstowym "slowa_zmienne.txt"
```
