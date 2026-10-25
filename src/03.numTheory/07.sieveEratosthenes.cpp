#include <bits/stdc++.h>
using namespace std;

int main() {
    const int LIM = 128;
    vector<char> flags(LIM + 1, true);
    flags[0] = flags[1] = false;

    for (int i = 2; i * i <= LIM; ++i) {
        if (flags[i]) {
            for (int j = i * i; j <= LIM; j += i) {
                flags[j] = false;
            }
        }
    }

    // 2 3 5 7 11 13 17 19 23...
    for (int i = 1; i <= LIM; ++i) {
        if (flags[i]) {
            cout << i << ' ';
        }
    }
    return 0;
}
