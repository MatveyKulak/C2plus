#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace std;

struct Cell {
    int trash;
    bool is_obstacle = false;
    bool is_hazard = false;
};

int N, M;
vector<vector<Cell>> room;
vector<vector<long long>> dp;
vector<vector<int>> trash_dp;
vector<vector<int>> dp_no_trash;
vector<vector<int>> min_path_dp;
vector<vector<int>> max_path_dp;
vector<vector<long long>> all_paths;
int total_trash = 0;

bool is_valid(int x, int y, bool allow_hazard) {
    if (x < 0 || y < 0 || x >= N || y >= M) return false;
    if (room[x][y].is_obstacle) return false;
    if (!allow_hazard && room[x][y].trash < 0) return false;
    return true;
}

void calculate_paths(int start_x, int start_y, int end_x, int end_y, bool allow_hazard) {
    dp = vector<vector<long long>>(N, vector<long long>(M, 0));
    trash_dp = vector<vector<int>>(N, vector<int>(M, 0));
    dp_no_trash = vector<vector<int>>(N, vector<int>(M, 0));
    min_path_dp = vector<vector<int>>(N, vector<int>(M, INT_MAX));
    max_path_dp = vector<vector<int>>(N, vector<int>(M, -1));
    all_paths = vector<vector<long long>>(N, vector<long long>(M, 0));

    dp[start_x][start_y] = 1;
    trash_dp[start_x][start_y] = (room[start_x][start_y].trash > 0) ? room[start_x][start_y].trash : 0;
    dp_no_trash[start_x][start_y] = (room[start_x][start_y].trash <= 0) ? 1 : 0;
    min_path_dp[start_x][start_y] = 0;
    max_path_dp[start_x][start_y] = 0;
    all_paths[start_x][start_y] = 1;

    for (int i = start_x; i < N; ++i) {
        for (int j = start_y; j < M; ++j) {
            if ((i == start_x && j == start_y) || !is_valid(i, j, allow_hazard)) continue;

            int cell_trash = (room[i][j].trash > 0) ? room[i][j].trash : 0;

            vector<pair<int,int>> prev_cells = {{i-1,j}, {i,j-1}, {i-1,j-1}};

            long long paths = 0;
            int min_path = INT_MAX;
            int max_path = -1;
            int max_trash = -1;
            long long max_trash_paths = 0;
            int no_trash_paths = 0;

            for (auto& p : prev_cells) {
                int x = p.first;
                int y = p.second;
                if (!is_valid(x, y, allow_hazard)) continue;

                paths += all_paths[x][y];

                if (min_path_dp[x][y] != INT_MAX) {
                    min_path = min(min_path, min_path_dp[x][y] + 1);
                }
                if (max_path_dp[x][y] != -1) {
                    max_path = max(max_path, max_path_dp[x][y] + 1);
                }

                if (trash_dp[x][y] + cell_trash > max_trash) {
                    max_trash = trash_dp[x][y] + cell_trash;
                    max_trash_paths = dp[x][y];
                } else if (trash_dp[x][y] + cell_trash == max_trash) {
                    max_trash_paths += dp[x][y];
                }

                if (cell_trash == 0) {
                    no_trash_paths += dp_no_trash[x][y];
                }
            }

            all_paths[i][j] = paths;
            trash_dp[i][j] = max_trash;
            dp[i][j] = max_trash_paths;
            dp_no_trash[i][j] = no_trash_paths;
            if (min_path != INT_MAX) min_path_dp[i][j] = min_path;
            if (max_path != -1) max_path_dp[i][j] = max_path;
        }
    }

    vector<vector<int>> full_min(N, vector<int>(M, INT_MAX));
    vector<vector<int>> full_max(N, vector<int>(M, -1));
    full_min[start_x][start_y] = 0;
    full_max[start_x][start_y] = 0;

    for (int i = start_x; i < N; ++i) {
        for (int j = start_y; j < M; ++j) {
            if ((i == start_x && j == start_y) || !is_valid(i, j, allow_hazard)) continue;

            int cell_trash = (room[i][j].trash > 0) ? room[i][j].trash : 0;
            vector<pair<int,int>> prev_cells = {{i-1,j}, {i,j-1}, {i-1,j-1}};

            int current_min = INT_MAX;
            int current_max = -1;

            for (auto& p : prev_cells) {
                int x = p.first;
                int y = p.second;
                if (!is_valid(x, y, allow_hazard)) continue;

                if (trash_dp[x][y] + cell_trash == trash_dp[i][j]) {
                    if (full_min[x][y] != INT_MAX) {
                        current_min = min(current_min, full_min[x][y] + 1);
                    }
                    if (full_max[x][y] != -1) {
                        current_max = max(current_max, full_max[x][y] + 1);
                    }
                }
            }

            if (current_min != INT_MAX) full_min[i][j] = current_min;
            if (current_max != -1) full_max[i][j] = current_max;
        }
    }

    min_path_dp = full_min;
    max_path_dp = full_max;
}

