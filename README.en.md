[Polski](README.md) · **English**

---

# Matura 2023 and 2024 (May) - computer science, extended level, task 3 "Liczba Pi" and task 3 "Nieparzysty skrót" - Python vs C++ comparison

> ### 🎬 Video walkthrough
> You can find a full step-by-step walkthrough of both tasks on my YouTube channel:
> **[Link to the YouTube video](https://youtu.be/Y1a8Y5cEOvs)**
>
> In the video I solve selected subtasks of two matura tasks side by side in Python and in C++. At every stage I compare the code in both languages and suggest which one to choose for the computer science matura.

---

## Table of contents

- [Description](#description)
- [Requirements](#requirements)
- [How to run](#how-to-run)
- [Project structure](#project-structure)
- [Task statements and solution approach](#task-statements-and-solution-approach)
- [Compliance with the exam sheet constraints](#compliance-with-the-exam-sheet-constraints)
- [Results](#results)
- [Comparing Python and C++](#comparing-python-and-c)
- [When to choose Python and when C++](#when-to-choose-python-and-when-c)
- [Implementation notes](#implementation-notes)

## Description

This repository contains solutions to selected subtasks of two tasks from the CKE (Polish Central Examination Board) computer science matura exam sheets at the extended level. Each solution is written twice, in Python and in C++. This lets you compare both languages on the same tasks and choose the one that will work better for you at the matura.

Tasks covered:

- Task 3 "Liczba Pi" (The number Pi) from the main May 2023 session, subtasks 3.1 and 3.2. The task is about two-digit fragments in the decimal expansion of Pi stored in a text file. The solution covers reading data from a file, counting fragments and finding the rarest and the most frequent fragment.
- Task 3 "Nieparzysty skrót" (Odd shortcut) from the main May 2024 session, subtask 3.1. You have to write a function that removes the even digits from the decimal representation of an integer. The task restricts you to integer operations, which is typical of matura exam sheets.

The comparison applies only to the computer science matura. It is not an assessment of which programming language is better in general.

## Requirements

- Python 3.9 or newer. Function signatures use the `list[int]` and `tuple[Wystapienia, Wystapienia]` type annotations, which do not work in older versions.
- A C++ compiler supporting the C++17 standard. The file `zad-1/app-1.cpp` uses structured bindings, e.g. `auto [najrzadszy, najczestszy] = zadanie_3_2(cyfry);`. The file `zad-2/app-2.cpp` also compiles under C++11.
- No external dependencies. The Python code uses only the standard library, including the `collections` module.

## How to run

Clone the repository and go to its directory:

```bash
git clone https://github.com/kmprograms/matura-porownanie-jezykow-python-cpp
cd matura-porownanie-jezykow-python-cpp
```

Each of the command blocks below assumes you start from the root directory of the repository.

### Task "Liczba Pi"

The programs open `pi.txt` and `pi_przyklad.txt` by file name only, so you run them from the `zad-1` directory.

Python version:

```bash
cd zad-1
python app-1.py
```

C++ version:

```bash
cd zad-1
g++ -std=c++17 -O2 -o app-1 app-1.cpp
./app-1
```

The program prints the answers to subtasks 3.1 and 3.2, each time first for the sample data and then for the actual data.

### Task "Nieparzysty skrót"

Python version:

```bash
cd zad-2
python app-2.py
```

C++ version:

```bash
cd zad-2
g++ -std=c++17 -O2 -o app-2 app-2.cpp
./app-2
```

The program prints two numbers, one per line, which are the results for the examples from the task statement. The full output of both programs is shown in the [Results](#results) section.

## Project structure

| File | Description |
| --- | --- |
| `PODSUMOWANIE.txt` | Summary table showing when to choose Python and when C++ for the matura |
| `zad-1/app-1.py` | Task "Liczba Pi", subtasks 3.1 and 3.2 in Python |
| `zad-1/app-1.cpp` | Task "Liczba Pi", subtasks 3.1 and 3.2 in C++ |
| `zad-1/pi.txt` | Task data, 10,000 digits of the decimal expansion of Pi after the decimal point, one digit per line |
| `zad-1/pi_przyklad.txt` | The first 100 lines of `pi.txt`, used to check the answers given in the task statement |
| `zad-2/app-2.py` | Task "Nieparzysty skrót", subtask 3.1 in Python |
| `zad-2/app-2.cpp` | Task "Nieparzysty skrót", subtask 3.1 in C++ |

## Task statements and solution approach

### Task 3 "Liczba Pi" (May 2023)

A mathematician wrote down the decimal expansion of Pi to 10,000 digits after the decimal point. All digits after the decimal point are stored in `pi.txt`, which has 10,000 lines with one digit on each. The file `pi_przyklad.txt` contains the first 100 lines of `pi.txt`, and the answers for this data are given below each subtask. The answers must be saved in `wyniki3.txt`, each preceded by the number of the task.

The repository solves subtasks 3.1 and 3.2.

#### Reading the data

The data is stored in a single string in which the digits form one continuous sequence. This form is tailored to subtasks 3.1 and 3.2. When solving the whole task, a different data structure might turn out to fit the remaining subtasks better.

Python version:

```python
def wczytaj_cyfry(nazwa_pliku: str) -> str:
    with open(nazwa_pliku) as plik:
        return "".join(plik.read().split())
```

The `open` function is available right away, with no imports. `read()` loads the whole file, `split()` splits it into digits and skips the newline characters, and `"".join(...)` joins the digits into a single string.

C++ version:

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

In C++ you need to include the `<fstream>` and `<string>` headers, create an `ifstream` object and append consecutive characters to the string in a loop. The `>>` operator skips whitespace, so newline characters do not end up in the result.

#### Task 3.1

A two-digit fragment is a pair of consecutive digits in `pi.txt`. There are 9999 two-digit fragments in total, and the last one starts on line 9999. You have to find the number of two-digit fragments that are decimal representations of numbers greater than 90. For the data in `pi_przyklad.txt` the correct answer is 13.

The solution starts with the `fragmenty` function, which turns the digit sequence into a list of all two-digit fragments as integers. The `zadanie_3_1` function counts the fragments greater than a threshold. The threshold is a parameter with a default value of 90.

Python version:

```python
def fragmenty(cyfry: str) -> list[int]:
    return [int(cyfry[i:i+2]) for i in range(len(cyfry) - 1)]
```

```python
def zadanie_3_1(cyfry: str, prog: int = 90) -> int:
    return sum(1 for wartosc in fragmenty(cyfry) if wartosc > prog)
```

`range(len(cyfry) - 1)` yields the indices from 0 to the second to last one. The slice `cyfry[i:i+2]` covers the characters at indices `i` and `i + 1`, because the upper bound is excluded. Counting is done by the built-in `sum` function with a generator expression that lets through only values greater than the threshold.

C++ version:

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

The fragments go into a `vector<int>`. Each pair of digits is cut out with `substr(i, 2)`, and `stoi` converts it to a number. The condition `i + 1 < cyfry.size()` iterates over the same indices as `range(len(cyfry) - 1)` in Python. Counting is a classic `for` loop with a counter.

Instead of `vector` you could use a plain array, because the data sizes are given in the task statement. Still, `vector` is worth knowing for the matura, because in many situations it is simply more convenient than a classic array.

#### Task 3.2

There are exactly 100 different possible two-digit fragments, from `00` to `99`. For example, the fragment `27` occurs in `pi.txt` exactly 101 times. You have to find the two-digit fragment with the smallest number of occurrences in `pi.txt` and the fragment with the largest number of occurrences, and give them together with their occurrence counts. If several fragments occur the same number of times, output the one with the smaller numeric value.

Python version:

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

This is the first point where Python needs any import at all. `Counter` counts all fragments in a single call. Then a `Wystapienia` object, a `namedtuple` with the fields `fragment` and `liczba`, is created for each number from 0 to 99. `Counter` returns 0 for fragments that never occurred, so they also take part in the search for the minimum. The rarest and the most frequent fragments are found by the built-in `min` and `max` functions with the `key` parameter.

In case of a tie, `min` and `max` return the first element found, and the list is ordered from fragment `00` to `99`. So the key `w.liczba` alone would be enough. For teaching purposes, the second criterion is written explicitly as the second element of the tuple. In `max` the fragment has a minus sign, because the smaller value should win a tie. Additional criteria can be added just as easily when sorting.

C++ version:

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

Instead of a `namedtuple` there is a `Wystapienia` struct, and instead of `Counter` there is a 100-element `licznik` vector in which the index corresponds to the fragment value. The minimum and maximum are searched for manually in a loop. Fragments are checked starting from the smallest, and the `<` and `>` comparisons are strict, so in case of a tie the fragment with the smaller value is kept. The two results are returned as a `pair` from the `<utility>` header.

Fragments smaller than 10 must be printed with a leading zero, that is `00` instead of `0`. The `pokaz_wystapienia` function takes care of that.

Python version:

```python
def pokaz_wystapienia(w: Wystapienia) -> None:
    fragment = f'0{w.fragment}' if w.fragment < 10 else f"{w.fragment}"
    print(f"Fragment: {fragment}, Liczba: {w.liczba}")
```

C++ version:

```cpp
void pokaz_wystapienia(const Wystapienia& w) {
    cout << setw(2) << setfill('0') << w.fragment << ", " << w.liczba << "\n";
}
```

In Python the leading zero is added by a conditional expression. In C++ `setw(2)` and `setfill('0')` from the `<iomanip>` header make sure the fragment always takes two positions.

Both subtasks go through all fragments, so the time complexity is O(N), where `N` is the number of digits. The list of fragments takes O(N) memory.

### Task 3 "Nieparzysty skrót" (May 2024)

#### Task 3.1

The odd shortcut of a positive integer `n` is the positive integer `m` obtained by removing the even digits from the decimal representation of `n`. The odd shortcut does not exist when the decimal representation of the number consists of even digits only.

Examples from the task statement:

- the odd shortcut of 294762 is 97
- the odd shortcut of 39101 is 3911
- the odd shortcut of 224 does not exist

You have to write, in pseudocode or in a programming language of your choice, a function that for a positive integer `n` whose odd shortcut exists computes the number `m`, that is the odd shortcut of `n`.

Specification from the exam sheet:

- Input: `n` - a positive integer for which the odd shortcut exists
- Output: `m` - the odd shortcut of `n`

The algorithm goes through the digits of `n` starting from the least significant one. The variable `p` stores the weight of the position where the next odd digit will be placed in `m`, that is first 1, then 10, 100 and so on. In each iteration of the loop:

1. `cyfra` is the remainder of dividing `n` by 10, that is the last digit of the number
2. if `cyfra % 2 == 1`, the digit is odd, so `cyfra * p` is added to `m` and the weight `p` is multiplied by ten
3. regardless of the digit's parity, `n` is divided by 10 using integer division, which removes the processed digit

The loop runs while `n` is greater than zero. According to the specification the shortcut always exists, so a number made only of even digits does not need to be handled.

Python version:

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

C++ version:

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

The time complexity is O(d), where `d` is the number of digits of `n`. The space complexity is O(1), because only four numeric variables are used.

In the CKE answer key, the sample solution for this subtask is given only in pseudocode. Pseudocode is accepted at the matura, but most candidates choose to write in a programming language.

## Compliance with the exam sheet constraints

The statement of the "Nieparzysty skrót" task includes a rule typical of this kind of matura task. The algorithm may use only variables that store integers and may operate only on integers. Allowed are arithmetic operations, comparisons of numbers, control statements, assignments to variables and self-written functions that use these operations. Using built-in functions and operators other than those listed is forbidden.

The `zadanie_3_1` function meets these conditions in both languages. It uses only the integer variables `n`, `m`, `p` and `cyfra`, and the only operators are `%`, `*`, `+=`, `*=`, `//=` (in C++ `/=` on integers), `>` and `==`. It does not convert the number to a string and does not call any built-in function. `print` and `cout` appear only in the `main` function, which prints the results of the test calls.

## Results

### Task "Liczba Pi"

The Python program prints:

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

The C++ program prints the same values without labels and without the separator:

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

| Subtask | `pi_przyklad.txt` | `pi.txt` |
| --- | --- | --- |
| 3.1, number of fragments greater than 90 | 13 | 902 |
| 3.2, rarest fragment and number of occurrences | 00, 0 | 88, 80 |
| 3.2, most frequent fragment and number of occurrences | 62, 4 | 65, 124 |

The results for `pi_przyklad.txt` match the answers given in the task statement, and the results for `pi.txt` match the CKE answer key.

### Task "Nieparzysty skrót"

Both programs print:

```
97
3911
```

| Number `n` | Odd shortcut `m` |
| --- | --- |
| 294762 | 97 |
| 39101 | 3911 |

The results match the examples from the task statement.

## Comparing Python and C++

In the video, after each stage I put both versions of the code side by side. The table lists the most important differences visible in this repository.

| Element | Python | C++ |
| --- | --- | --- |
| Libraries | `open`, `sum`, `min` and `max` are available without imports. Task 3.2 imports `Counter` and `namedtuple` from the `collections` module | The `<fstream>`, `<iomanip>`, `<iostream>`, `<string>`, `<utility>`, `<vector>` headers and `using namespace std;` |
| `main` function | Optional | Mandatory |
| Data types | Type annotations are optional | The type of every variable and every parameter is mandatory |
| Reading the file | A `with` block and a single statement | An `ifstream` object and a `while` loop |
| Two-digit fragments | List comprehension and slicing | `vector`, a `for` loop, `substr` and `stoi` |
| Counting in 3.1 | `sum` with a generator expression | A `for` loop with a counter |
| Minimum and maximum in 3.2 | `Counter` plus `min` and `max` with the `key` parameter | A vector of counters and a manual search in a loop |
| Leading zero | A conditional expression and an f-string | `setw(2)` and `setfill('0')` |
| Integer range | Very large, the type needs no attention | You have to pick a type, here `long long` |

Takeaways from the video:

- Reading the data is the first stage where Python wins. A shorter version is possible in C++ too, but it requires learning more advanced parts of the language. For a matura candidate, a low entry threshold is what counts.
- Mandatory types make C++ code longer and give extra room for mistakes. At the matura, AI tools are disabled and the editor hints are as basic as they get.
- Matura tasks are small. This is not the kind of problem where C++ performance gives a clear edge over Python, so choosing C++ for that reason alone makes no sense.
- List comprehension, slicing, `sum`, `Counter`, and `min` and `max` with the `key` parameter are easy to master and then shorten your code at the matura. The classic loops from the C++ version can be written the same way in Python.
- Even a short C++ solution contains details you need to understand, e.g. `&` and `const` on parameters, the angle brackets in `vector<int>` or the `size_t` type. Python has none of these details.
- In the simple "Nieparzysty skrót" task both implementations are very similar and the two languages could be used interchangeably. In C++, however, you need to think a little longer about types.

My choice for the matura is Python. It is easy to learn, gives results quickly and requires keeping track of fewer details than C++.

## When to choose Python and when C++

The file `PODSUMOWANIE.txt` contains a table for choosing the language for the matura:

| Python | C++ |
| --- | --- |
| You are starting to program from scratch or there are fewer than 12-10 months left before the matura | You have been writing C++ for a long time, often this choice is imposed by the school |
| You waste time on "technical" details instead of focusing on the algorithm | You plan to study a field where you build solutions based on C++ |
| You care about writing short code quickly | You like mandatory type checking, learning the details of syntax and more code required by the language |

When you are about 12-10 months before the matura, you can freely switch programming languages. After that, stick to the programming language you have been using so far.

In practice such a switch is usually a move from C++ to Python. Many people who came to me feeling unsure about C++ switched to Python. Every time it was a good decision. I do not remember anyone switching the other way.

C++ is doing very well, for example, in electronics and embedded systems. If you plan to study in such a field and already write C++, then C++ is a good choice for you at the matura as well.

Closer to the exam, the programming language is just one of the tools. At that point it is better to focus on algorithms, which you can implement in Python as well as in C++.

## Implementation notes

- The programs print their results to the terminal. The "Liczba Pi" task statement requires saving the answers in `wyniki3.txt`, each preceded by the number of the task.
- The "Liczba Pi" programs compute the answers for both `pi_przyklad.txt` and `pi.txt`. This way you first check the solution on data for which you know the answer from the task statement.
- The `main` function and the `if __name__ == "__main__":` section are not mandatory in Python. They do, however, keep the program structure tidy and make the solution look more elegant and professional. In C++ the `main` function is mandatory.
- Type annotations in Python are optional. Code without them is also correct, and their use can be checked by type checking tools.
- In C++ strings are passed to functions as `const string&`, because schools more often use an older standard of the language. The exception is the structured binding in the `main` function in `zad-1/app-1.cpp`, which requires C++17. With an older standard you can receive the result of `zadanie_3_2` as a `pair` and access its `first` and `second` fields.
- In the "Nieparzysty skrót" task the C++ version uses the `long long` type, so that no one can point to a possible overflow. For the purposes of the matura this range is sufficient. In Python integers have a very large range, limited only by the capabilities of the system, so choosing a type is not an issue.
- The logic of each subtask is enclosed in a separate function, and the test calls are in the `main` function. Thanks to this, the function itself can be moved to another program without changes.