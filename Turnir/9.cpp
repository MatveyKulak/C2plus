#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        unordered_set<long long> vals;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            vals.insert(a[i]);
        }

        bool found = false;
        for (int i = 0; i < n && !found; ++i) {
            long long x = a[i];
            long long numerator = k + x;
            long long denom = x + 1;
            if (denom == 0) continue;
            if (numerator % denom != 0) continue;
            long long y = numerator / denom;
            if (y != x && vals.count(y)) {
                found = true;
            }
        }

        cout << (found ? "Yes\n" : "No\n");
    }

    return 0;
}