void print_matrix() {
    cout << "\nВведённый план комнаты:\n";
    int cell_width = 6;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) cout << "+" << string(cell_width, '-');
        cout << "+\n";

        for (int j = 0; j < M; ++j) {
            cout << "|";
            cout << setw(cell_width-1) << right << room[i][j].trash << " ";
        }
        cout << "|\n";
    }
    for (int j = 0; j < M; ++j) cout << "+" << string(cell_width, '-');
    cout << "+\n";
}

int main() {
    cout << "Введите количество строк (N) и столбцов (M): ";
    cin >> N >> M;

    room = vector<vector<Cell>>(N, vector<Cell>(M));
    total_trash = 0;

    cout << "Введите план комнаты (положительные — мусор, 0 — препятствие, отрицательные — вредные вещества):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> room[i][j].trash;
            if (room[i][j].trash == 0) {
                room[i][j].is_obstacle = true;
            } else if (room[i][j].trash < 0) {
                room[i][j].is_hazard = true;
            }
            if (room[i][j].trash > 0)
                total_trash += room[i][j].trash;
        }
    }

    print_matrix();

    int start_x, start_y, end_x, end_y;
    cout << "Введите начальные координаты (строка и столбец, начиная с 1): ";
    cin >> start_x >> start_y;
    cout << "Введите конечные координаты (строка и столбец, начиная с 1): ";
    cin >> end_x >> end_y;

    start_x--; start_y--;
    end_x--; end_y--;

    if (start_x < 0 || start_x >= N || start_y < 0 || start_y >= M ||
        end_x < 0 || end_x >= N || end_y < 0 || end_y >= M) {
        cout << "Ошибка: координаты вне диапазона\n";
        return 1;
    }
    if (room[start_x][start_y].is_obstacle) {
        cout << "Ошибка: стартовая клетка — препятствие\n";
        return 1;
    }
    if (room[end_x][end_y].is_obstacle) {
        cout << "Ошибка: конечная клетка — препятствие\n";
        return 1;
    }

    calculate_paths(start_x, start_y, end_x, end_y, false);

    if (all_paths[end_x][end_y] == 0) {
        cout << "Пути без захода в вредные клетки отсутствуют, считаем с разрешением заходить в них...\n\n";
        calculate_paths(start_x, start_y, end_x, end_y, true);
    }

    int collected_trash = trash_dp[end_x][end_y];

    cout << "Общее количество путей от начала до конца: " << all_paths[end_x][end_y] << "\n";

    if (collected_trash == total_trash && dp[end_x][end_y] > 0) {
    cout << "Количество путей, на которых собран весь мусор: " << dp[end_x][end_y] << "\n";
    if (min_path_dp[end_x][end_y] != INT_MAX && max_path_dp[end_x][end_y] != -1) {
        if (min_path_dp[end_x][end_y] == max_path_dp[end_x][end_y]) {
            cout << "Длина пути с полным сбором мусора: " << min_path_dp[end_x][end_y] << " шагов\n";
        } else {
            cout << "Минимальная длина пути с полным сбором мусора: " << min_path_dp[end_x][end_y] << " шагов\n";
            cout << "Максимальная длина пути с полным сбором мусора: " << max_path_dp[end_x][end_y] << " шагов\n";
        }
    }
} else {
    cout << "Количество путей, на которых собран весь мусор: 0\n";
    cout << "Пути с полным сбором мусора не найдены\n";
}

    return 0;
}
