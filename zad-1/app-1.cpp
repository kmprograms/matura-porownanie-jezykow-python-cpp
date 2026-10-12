#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Wystapienia {
    int fragment;
    int liczba;
};

string wczytaj_cyfry(const string& nazwa_pliku) {
    ifstream plik(nazwa_pliku);
    string cyfry;
    char c;
    while (plik >> c) {
        cyfry += c;
    }
    return cyfry;
}

vector<int> fragmenty(const string& cyfry) {
    vector<int> wynik;
    for (size_t i = 0; i + 1 < cyfry.size(); ++i) {
        wynik.push_back(stoi(cyfry.substr(i, 2)));
    }
    return wynik;
}

int zadanie_3_1(const string& cyfry, int prog = 90) {
    int wynik = 0;
    for (int wartosc: fragmenty(cyfry)) {
        if (wartosc > prog) {
            ++wynik;
        }
    }
    return wynik;
}

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

void pokaz_wystapienia(const Wystapienia& w) {
    cout << setw(2) << setfill('0') << w.fragment << ", " << w.liczba << "\n";
}

int main() {
    const string PLIK_DANYCH = "pi.txt";
    const string PLIK_DANYCH_PRZYKLADOWYCH = "pi_przyklad.txt";
    string cyfry = wczytaj_cyfry(PLIK_DANYCH);
    string cyfry_przyklad = wczytaj_cyfry(PLIK_DANYCH_PRZYKLADOWYCH);
    
    cout << "Zadanie 3.1\n";
    cout << zadanie_3_1(cyfry_przyklad) << "\n";
    cout << zadanie_3_1(cyfry) << "\n"; 

    cout << "Zadanie 3.2\n";
    auto [najrzadszy_p, najczestszy_p] = zadanie_3_2(cyfry_przyklad);
    auto [najrzadszy, najczestszy] = zadanie_3_2(cyfry);
    pokaz_wystapienia(najrzadszy_p);
    pokaz_wystapienia(najczestszy_p);
    pokaz_wystapienia(najrzadszy);
    pokaz_wystapienia(najczestszy);

    return 0;
}