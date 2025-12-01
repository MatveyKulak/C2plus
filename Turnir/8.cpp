#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <stack>
#include <cctype>

using namespace std;

const long long MOD = 1e9 + 9;

struct Matrix {
    int rows, cols;
    vector<vector<long long>> data;

    Matrix(int r, int c) : rows(r), cols(c) {
        data.assign(r, vector<long long>(c, 0));
    }
};

Matrix matrix_add(const Matrix &a, const Matrix &b) {
    Matrix result(a.rows, a.cols);
    for (int i = 0; i < a.rows; ++i) {
        for (int j = 0; j < a.cols; ++j) {
            result.data[i][j] = (a.data[i][j] + b.data[i][j]) % MOD;
        }
    }
    return result;
}

Matrix matrix_subtract(const Matrix &a, const Matrix &b) {
    Matrix result(a.rows, a.cols);
    for (int i = 0; i < a.rows; ++i) {
        for (int j = 0; j < a.cols; ++j) {
            result.data[i][j] = (a.data[i][j] - b.data[i][j] + MOD) % MOD;
        }
    }
    return result;
}

Matrix matrix_multiply(const Matrix &a, const Matrix &b) {
    Matrix result(a.rows, b.cols);
    for (int i = 0; i < a.rows; ++i) {
        for (int j = 0; j < b.cols; ++j) {
            for (int k = 0; k < a.cols; ++k) {
                result.data[i][j] = (result.data[i][j] + a.data[i][k] * b.data[k][j]) % MOD;
            }
        }
    }
    return result;
}

Matrix evaluate_expression(const string &expr, unordered_map<char, Matrix> &matrices) {
    stack<Matrix> values;
    stack<char> ops;

    auto apply_operation = [&]() {
        char op = ops.top();
        ops.pop();
        Matrix b = values.top();
        values.pop();
        Matrix a = values.top();
        values.pop();

        if (op == '+') values.push(matrix_add(a, b));
        if (op == '-') values.push(matrix_subtract(a, b));
        if (op == '*') values.push(matrix_multiply(a, b));
    };

    for (size_t i = 0; i < expr.size(); ++i) {
        char ch = expr[i];
        if (isalpha(ch)) {
            values.push(matrices[ch]);
        } else if (ch == '(') {
            ops.push(ch);
        } else if (ch == ')') {
            while (!ops.empty() && ops.top() != '(') {
                apply_operation();
            }
            ops.pop();
        } else if (ch == '+' || ch == '-' || ch == '*') {
            while (!ops.empty() && ops.top() != '(' &&
                   ((ch == '+' || ch == '-') || (ch == '*' && ops.top() == '*'))) {
                apply_operation();
            }
            ops.push(ch);
        }
    }

    while (!ops.empty()) {
        apply_operation();
    }

    return values.top();
}

int main() {
    int t;
    cin >> t;

    unordered_map<char, Matrix> matrices;

    for (int i = 0; i < t; ++i) {
        char name;
        int rows, cols;
        cin >> name >> rows >> cols;

        Matrix mat(rows, cols);
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                cin >> mat.data[r][c];
            }
        }

        matrices[name] = mat;
    }

    string expr;
    cin >> ws;
    getline(cin, expr);

    Matrix result = evaluate_expression(expr, matrices);

    for (const auto &row : result.data) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (i > 0) cout << " ";
            cout << row[i];
        }
        cout << endl;
    }

    return 0;
}