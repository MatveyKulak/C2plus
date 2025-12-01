#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200005;
int a[MAXN];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);

    int x;
    if (k == 0) {
        x = a[0] - 1;
        if (x < 1) cout << -1 << endl;
        else cout << x << endl;
    } else if (k == n) {
        cout << 1000000000 << endl;
    } else {
        x = a[k - 1];
        if (a[k] == x) cout << -1 << endl;
        else cout << x << endl;
    }

    return 0;
}
