#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool is_valid_encryption(const string &encrypted, const string &original) {
    unordered_map<char, char> forward_map, reverse_map;

    for (size_t i = 0; i < original.size(); ++i) {
        char o = original[i];
        char e = encrypted[i];

        if (forward_map.count(o) && forward_map[o] != e) return false;
        if (reverse_map.count(e) && reverse_map[e] != o) return false;

        forward_map[o] = e;
        reverse_map[e] = o;
    }

    if (forward_map.size() != reverse_map.size()) return false;

    return true;
}

int main() {
    string encrypted, original;
    cin >> encrypted >> original;

    if (is_valid_encryption(encrypted, original)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}