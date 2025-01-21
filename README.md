# Projekt-PWI-Z9

Nasz projekt to komputerowa symulacja gry w statki w języku c.

Instalacja biblioteki RayLib (niezbędne, aby uruchomić grę):

Linux (korzystając z terminala):

Warto się upewnić, że system jest aktualny, wpisując:

sudo apt update

Jeżeli okaże się, że nie, można go zaktualizować poleceniem:

sudo apt upgrade

RayLib wymaga zainstalowania pewnych zależności:

sudo apt install build-essential libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev

Osobno też instalujemy narzędzie cmake:

sudo apt install cmake

Po tych czynnościach możemy przystąpić do instalacji biblioteki. Najpiew klonujemy repozytorium RayLib na github:

git clone https://github.com/raysan5/raylib.git

W katalogu, w którym wykonaliśmy to polecenie, pojawi się katalog raylib. Wtedy wchodzimy do tego katalogu:

cd raylib

W katalogu raylib tworzymy nowy katalog, w którym skompilujemy bibliotekę:

mkdir build

Następnie wchodzimy do tego katalogu:

cd build

Poleceniem cmake konfigurujemy bibliotekę (to znaczy generujemy makefile do skompilowania biblioteki)

cmake .. -DBUILD_SHARED_LIBS=ON

Z tym, że flaga -DBUILD_SHARED_LIBS=ON nie będzie potrzebna do uruchomienia naszej gry, więc jest opcjonalna.

A następnie kompilujemy:

make

Dopiero po kompilacji możemy zainstalować bibliotekę w systemie, czyli przenieść pliki nagłówkowe i biblioteczne do katalogu /usr/local/lib/:

sudo make install

Sprawdzamy, czy RayLib został prawidłowo zainstalowany

ls /usr/local/include

Naszym oczom powinny ukazać się nazwy trzech plików nagłówkowych:

raylib.h  raymath.h  rlgl.h

Można też skopiować poniższy program do edytora tekstu w linux i zapisać go jako plik z rozszerzeniem c, na przykład test.c

#include "raylib.h"

