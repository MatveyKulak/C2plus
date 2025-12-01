#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
int adj[200][200], res[200][200], temp[200][200];

void multiply(int a[200][200], int b[200][200], int n, int c[200][200]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
            }
        }
    }
}

void matrix_pow(int a[200][200], int n, int k, int result[200][200]) {
    int temp_pow[200][200];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = (i == j);
        }
    }
    while (k > 0) {
        if (k % 2 == 1) {
            multiply(result, a, n, temp_pow);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    result[i][j] = temp_pow[i][j];
                }
            }
        }
        multiply(a, a, n, temp_pow);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = temp_pow[i][j];
            }
        }
        k /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u-1][v-1] = 1;
        adj[v-1][u-1] = 1;
    }

    matrix_pow(adj, n, k, res);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << res[a-1][b-1] << '\n';
    }

    return 0;
}