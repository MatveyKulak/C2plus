#include <bits/stdc++.h>
using namespace std;

struct CellWalls { bool top = false, bottom = false, left = false, right = false; };
using Maze = vector<vector<CellWalls>>;
using Point = pair<int, int>;

const int DY[4] = {-1, 1, 0, 0};
const int DX[4] = {0, 0, -1, 1};

Maze generate_maze(int H, int W, double frac = 0.5) {
    Maze m(H, vector<CellWalls>(W));
    random_device rd; mt19937 g(rd());
    uniform_int_distribution<> ry(0, H - 1), rx(0, W - 1), rd4(0, 3);

    for (int y = 0; y < H; y++) {
        m[y][0].left = true;
        m[y][W - 1].right = true;
    }
    for (int x = 0; x < W; x++) {
        m[0][x].top = true;
        m[H - 1][x].bottom = true;
    }

    int cnt = int(H * W * frac);
    while (cnt--) {
        int y = ry(g), x = rx(g), d = rd4(g);
        auto& c = m[y][x];
        if (d == 0 && y > 0 && !c.top) { c.top = true; m[y - 1][x].bottom = true; }
        else if (d == 1 && y < H - 1 && !c.bottom) { c.bottom = true; m[y + 1][x].top = true; }
        else if (d == 2 && x > 0 && !c.left) { c.left = true; m[y][x - 1].right = true; }
        else if (d == 3 && x < W - 1 && !c.right) { c.right = true; m[y][x + 1].left = true; }
    }

    return m;
}

Point slide(const Maze& m, int y, int x, int d) {
    int H = m.size(), W = m[0].size(), ny = y, nx = x;
    while (true) {
        if ((d == 0 && m[ny][nx].top) || (d == 1 && m[ny][nx].bottom) ||
            (d == 2 && m[ny][nx].left) || (d == 3 && m[ny][nx].right)) break;
        int ty = ny + DY[d], tx = nx + DX[d];
        if (ty < 0 || ty >= H || tx < 0 || tx >= W) break;
        if ((d == 0 && m[ty][tx].bottom) || (d == 1 && m[ty][tx].top) ||
            (d == 2 && m[ty][tx].right) || (d == 3 && m[ty][tx].left)) break;
        ny = ty; nx = tx;
    }
    return {ny, nx};
}

vector<Point> find_shortest(const Maze& m, Point goal) {
    int H = m.size(), W = m[0].size();
    vector<vector<bool>> vis(H, vector<bool>(W, false));
    deque<pair<Point, vector<Point>>> dq;
    dq.push_back({{0, 0}, {{0, 0}}});
    vis[0][0] = true;

    while (!dq.empty()) {
        auto [p, path] = dq.front(); dq.pop_front();
        int y = p.first, x = p.second;
        if (p == goal) return path;
        for (int d = 0; d < 4; d++) {
            auto np = slide(m, y, x, d);
            if (!vis[np.first][np.second]) {
                vis[np.first][np.second] = true;
                auto npth = path;
                npth.emplace_back(np);
                dq.push_back({np, move(npth)});
            }
        }
    }

    return {};
}

void print_pretty(const Maze& m, const vector<Point>& path) {
    int H = m.size(), W = m[0].size();
    vector<string> g(H, string(W, '.'));

    for (int i = 0; i + 1 < (int)path.size(); ++i) {
        auto [y, x] = path[i];
        auto [ny, nx] = path[i + 1];
        if (ny < y) g[y][x] = '^';
        else if (ny > y) g[y][x] = 'v';
        else if (nx < x) g[y][x] = '<';
        else if (nx > x) g[y][x] = '>';
    }

    if (!path.empty()) {
        auto s = path.front(), t = path.back();
        g[s.first][s.second] = 'S';
        g[t.first][t.second] = 'G';
    }

    for (int y = 0; y <= H; ++y) {
        for (int x = 0; x < W; ++x) {
            cout << "+";
            if (y > 0 && m[y - 1][x].bottom) cout << "---";
            else if (y < H && m[y][x].top) cout << "---";
            else cout << "   ";
        }
        cout << "+\n";
        if (y == H) break;
        for (int x = 0; x <= W; ++x) {
            if (x > 0 && x < W) cout << (m[y][x - 1].right ? "|" : " ");
            else cout << "|";
            if (x < W) cout << " " << g[y][x] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "Лабиринт Йети\n\n";
    int W, H;
    cout << "Введите ширину лабиринта: " << flush; cin >> W;
    cout << "Введите высоту лабиринта: " << flush; cin >> H;

    Maze m;
    vector<Point> path;
    Point start = {0, 0}, goal;
    random_device rd; mt19937 gen(rd());
    uniform_int_distribution<> ry(0, H - 1), rx(0, W - 1);

    do {
        goal = {ry(gen), rx(gen)};
    } while (goal == start);

    do {
        m = generate_maze(H, W, 0.6);
        path = find_shortest(m, goal);
    } while (path.empty());

    cout << "\nКратчайший путь (" << path.size() - 1 << " ходов):\n";
    print_pretty(m, path);

    return 0;
}
