**Polski** · [English](README.en.md)

---

# Matura 2023 i 2024 (maj) - informatyka, poziom rozszerzony, zadanie 3. "Liczba Pi" i zadanie 3. "Nieparzysty skrót" - porównanie Pythona i C++

> ### 🎬 Wideo z rozwiązaniem
> Pełne omówienie obu zadań krok po kroku znajdziesz na moim kanale YouTube:
> **[Link do filmu na YouTube](https://youtu.be/Y1a8Y5cEOvs)**
>
> Na filmie rozwiązuję wybrane podpunkty dwóch zadań maturalnych równolegle w Pythonie i w C++. Na każdym etapie porównuję kod w obu językach i podpowiadam, który z nich wybrać na maturę z informatyki.

---

## Spis treści

- [Opis](#opis)
- [Wymagania](#wymagania)
- [Uruchomienie](#uruchomienie)
- [Struktura projektu](#struktura-projektu)
- [Treść zadań i sposób rozwiązania](#treść-zadań-i-sposób-rozwiązania)
- [Zgodność z ograniczeniami z arkusza](#zgodność-z-ograniczeniami-z-arkusza)
- [Wyniki](#wyniki)
- [Porównanie Pythona i C++](#porównanie-pythona-i-c)
- [Kiedy wybrać Pythona, a kiedy C++](#kiedy-wybrać-pythona-a-kiedy-c)
- [Uwagi implementacyjne](#uwagi-implementacyjne)

## Opis

Repozytorium zawiera rozwiązania wybranych podpunktów dwóch zadań z arkuszy maturalnych CKE z informatyki na poziomie rozszerzonym. Każde rozwiązanie jest napisane dwa razy, w Pythonie i w C++. Dzięki temu możesz porównać oba języki na tych samych zadaniach i wybrać ten, który lepiej sprawdzi się u Ciebie na maturze.

Omawiane zadania:

- Zadanie 3. "Liczba Pi" z terminu głównego maj 2023, podpunkty 3.1 i 3.2. Zadanie dotyczy fragmentów dwucyfrowych w rozwinięciu dziesiętnym liczby Pi zapisanym w pliku tekstowym. Rozwiązanie obejmuje wczytanie danych z pliku, zliczanie fragmentów oraz wyszukanie fragmentu najrzadszego i najczęstszego.
- Zadanie 3. "Nieparzysty skrót" z terminu głównego maj 2024, podpunkt 3.1. Trzeba napisać funkcję, która usuwa cyfry parzyste z zapisu liczby całkowitej. Zadanie ma ograniczenia do operacji na liczbach całkowitych, typowe dla arkuszy maturalnych.

Porównanie dotyczy wyłącznie matury z informatyki. To nie jest ocena, który język programowania jest lepszy w ogóle.

## Wymagania

- Python 3.9 lub nowszy. Sygnatury funkcji używają adnotacji typów `list[int]` i `tuple[Wystapienia, Wystapienia]`, które w starszych wersjach nie działają.
- Kompilator C++ obsługujący standard C++17. Plik `zad-1/app-1.cpp` korzysta z dekompozycji strukturalnej, np. `auto [najrzadszy, najczestszy] = zadanie_3_2(cyfry);`. Plik `zad-2/app-2.cpp` skompiluje się również w C++11.
- Brak zewnętrznych zależności. W Pythonie wykorzystano wyłącznie bibliotekę standardową, w tym moduł `collections`.

## Uruchomienie

Sklonuj repozytorium i przejdź do jego katalogu:

```bash
git clone https://github.com/kmprograms/matura-porownanie-jezykow-python-cpp
cd matura-porownanie-jezykow-python-cpp
```

Każdy z poniższych bloków poleceń zakłada, że startujesz z katalogu głównego repozytorium.

### Zadanie "Liczba Pi"

Programy otwierają pliki `pi.txt` i `pi_przyklad.txt` po samej nazwie, dlatego uruchamiasz je z katalogu `zad-1`.

Wersja w Pythonie:

```bash
cd zad-1
python app-1.py
```

Wersja w C++:

```bash
cd zad-1
g++ -std=c++17 -O2 -o app-1 app-1.cpp
./app-1
```

Program wypisuje odpowiedzi do podpunktów 3.1 i 3.2, za każdym razem najpierw dla danych przykładowych, a potem dla właściwych.

### Zadanie "Nieparzysty skrót"

Wersja w Pythonie:

```bash
cd zad-2
python app-2.py
```

Wersja w C++:

```bash
cd zad-2
g++ -std=c++17 -O2 -o app-2 app-2.cpp
./app-2
```

Program wypisuje dwie liczby, po jednej w wierszu, czyli wyniki dla przykładów z treści zadania. Pełne wyjście obu programów znajdziesz w sekcji [Wyniki](#wyniki).

## Struktura projektu

| Plik | Opis |
| --- | --- |
| `PODSUMOWANIE.txt` | Tabela z podsumowaniem, kiedy na maturze wybrać Pythona, a kiedy C++ |
| `zad-1/app-1.py` | Zadanie "Liczba Pi", podpunkty 3.1 i 3.2 w języku Python |
| `zad-1/app-1.cpp` | Zadanie "Liczba Pi", podpunkty 3.1 i 3.2 w języku C++ |
| `zad-1/pi.txt` | Dane do zadania, 10 000 cyfr rozwinięcia dziesiętnego liczby Pi po przecinku, po jednej cyfrze w wierszu |
| `zad-1/pi_przyklad.txt` | 100 pierwszych wierszy pliku `pi.txt`, dane do sprawdzenia odpowiedzi podanych w treści zadania |
| `zad-2/app-2.py` | Zadanie "Nieparzysty skrót", podpunkt 3.1 w języku Python |
| `zad-2/app-2.cpp` | Zadanie "Nieparzysty skrót", podpunkt 3.1 w języku C++ |

## Treść zadań i sposób rozwiązania

### Zadanie 3. "Liczba Pi" (maj 2023)

Pewien matematyk zapisał rozwinięcie dziesiętne liczby Pi z dokładnością do 10 000 cyfr po przecinku. Wszystkie cyfry po przecinku znajdują się w pliku `pi.txt`, który ma 10 000 wierszy, po jednej cyfrze w każdym. Plik `pi_przyklad.txt` zawiera 100 pierwszych wierszy pliku `pi.txt`, a odpowiedzi dla tych danych podano pod treścią podpunktów. Odpowiedzi należy zapisać w pliku `wyniki3.txt`, każdą poprzedzoną numerem zadania.

W repozytorium rozwiązane są podpunkty 3.1 i 3.2.

#### Wczytywanie danych

Dane trafiają do jednego napisu, w którym cyfry tworzą nieprzerwany ciąg. Taka postać jest dobrana pod podpunkty 3.1 i 3.2. Przy rozwiązywaniu całego zadania mogłoby się okazać, że do kolejnych podpunktów lepiej pasuje inna struktura danych.

Wersja w Pythonie:

```python
def wczytaj_cyfry(nazwa_pliku: str) -> str:
    with open(nazwa_pliku) as plik:
        return "".join(plik.read().split())
```

Funkcja `open` jest dostępna od razu, bez importów. `read()` wczytuje cały plik, `split()` dzieli go na cyfry i pomija znaki nowej linii, a `"".join(...)` skleja cyfry w jeden napis.

Wersja w C++:

```cpp
string wczytaj_cyfry(const string& nazwa_pliku) {
    ifstream plik(nazwa_pliku);
    string cyfry;
    char c;
    while (plik >> c) {
        cyfry += c;
    }
    return cyfry;
}
```

W C++ trzeba dołączyć nagłówki `<fstream>` i `<string>`, utworzyć obiekt `ifstream` i w pętli dopisywać kolejne znaki do napisu. Operator `>>` pomija białe znaki, więc znaki nowej linii nie trafiają do wyniku.

#### Zadanie 3.1

Fragmentem dwucyfrowym nazywamy dwie następujące po sobie cyfry w pliku `pi.txt`. Wszystkich fragmentów dwucyfrowych jest 9999, a ostatni rozpoczyna się w wierszu numer 9999. Należy znaleźć liczbę fragmentów dwucyfrowych, które są zapisami dziesiętnymi liczb większych od 90. Dla danych z pliku `pi_przyklad.txt` poprawna odpowiedź to 13.

Rozwiązanie zaczyna się od funkcji `fragmenty`, która zamienia ciąg cyfr na listę wszystkich fragmentów dwucyfrowych jako liczb całkowitych. Funkcja `zadanie_3_1` zlicza fragmenty większe od progu. Próg jest parametrem z wartością domyślną 90.

Wersja w Pythonie:

```python
def fragmenty(cyfry: str) -> list[int]:
    return [int(cyfry[i:i+2]) for i in range(len(cyfry) - 1)]
```

```python
def zadanie_3_1(cyfry: str, prog: int = 90) -> int:
    return sum(1 for wartosc in fragmenty(cyfry) if wartosc > prog)
```

`range(len(cyfry) - 1)` daje indeksy od 0 do przedostatniego. Wycinek `cyfry[i:i+2]` obejmuje znaki o indeksach `i` oraz `i + 1`, bo górna granica nie jest brana pod uwagę. Zliczanie wykonuje wbudowana funkcja `sum` z wyrażeniem generatorowym, które przepuszcza tylko wartości większe od progu.

Wersja w C++:

```cpp
vector<int> fragmenty(const string& cyfry) {
    vector<int> wynik;
    for (size_t i = 0; i + 1 < cyfry.size(); ++i) {
        wynik.push_back(stoi(cyfry.substr(i, 2)));
    }
    return wynik;
}
```

```cpp
int zadanie_3_1(const string& cyfry, int prog = 90) {
    int wynik = 0;
    for (int wartosc: fragmenty(cyfry)) {
        if (wartosc > prog) {
            ++wynik;
        }
    }
    return wynik;
}
```

Fragmenty trafiają do `vector<int>`. Kolejne pary cyfr wycina `substr(i, 2)`, a `stoi` zamienia je na liczbę. Warunek `i + 1 < cyfry.size()` przechodzi przez te same indeksy co `range(len(cyfry) - 1)` w Pythonie. Zliczanie to klasyczna pętla `for` z licznikiem.

Zamiast `vector` można użyć zwykłej tablicy, bo rozmiary danych są podane w treści. Mimo to `vector` warto znać na maturze, bo w wielu sytuacjach jest po prostu wygodniejszy od klasycznej tablicy.

#### Zadanie 3.2

Wszystkich możliwych różnych fragmentów dwucyfrowych jest dokładnie 100, od `00` do `99`. Na przykład fragment `27` występuje w pliku `pi.txt` dokładnie 101 razy. Należy znaleźć fragment dwucyfrowy o najmniejszej liczbie wystąpień w pliku `pi.txt` oraz fragment o największej liczbie wystąpień i podać je razem z liczbami wystąpień. Jeśli kilka fragmentów występuje tyle samo razy, należy wypisać ten o mniejszej wartości liczbowej.

Wersja w Pythonie:

```python
from collections import Counter, namedtuple

Wystapienia = namedtuple("Wystapienia", "fragment,liczba")
```

```python
def zadanie_3_2(cyfry: str) -> tuple[Wystapienia, Wystapienia]:
    licznik = Counter(fragmenty(cyfry))
    wszystkie = [Wystapienia(n, licznik[n]) for n in range(100)]
    najrzadszy = min(wszystkie, key=lambda w: (w.liczba, w.fragment))
    najczestszy = max(wszystkie, key=lambda w: (w.liczba, -w.fragment))
    return najrzadszy, najczestszy
```

To pierwszy moment, w którym w Pythonie trzeba cokolwiek zaimportować. `Counter` zlicza wszystkie fragmenty jednym wywołaniem. Następnie dla każdej liczby od 0 do 99 powstaje obiekt `Wystapienia`, czyli `namedtuple` z polami `fragment` i `liczba`. `Counter` zwraca 0 dla fragmentów, które nie wystąpiły ani razu, dlatego one też biorą udział w szukaniu minimum. Najrzadszy i najczęstszy fragment wyznaczają wbudowane funkcje `min` i `max` z parametrem `key`.

Przy remisie `min` i `max` zwracają pierwszy znaleziony element, a lista jest ułożona od fragmentu `00` do `99`. Wystarczyłby więc sam klucz `w.liczba`. Dla celów dydaktycznych drugie kryterium jest zapisane jawnie jako drugi element krotki. W `max` przed fragmentem stoi minus, bo przy remisie ma wygrać mniejsza wartość. Tak samo łatwo dopisuje się kolejne kryteria przy sortowaniu.

Wersja w C++:

```cpp
struct Wystapienia {
    int fragment;
    int liczba;
};
```

```cpp
pair<Wystapienia, Wystapienia> zadanie_3_2(const string& cyfry) {
    vector<int> licznik(100, 0);
    for (int wartosc: fragmenty(cyfry)) {
        ++licznik[wartosc];
    }

    Wystapienia najrzadszy = {0, licznik[0]};
    Wystapienia najczestszy = {0, licznik[0]};

    for (int i = 1; i < 100; ++i) {
        if (licznik[i] < najrzadszy.liczba) {
            najrzadszy = {i, licznik[i]};
        }
        if (licznik[i] > najczestszy.liczba) {
            najczestszy = {i, licznik[i]};
        }
    }
    return {najrzadszy, najczestszy};
}
```

Zamiast `namedtuple` jest struktura `Wystapienia`, a zamiast `Counter` wektor `licznik` o 100 elementach, w którym indeks odpowiada wartości fragmentu. Minimum i maksimum są wyszukiwane ręcznie w pętli. Fragmenty są przeglądane od najmniejszego, a porównania `<` i `>` są ostre, dlatego przy remisie zostaje fragment o mniejszej wartości. Do zwrócenia dwóch wyników służy `pair` z nagłówka `<utility>`.

Fragmenty mniejsze od 10 trzeba wypisać z zerem wiodącym, czyli `00` zamiast `0`. Odpowiada za to funkcja `pokaz_wystapienia`.

Wersja w Pythonie:

```python
def pokaz_wystapienia(w: Wystapienia) -> None:
    fragment = f'0{w.fragment}' if w.fragment < 10 else f"{w.fragment}"
    print(f"Fragment: {fragment}, Liczba: {w.liczba}")
```

Wersja w C++:

```cpp
void pokaz_wystapienia(const Wystapienia& w) {
    cout << setw(2) << setfill('0') << w.fragment << ", " << w.liczba << "\n";
}
```

W Pythonie zero wiodące dokleja wyrażenie warunkowe. W C++ `setw(2)` i `setfill('0')` z nagłówka `<iomanip>` sprawiają, że fragment zawsze zajmuje dwie pozycje.

Oba podpunkty przechodzą przez wszystkie fragmenty, więc złożoność czasowa to O(N), gdzie `N` to liczba cyfr. Lista fragmentów zajmuje O(N) pamięci.

### Zadanie 3. "Nieparzysty skrót" (maj 2024)

#### Zadanie 3.1

Nieparzystym skrótem dodatniej liczby całkowitej `n` nazywamy dodatnią liczbę całkowitą `m`, która powstaje przez usunięcie cyfr parzystych z zapisu dziesiętnego liczby `n`. Nieparzysty skrót nie istnieje, gdy zapis dziesiętny liczby składa się tylko z cyfr parzystych.

Przykłady z treści zadania:

- nieparzystym skrótem liczby 294762 jest 97
- nieparzystym skrótem liczby 39101 jest 3911
- nieparzysty skrót liczby 224 nie istnieje

Należy w pseudokodzie lub w wybranym języku programowania zapisać funkcję, która dla dodatniej liczby całkowitej `n`, dla której istnieje nieparzysty skrót, wyznaczy liczbę `m`, czyli nieparzysty skrót liczby `n`.

Specyfikacja z arkusza:

- Dane: `n` - dodatnia liczba całkowita, taka że istnieje dla niej nieparzysty skrót
- Wynik: `m` - nieparzysty skrót liczby `n`

Algorytm przechodzi przez cyfry liczby `n` od najmniej znaczącej. Zmienna `p` przechowuje wagę pozycji, na której w `m` stanie kolejna cyfra nieparzysta, czyli najpierw 1, potem 10, 100 i tak dalej. W każdym obiegu pętli:

1. `cyfra` to reszta z dzielenia `n` przez 10, czyli ostatnia cyfra liczby
2. jeśli `cyfra % 2 == 1`, cyfra jest nieparzysta, więc do `m` dodawane jest `cyfra * p`, a waga `p` rośnie dziesięciokrotnie
3. niezależnie od parzystości cyfry `n` jest dzielone całkowitoliczbowo przez 10, co usuwa przetworzoną cyfrę

Pętla działa, dopóki `n` jest większe od zera. Zgodnie ze specyfikacją skrót zawsze istnieje, więc przypadek liczby złożonej z samych cyfr parzystych nie wymaga obsługi.

Wersja w Pythonie:

```python
def zadanie_3_1(n: int) -> int:
    m = 0
    p = 1

    while n > 0:
        cyfra = n % 10
        if cyfra % 2 == 1:
            m += cyfra * p
            p *= 10
        n //= 10
    return m
```

Wersja w C++:

```cpp
long long zadanie_3_1(long long n) {
    long long m = 0;
    long long p = 1;
    while (n > 0) {
        long long cyfra = n % 10;
        if (cyfra % 2 == 1) {
            m += cyfra * p;
            p *= 10;
        }
        n /= 10;
    }
    return m;
}
```

Złożoność czasowa to O(d), gdzie `d` to liczba cyfr liczby `n`. Złożoność pamięciowa to O(1), bo używane są tylko cztery zmienne liczbowe.

W kluczu odpowiedzi CKE przykładowe rozwiązanie tego podpunktu podano wyłącznie w pseudokodzie. Pseudokod jest na maturze dopuszczalny, ale większość zdających wybiera zapis w języku programowania.

## Zgodność z ograniczeniami z arkusza

Treść zadania "Nieparzysty skrót" zawiera regułę typową dla tego rodzaju zadań maturalnych. Algorytm może używać wyłącznie zmiennych przechowujących liczby całkowite i może operować wyłącznie na liczbach całkowitych. Dozwolone są operacje arytmetyczne, porównywanie liczb, instrukcje sterujące, przypisania do zmiennych oraz samodzielnie napisane funkcje wykorzystujące te operacje. Zabronione jest używanie funkcji wbudowanych oraz operatorów innych niż wymienione.

Funkcja `zadanie_3_1` w obu językach spełnia te warunki. Używa tylko zmiennych całkowitych `n`, `m`, `p` i `cyfra`, a jedyne operatory to `%`, `*`, `+=`, `*=`, `//=` (w C++ `/=` na liczbach całkowitych), `>` i `==`. Nie zamienia liczby na napis i nie wywołuje żadnej funkcji wbudowanej. `print` i `cout` występują tylko w funkcji `main`, która wypisuje wyniki testowych wywołań.

## Wyniki

### Zadanie "Liczba Pi"

Program w Pythonie wypisuje:

```
Zadanie 3.1
13
902
Zadanie 3.2
Fragment: 00, Liczba: 0
Fragment: 62, Liczba: 4
--
Fragment: 88, Liczba: 80
Fragment: 65, Liczba: 124
```

Program w C++ wypisuje te same wartości bez opisów i bez separatora:

```
Zadanie 3.1
13
902
Zadanie 3.2
00, 0
62, 4
88, 80
65, 124
```

| Podpunkt | `pi_przyklad.txt` | `pi.txt` |
| --- | --- | --- |
| 3.1, liczba fragmentów większych od 90 | 13 | 902 |
| 3.2, najrzadszy fragment i liczba wystąpień | 00, 0 | 88, 80 |
| 3.2, najczęstszy fragment i liczba wystąpień | 62, 4 | 65, 124 |

Wyniki dla `pi_przyklad.txt` są zgodne z odpowiedziami podanymi w treści zadania, a wyniki dla `pi.txt` z kluczem odpowiedzi CKE.

### Zadanie "Nieparzysty skrót"

Oba programy wypisują:

```
97
3911
```

| Liczba `n` | Nieparzysty skrót `m` |
| --- | --- |
| 294762 | 97 |
| 39101 | 3911 |

Wyniki są zgodne z przykładami z treści zadania.

## Porównanie Pythona i C++

W nagraniu po każdym etapie zestawiam obie wersje kodu obok siebie. Tabela zbiera najważniejsze różnice widoczne w tym repozytorium.

| Element | Python | C++ |
| --- | --- | --- |
| Biblioteki | `open`, `sum`, `min` i `max` są dostępne bez importu. W zadaniu 3.2 importowane są `Counter` i `namedtuple` z modułu `collections` | Nagłówki `<fstream>`, `<iomanip>`, `<iostream>`, `<string>`, `<utility>`, `<vector>` oraz `using namespace std;` |
| Funkcja `main` | Opcjonalna | Obowiązkowa |
| Typy danych | Adnotacje typów są opcjonalne | Typ każdej zmiennej i każdego parametru jest obowiązkowy |
| Wczytanie pliku | Blok `with` i jedna instrukcja | Obiekt `ifstream` i pętla `while` |
| Fragmenty dwucyfrowe | List comprehension i wycinki (slicing) | `vector`, pętla `for`, `substr` i `stoi` |
| Zliczanie w 3.1 | `sum` z wyrażeniem generatorowym | Pętla `for` z licznikiem |
| Minimum i maksimum w 3.2 | `Counter` oraz `min` i `max` z parametrem `key` | Wektor liczników i ręczne wyszukiwanie w pętli |
| Zero wiodące | Wyrażenie warunkowe i f-string | `setw(2)` i `setfill('0')` |
| Zakres liczb całkowitych | Bardzo duży, typ nie wymaga uwagi | Trzeba dobrać typ, tutaj `long long` |

Wnioski z nagrania:

- Wczytywanie danych to pierwszy etap, na którym wygrywa Python. W C++ krótszy zapis też jest możliwy, ale wymaga poznania bardziej zaawansowanych elementów języka. Dla maturzysty liczy się niski próg wejścia.
- Obowiązkowe typy wydłużają kod w C++ i dają dodatkową okazję do pomyłek. Na maturze narzędzia AI są wyłączone, a podpowiedzi edytora są najprostsze z możliwych.
- Zadania maturalne są małe. To nie jest ten kaliber problemu, w którym wydajność C++ daje wyraźną przewagę nad Pythonem, więc wybieranie C++ tylko z tego powodu nie ma sensu.
- List comprehension, wycinki, `sum`, `Counter` oraz `min` i `max` z parametrem `key` łatwo opanować, a potem skracają kod na maturze. Klasyczne pętle z wersji C++ można tak samo zapisać w Pythonie.
- Nawet krótkie rozwiązanie w C++ zawiera szczegóły, które trzeba rozumieć, np. `&` i `const` przy parametrach, nawiasy ostrokątne w `vector<int>` czy typ `size_t`. W Pythonie tych detali nie ma.
- W prostym zadaniu "Nieparzysty skrót" obie implementacje są bardzo podobne i oba języki można by stosować zamiennie. W C++ trzeba jednak chwilę dłużej pomyśleć o typach.

Mój wybór na maturę to Python. Łatwo się go nauczyć, szybko daje efekty i wymaga pilnowania mniejszej liczby szczegółów niż C++.

## Kiedy wybrać Pythona, a kiedy C++

Plik `PODSUMOWANIE.txt` zawiera tabelę z wyborem języka na maturę:

| Python | C++ |
| --- | --- |
| Zaczynasz programować od zera lub do matury zostało mniej niż 12-10 miesięcy | Piszesz w C++ od dawna, często ten wybór narzuca szkoła |
| Tracisz czas na "techniczne" szczegóły zamiast skupiania się na algorytmie | Planujesz studia na kierunkach, gdzie wdrażasz rozwiązania oparte na C++ |
| Zależy Ci na szybkim tworzeniu krótkiego kodu | Lubisz obowiązkową kontrolę typów, poznawanie szczegółów składni i więcej kodu od języka |

Kiedy jesteś około 12-10 miesięcy przed maturą, możesz swobodnie zmieniać język programowania. Później pozostań przy języku programowania, którego używałeś do tej pory.

W praktyce taka zmiana to zwykle przejście z C++ na Pythona. Wiele osób, które przychodziły do mnie bez pewności w C++, przechodziło na Pythona. Za każdym razem była to dobra decyzja. Nie pamiętam, żeby ktoś przeszedł w drugą stronę.

C++ ma się bardzo dobrze na przykład w elektronice i w systemach wbudowanych. Jeśli planujesz studia w takim kierunku i już piszesz w C++, to C++ jest dla Ciebie dobrym wyborem także na maturze.

Bliżej egzaminu język programowania jest już tylko jednym z narzędzi. Wtedy lepiej skupić się na algorytmice, którą zrealizujesz zarówno w Pythonie, jak i w C++.

## Uwagi implementacyjne

- Programy wypisują wyniki w terminalu. Treść zadania "Liczba Pi" wymaga zapisania odpowiedzi w pliku `wyniki3.txt`, każdej poprzedzonej numerem zadania.
- Programy do zadania "Liczba Pi" liczą odpowiedzi zarówno dla `pi_przyklad.txt`, jak i dla `pi.txt`. Dzięki temu najpierw sprawdzasz rozwiązanie na danych, dla których znasz odpowiedź z treści zadania.
- Funkcja `main` i sekcja `if __name__ == "__main__":` w Pythonie nie są obowiązkowe. Porządkują jednak strukturę programu, a rozwiązanie wygląda bardziej elegancko i profesjonalnie. W C++ funkcja `main` jest obowiązkowa.
- Adnotacje typów w Pythonie są opcjonalne. Kod bez nich też jest poprawny, a ich użycie mogą sprawdzić narzędzia do kontroli typów.
- W C++ napisy są przekazywane do funkcji jako `const string&`, bo w szkołach częściej obowiązuje starszy standard języka. Wyjątkiem jest dekompozycja strukturalna w funkcji `main` w pliku `zad-1/app-1.cpp`, która wymaga C++17. W starszym standardzie wynik `zadanie_3_2` można odebrać jako `pair` i odwołać się do pól `first` i `second`.
- W zadaniu "Nieparzysty skrót" wersja w C++ używa typu `long long`, żeby nikt nie zarzucił możliwości przepełnienia. Na potrzeby matury ten zakres jest wystarczający. W Pythonie liczby całkowite mają bardzo duży zakres, ograniczony jedynie możliwościami systemu, więc problem doboru typu nie występuje.
- Logika każdego podpunktu jest zamknięta w osobnej funkcji, a wywołania testowe znajdują się w funkcji `main`. Dzięki temu samą funkcję można przenieść do innego programu bez zmian.