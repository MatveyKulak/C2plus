#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const string RGB = "RGB";

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<vector<int>> cost(3, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cost[j][i] = (s[i] != RGB[(i + j) % 3]);
        }
    }

    vector<vector<int>> prefix(3, vector<int>(n + 1));
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < n; ++i) {
            prefix[j][i + 1] = prefix[j][i] + cost[j][i];
        }
    }

    int ans = k;
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i + k <= n; ++i) {
            int current = prefix[j][i + k] - prefix[j][i];
            ans = min(ans, current);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}