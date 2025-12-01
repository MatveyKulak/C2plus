#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

int n;
vector<pair<ll, ll>> imp;
vector<vector<pair<int, int>>> adj;
vector<bool> used_edge;
vector<int> ans;

void dfs(int u) {
    auto &lst = adj[u];
    while (!lst.empty()) {
        auto [v, eid] = lst.back();
        lst.pop_back();
        if (used_edge[eid]) continue;
        used_edge[eid] = true;
        dfs(v);
        ans.push_back(eid);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    imp.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> imp[i].first >> imp[i].second;
    }

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    vector<ll> va, vb;
    for (auto &[a, b] : imp) {
        va.push_back(a);
        vb.push_back(b);
    }

    sort(va.begin(), va.end());
    va.erase(unique(va.begin(), va.end()), va.end());
    sort(vb.begin(), vb.end());
    vb.erase(unique(vb.begin(), vb.end()), vb.end());

    int na = va.size(), nb = vb.size();
    int V = na + nb;
    adj.assign(V, {});
    used_edge.assign(n, false);
    vector<int> deg(V, 0);

    for (int i = 0; i < n; ++i) {
        int ai = lower_bound(va.begin(), va.end(), imp[i].first) - va.begin();
        int bi = lower_bound(vb.begin(), vb.end(), imp[i].second) - vb.begin() + na;
        adj[ai].emplace_back(bi, i);
        adj[bi].emplace_back(ai, i);
        deg[ai]++;
        deg[bi]++;
    }

    for (int u = 0; u < V; ++u) {
        sort(adj[u].begin(), adj[u].end(), [&](auto &a, auto &b) {
            return a.second > b.second;
        });
    }

    vector<int> odd;
    for (int u = 0; u < V; ++u)
        if (deg[u] % 2)
            odd.push_back(u);

    if (!odd.empty() && odd.size() != 2) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> cand = odd.empty() ? vector<int>() : odd;
    if (cand.empty()) {
        for (int u = 0; u < V; ++u)
            if (!adj[u].empty())
                cand.push_back(u);
    }

    int start = -1, best_e = n + 1;
    for (int u : cand) {
        if (!adj[u].empty() && adj[u].back().second < best_e) {
            best_e = adj[u].back().second;
            start = u;
        }
    }

    dfs(start);

    if ((int)ans.size() != n) {
        cout << -1 << "\n";
        return 0;
    }

    reverse(ans.begin(), ans.end());
    for (int eid : ans) {
        cout << eid + 1 << " ";
    }
    cout << "\n";

    return 0;
}