int main(void) {

    InitWindow(800, 600, "Raylib Example");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, Raylib!", 10, 10, 20, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

A następnie skompilować w tym samym katalogu gdzie został stworzony.

gcc test.c -lraylib -lm -lpthread -ldl -lX11

I uruchomić poleceniem ./a.out. Powinien się ukazać ekran z czerwonymi napisami Hello, Raylib na białoszarym tle.

Alternatywnie, można też zainstalować RayLiba bezpośrednio z pakietów na poniższych rodzinach dystrybucji linuxa:

Ubuntu (20.04+) - sudo apt install libraylib-dev
Debian (10+) - sudo apt install libraylib-dev
Fedora (32+) - sudo dnf install raylib-devel
Arch Linux - sudo dnf install raylib-devel
OpenSUSE - sudo zypper install raylib-devel
Gentoo - emerge dev-libs/raylib

W nawiasach podano wersję dystrybucji, od której można to zrobić.

Oczywiście podstawowe funkcje języka c (kompilator gcc, wraz z flagami, pliki nagłówkowe) są w build essential.

Instalacja git:

Tu pomoże poniższa komenda:

sudo apt install git

Klonowanie repozytorium projektu i jego kompilacja:

git clone https://github.com/Famde14/Projekt-PWI-Z9/

Po tym poleceniu w katalogu, w którym wpisaliśmy tę komendę, pojawi się folder Projekt-PWI-Z9. Wchodzimy do niego poleceniem:

cd Projekt-PWI-Z9

Grę kompilujemy poleceniem:

gcc functions.c glowny.c -lraylib -lm -lpthread -ldl -lX11

Następnie ją uruchamiamy (zaleca się przed tym przeczytać ten plik do końca):

./a.out

Stworzony został też plik bash zawierający drugą od góry komendę (nieco zmienioną, dzięki czemu plik wykonywalny nazywa się statki, a nie a.out). Wtedy grę można
skompilować i uruchomić prościej (ale tylko na linux):

sh build.bash

I uruchomić poleceniem (nie zmienia to dalej faktu, że ten plik warto przeczytać do końca):

./statki

Opis gry:

Po uruchomieniu w menu mamy dwa tryby gry do wyboru: singleplayer (Jeden gracz) i multiplayer (Dwóch graczy). Singleplayer umożliwia zmierzenie się z komputerem,
a multiplayer to rozgrywka między dwoma graczami.

Po wybraniu pierwszej z opcji włącza się tryb ustawiania statków. Do dyspozycji mamy 4 jednomasztowce, 3 dwumasztowce, 2 trzymasztowce, 1 czteromasztowiec
(gdzie n-masztowiec oznacza okręt, który zajmuje n pól). Przeciągamy je na planszę, klikając lewy przycisk myszy i go przytrzymując. Umieszczane
statki nie mogą zajmować sąsiednich kafelków, ani stykać się rogami. Dodatkowo wciskając klawisz E lub Q, możemy zmienić orientację statku
z poziomej na pionową (te dwa klawisze różnią się jednak kierunkiem obrotu). Klikając "Zacznij Bitwę", rozpoczynamy
właściwą część gry. Naciśnięcie "Ustaw Losowo" da ten sam efekt, tyle że statki zostaną losowo rozłożone na planszy.
Strzały w kolejnych turach oddają gracz i bot (tutaj tura oznacza ciąg strzałów zakończony strzałem niecelnym). Aby oddać strzał, klikamy 
dowolne pole na planszy przeciwnika, to zabarwi się na szaro, gdy okaże się, że nie ma tam statku, pojawi się na nim znak X, jeśli został trafiony lub
teksturę zniszczonego statku, jeśli zostały trafione wszystkie pola zajmowane przez statek. Zdarzenia te są ponadto sygnalizowane odpowiednimi dźwiękami.

Gra kończy się w momencie zestrzelenia wszystkich statków bota przez gracza (wygrana) lub vice versa (przegrana). Naciśnięcie "Zagraj Ponownie" powoduje ponowne
włączenie trybu ustawiania statków.

Tryb multiplayer prezentuje się podobnie, tyle że ustawianie statków i strzelanie odbywają się osobno dla pierwszego i drugiego gracza. Tury są oddzielone
osobnym ekranem, umożliwiającym sprawiedliwą rywalizację.

Kliknięcie klawisza Escape w trakcie gry powoduje pauzę, która daje opcję powrotu do menu, do gry oraz regulacji dźwięku.

Ta ostatnia jest również osiągalna w menu poprzez kliknięcie ikony nuty ósemki w prawym dolnym rogu ekranu. Dźwięk regulujemy, przesuwając suwak.

OSTRZEŻENIE O PROBLEMACH W ZARZĄDZANIU PAMIĘCIĄ!

Niestety w trakcie projektu pojawiły się trudne do zidentyfikowania problemy z zarządzaniem pamięcią, jak nie zwalnianie zaalokowaniej pamięci, jak i przeciwnie,
zwalnianie jej wielokrotnie prowadząc do błędu double free. Ten ostatni występuje przy wychodzeniu z gry. System linux powinien zatrzymać program w takiej sytuacji,
więc nie powinno to wyrządzić wiele szkód, dla systemu operacyjnego, ale włączenie gry odbywa się na odpowiedzialność użytkownika.

Przy tworzeniu wykorzystano następujące zasoby, niebędące autorstwa twórców projektu:

bibliotekę do gier RayLib: https://www.raylib.com/ (powyżej odnośnik do repozytorium)
otwarty program do edycji muzyki MuseScore: https://musescore.org/pl
wskazówki czatbota chatGPT: https://chatgpt.com/
dostępne na otwartej licencji czcionki ze strony https://www.fontspace.com/
internetowe narzędzie do konwersji typów plików dźwiękowych (w tym przypadku z mp3 na ogg) convertio: https://convertio.co/pl/audio-converter/
internetowe narzędzie do generowania dźwięków ośmiobitowych: https://sfxr.me/

Muzyka została skomponowana przez część twórców projektu, a dźwięk został wygenerowany dzięki programowi MuseScore, podobnie tekstury, też zostały przygotowane przez
część twórców.
