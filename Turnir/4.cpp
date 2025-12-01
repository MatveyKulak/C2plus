#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <numeric>
using namespace std;

struct Term {
    int a, b;
    Term(int a = 0, int b = 0) : a(a), b(b) {}
    Term operator+(const Term& rhs) const {
        return Term(a + rhs.a, b + rhs.b);
    }
    Term operator-(const Term& rhs) const {
        return Term(a - rhs.a, b - rhs.b);
    }
    Term operator*(const Term& rhs) const {
        if (a != 0 && rhs.a != 0) throw invalid_argument("nonlinear");
        return Term(a * rhs.b + b * rhs.a, b * rhs.b);
    }
    Term operator/(const Term& rhs) const {
        if (rhs.a != 0) throw invalid_argument("division with variable");
        if (rhs.b == 0) throw runtime_error("division by zero");
        return Term(a / rhs.b, b / rhs.b);
    }
};

int main() {
    string line, token;
    getline(cin, line);
    stringstream ss(line);
    stack<Term> st;
    try {
        while (ss >> token) {
            if (token == "X") {
                st.push(Term(1, 0));
            } else if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
                st.push(Term(0, stoi(token)));
            } else {
                Term b = st.top(); st.pop();
                Term a = st.top(); st.pop();
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);
            }
        }
    } catch (...) {
        cout << "MULTIPLE\n";
        return 0;
    }

    Term f = st.top();
    if (f.a == 0) {
        if (f.b == 0) cout << "MULTIPLE\n";
        else cout << "NONE\n";
    } else {
        int num = -f.b, denom = f.a;
        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
        int g = gcd(abs(num), denom);
        num /= g;
        denom /= g;
        cout << "X = " << num << "/" << denom << '\n';
    }

    return 0;
}
