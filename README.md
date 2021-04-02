# Systemu Czasu Rzeczywistego - Projekt - Symulacja systemu zbierajacego temperatury ze stacji meteorologicznych.
Projekt wykonany w ramach przedmiotu SCZR (Systemu Czasu Rzeczywistego) w semestrze 2020Z (5 semestr), na kierunku Informatyka, specjalizacji Inżynieria Systemów Informacyjnych (ISI) na Wydziale Elektroniki i Technik Informacyjnych (EiTI) Politechniki Warszawskiej.

**Prowadzący projekt**: mgr inż Michał Kruszewski  
**Ocena**: 37/40  

### Autorzy
Krystian Kujawski, nr 291129  
krystian.kujawski.stud@pw.edu.pl  
Lukasz Pokorzyński, nr 300251  
lukasz.pokorzynski.stud@pw.edu.pl  
Adam Steciuk, nr 300263  
adam.steciuk.stud@pw.edu.pl  

### Treść zadania
Zadanie polega na zbudowaniu działającego systemu czasu rzeczywistego korzystającego z rozwiązań komunikacji międzyprocesowej zaimplementowanych w systemach Unix.

_[Dokumentacja końcowa](https://github.com/steciuk/SCZR/blob/master/SCZR%20-%20sprawozdanie.pdf) prezentuje dokładne działanie zbudowanego systemu i wyniki przeprowadzonych testów._

### Wymagania
* ``dystrybucja systemu Linux``
* ``Allegro5``

### Instrukcja
* Do uruchomienia programu najlepiej użyć środowisko IDE CLion i na dowolnej dystrybucji systemu Unix/Linux zbudować podany w repozytorium projekt.
* Po włączeniu systemu wyświetli się zapytanie o tryb szeregowania (1 FIFO, 2 RR, 3 Domyślny)
  * Tryby FIFO i RR dodatkowo zapytają o możliwość wywłaszczenia rdzenia procesora na rzecz procesu wizualizującego.
* Następnie użytkownik ma przekazać wymiary mapy X i Y.
* Ostatnią czynnością jest przekazanie liczby symulowanych stacji (min 1, maks 200).

Jeżeli wszystkie czynności zostały wykonane poprawnie, to wyświetli się okno symulujące przebieg temperatury między wygenerowanymi stacjami.
