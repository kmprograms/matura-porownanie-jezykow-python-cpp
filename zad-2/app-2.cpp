#include <iostream>

using namespace std;

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

int main() {
    cout << zadanie_3_1(294762) << "\n";
    cout << zadanie_3_1(39101) << "\n";
    return 0;
}