#include <iostream>
using namespace std;
using ll = long long;

const int MOD = 1000000007;

ll power(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ll n;
    int k;
    ll a;
    cin >> n >> k >> a;

    if (n == 0 || a == 0) {
        cout << 0 << "\n";
        return 0;
    }

    if (a == 1) {
        ll ans = 0;
        for (ll i = 1; i <= n; ++i)
            ans = (ans + power(i, k)) % MOD;
        cout << ans << "\n";
        return 0;
    }

    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        ans = (ans + power(a, i) * power(i, k) % MOD) % MOD;
    }
    cout << ans << "\n";
    return 0;
}