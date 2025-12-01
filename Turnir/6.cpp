#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    
    int low = -1e9, high = 1e9;
    for (int i = 0; i < n; ++i) {
        int curr_low = a[i] - b[i] - (w - h);
        int curr_high = a[i] - b[i] + (w - h);
        low = max(low, curr_low);
        high = min(high, curr_high);
        if (low > high) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}