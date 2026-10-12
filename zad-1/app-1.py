from collections import Counter, namedtuple

Wystapienia = namedtuple("Wystapienia", "fragment,liczba")

def wczytaj_cyfry(nazwa_pliku: str) -> str:
    with open(nazwa_pliku) as plik:
        return "".join(plik.read().split())
    
def fragmenty(cyfry: str) -> list[int]:
    return [int(cyfry[i:i+2]) for i in range(len(cyfry) - 1)]    
    
def zadanie_3_1(cyfry: str, prog: int = 90) -> int:
    return sum(1 for wartosc in fragmenty(cyfry) if wartosc > prog)    

def pokaz_wystapienia(w: Wystapienia) -> None:
    fragment = f'0{w.fragment}' if w.fragment < 10 else f"{w.fragment}"
    print(f"Fragment: {fragment}, Liczba: {w.liczba}")
    
def zadanie_3_2(cyfry: str) -> tuple[Wystapienia, Wystapienia]:
    licznik = Counter(fragmenty(cyfry))
    wszystkie = [Wystapienia(n, licznik[n]) for n in range(100)]
    najrzadszy = min(wszystkie, key=lambda w: (w.liczba, w.fragment))
    najczestszy = max(wszystkie, key=lambda w: (w.liczba, -w.fragment))
    return najrzadszy, najczestszy
    
        
def main() -> None:
    PLIK_DANYCH = "pi.txt"
    PLIK_DANYCH_PRZYKLADOWYCH = "pi_przyklad.txt"
    cyfry = wczytaj_cyfry(PLIK_DANYCH)
    cyfry_przyklad = wczytaj_cyfry(PLIK_DANYCH_PRZYKLADOWYCH)
    
    print("Zadanie 3.1")
    print(zadanie_3_1(cyfry_przyklad))
    print(zadanie_3_1(cyfry))
    
    print("Zadanie 3.2")
    najrzadszy_p, najczestszy_p = zadanie_3_2(cyfry_przyklad)
    pokaz_wystapienia(najrzadszy_p)
    pokaz_wystapienia(najczestszy_p)
    print("--")
    najrzadszy, najczestszy = zadanie_3_2(cyfry)
    pokaz_wystapienia(najrzadszy)
    pokaz_wystapienia(najczestszy)
        
    
    
if __name__ == "__main__":
    main()    


        