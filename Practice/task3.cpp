#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const char wall1 = '%';
const char wall2 = '*';
const char Empty = ' ';
const char ladder = '#';
const char chain = '-';
const char goal_symbol = '@';
const char start_mark = 'Y';
const char path_mark = '.';

const int max_size = 100;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct position {
    int row;
    int col;
};

bool inside(int row, int col, int n, int m) {
    return row >= 0 && row < n && col >= 0 && col < m;
}

bool passable(char ch) {
    return ch == Empty || ch == ladder || ch == chain || ch == goal_symbol;
}

void fall(position& pos, const vector<string>& maze) {
    int n = maze.size();
    while (pos.row + 1 < n && maze[pos.row + 1][pos.col] == Empty) {
        pos.row++;
    }
}

void print_pretty(const vector<string>& maze) {
    int n = maze.size();
    int m = maze[0].size();
    string horizontal = "+";
    for (int j = 0; j < m; ++j) {
        horizontal += "---+";
    }

    cout << "\nПуть найден (обозначен точками '.'): \n";
    for (int i = 0; i < n; ++i) {
        cout << horizontal << '\n';
        cout << "|";
        for (int j = 0; j < m; ++j) {
            cout << " " << maze[i][j] << " |";
        }
        cout << '\n';
    }
    cout << horizontal << '\n';
}

int main() {
    cout << "Добро пожаловать в игру \"Йети в вертикальном лабиринте\"!\n\n";
    cout << "Обозначения:\n";
    cout << "  " << wall1 << ", " << wall2 << " — стены\n";
    cout << "  " << Empty << " — пустое пространство\n";
    cout << "  " << ladder << " — вертикальная лестница\n";
    cout << "  " << chain << " — горизонтальная цепь\n";
    cout << "  " << goal_symbol << " — цель\n";
    cout << "  " << start_mark << " — начальная позиция Йети\n";
    cout << "  " << path_mark << " — путь Йети\n\n";

    int n, m;
    cout << "Введите размеры лабиринта (n m): ";
    cin >> n >> m;
    cin.ignore();

    if (n > max_size || m > max_size || n <= 0 || m <= 0) {
        cout << "Недопустимый размер лабиринта.\n";
        return 1;
    }

    vector<string> maze(n);
    position start = {-1, -1};

    cout << "\nВведите лабиринт построчно (ровно " << m << " символов в каждой строке):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Строка " << i << ": ";
        getline(cin, maze[i]);
        if (maze[i].size() != m) {
            cout << "Ошибка: строка должна содержать ровно " << m << " символов.\n";
            return 1;
        }
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == start_mark) {
                start = {i, j};
            }
        }
    }

    if (start.row == -1) {
        cout << "\nОшибка: старт Йети (Y) не найден в лабиринте.\n";
        return 1;
    }

    maze[start.row][start.col] = Empty;
    fall(start, maze);

    queue<position> q;
    bool visited[max_size][max_size] = {};
    position parent[max_size][max_size];

    visited[start.row][start.col] = true;
    q.push(start);

    position goal = {-1, -1};
    bool found = false;

    while (!q.empty() && !found) {
        position curr = q.front(); q.pop();
        if (maze[curr.row][curr.col] == goal_symbol) {
            goal = curr;
            found = true;
            break;
        }
        for (int dir = 0; dir < 4; ++dir) {
            int nr = curr.row + dx[dir];
            int nc = curr.col + dy[dir];
            if (!inside(nr, nc, n, m)) continue;
            char from = maze[curr.row][curr.col];
            char to = maze[nr][nc];
            bool can_move = false;
            if (dir == 0 && (from == ladder || from == Empty) && to != wall1 && to != wall2) can_move = true;
            if (dir == 1 && passable(to)) can_move = true;
            if ((dir == 2 || dir == 3) && (from == chain || from == Empty) && passable(to)) can_move = true;
            if (can_move && !visited[nr][nc]) {
                position next = {nr, nc};
                fall(next, maze);
                if (!visited[next.row][next.col]) {
                    visited[next.row][next.col] = true;
                    parent[next.row][next.col] = curr;
                    q.push(next);
                }
            }
        }
    }

    if (!found) {
        cout << "\nЦель (" << goal_symbol << ") не найдена. Йети застрял в лабиринте.\n";
        return 0;
    }

    position p = goal;
    int steps = 0;
    while (!(p.row == start.row && p.col == start.col)) {
        if (maze[p.row][p.col] == Empty)
            maze[p.row][p.col] = path_mark;
        p = parent[p.row][p.col];
        steps++;
    }

    maze[start.row][start.col] = start_mark;
    maze[goal.row][goal.col] = goal_symbol;

    print_pretty(maze);

    cout << "\nЙети прошёл путь от (" << start.row << ", " << start.col << ") ";
    cout << "до цели (" << goal.row << ", " << goal.col << ").\n";
    cout << "Количество шагов в кратчайшем пути: " << steps << "\n";

    return 0;
}
