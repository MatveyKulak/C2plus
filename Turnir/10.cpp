#include <iostream>
#include <cmath>
using namespace std;

const long long MOD = 1e9 + 7;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long mod_inverse(long long a, long long mod) {
    return mod_pow(a, mod - 2, mod);
}

int main() {
    long long n, p, r, k;
    cin >> n >> p >> r >> k;

    long long start = n * p;
    long long end = (n + 1) * p;
    long long count = 0;

    for (long long i = start; i < end; ++i) {
        long long current = (i * mod_pow(10, r, p)) % p;
        long long digit = (current * 10) / p;
        if (digit == k) {
            ++count;
        }
    }

    long long q = p;
    long long p_mod = count;
    long long q_inverse = mod_inverse(q, MOD);
    long long result = (p_mod * q_inverse) % MOD;

    cout << result << endl;

    return 0;
}