#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int max_size = 100;
const char wall = '%';
const char Empty = ' ';
const char target_symbol = '@';
const char path = '.';

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct position {
    int row;
    int col;
};

bool is_valid_position(int row, int col, int rows, int cols,
    const vector<string>& maze, bool visited[max_size][max_size]) {
        return row >= 0 && row < rows && col >= 0 && col < cols &&
        (maze[row][col] == Empty || maze[row][col] == target_symbol) &&
            !visited[row][col];
}

void print_maze_with_borders(const vector<string>& maze) {
    const char horizontal = '-';
    const char vertical = '|';
    const char corner = '+';

    cout << corner;
    for (int col = 0; col < maze[0].size(); col++) {
        cout << horizontal << horizontal << horizontal << corner;
    }
    cout << endl;

    for (int row = 0; row < maze.size(); row++) {
        cout << vertical;
        for (int col = 0; col < maze[row].size(); col++) {
            char cell = maze[row][col];
            cout << " " << cell << " " << vertical;
        }
        cout << endl;

        cout << corner;
        for (int col = 0; col < maze[row].size(); col++) {
            cout << horizontal << horizontal << horizontal << corner;
        }
        cout << endl;
    }
}

void print_welcome_message() {
    cout << "Лабиринт\n";
    cout << "Йети ищет путь от начальной точки до цели (@)\n";
    cout << "Символы: % - стена, пробел - проход, @ - цель\n";
    cout << "Ввод строк должен быть без пробелов между символами!\n";
}

int main() {
    print_welcome_message();

    int rows, cols;
    cout << "Введите размеры лабиринта (строки столбцы): ";
    cin >> rows >> cols;

    vector<string> maze(rows);
    cout << "\nВведите лабиринт (пример строки: %%%@%):\n";
    cin.ignore();
    for (int i = 0; i < rows; ++i) {
        cout << "Строка " << (i + 1) << ": ";
        getline(cin, maze[i]);

        if (maze[i].size() != cols) {
            cout << "Ошибка: строка должна содержать ровно " << cols << " символов.\n";
            return 1;
        }
    }

    position start;
    cout << "\nВведите начальную позицию (строка столбец): ";
    cin >> start.row >> start.col;

    position queue[max_size * max_size];
    int front = 0, rear = 0;

    bool visited[max_size][max_size] = {};
    position parent[max_size][max_size];

    visited[start.row][start.col] = true;
    queue[rear++] = start;

    position target = {-1, -1};
    bool target_found = false;

    while (front < rear && !target_found) {
        position current = queue[front++];

        if (maze[current.row][current.col] == target_symbol) {
            target = current;
            target_found = true;
            break;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int new_row = current.row + dx[dir];
            int new_col = current.col + dy[dir];

            if (is_valid_position(new_row, new_col, rows, cols, maze, visited)) {
                visited[new_row][new_col] = true;
                queue[rear++] = {new_row, new_col};
                parent[new_row][new_col] = current;
            }
        }
    }

    if (!target_found) {
        cout << "\nЦель не найдена!\n";
        return 0;
    }

    position p = target;
    while (!(p.row == start.row && p.col == start.col)) {
        if (maze[p.row][p.col] != target_symbol)
            maze[p.row][p.col] = path;
        p = parent[p.row][p.col];
    }

    cout << "\nПуть найден (обозначен точками '.'):\n";
    print_maze_with_borders(maze);

    cout << "Путь от (" << start.row << "," << start.col << ") ";
    cout << "до (" << target.row << "," << target.col << ")\n";

    return 0;
}
