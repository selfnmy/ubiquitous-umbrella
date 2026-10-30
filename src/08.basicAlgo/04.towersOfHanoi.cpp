// for example

#include <bits/stdc++.h>
using namespace std;

// globals
int n;
string s;
string output;

void moveLayer(int from, int to) {
    output += char('0' + from);
    output += ' ';
    output += char('0' + to);
    output += '\n';
}

void hanoi(int k, int from, int to, int aux) {
    if (k == 0) return;
    hanoi(k - 1, from, aux, to);
    moveLayer(from, to);
    hanoi(k - 1, aux, to, from);
}

void separate(int k, int from) {
    if (k == 0) return;

    int idx = n - k;
    int target = (s[idx] == '0' ? 2 : 3);

    if (target == from) {
        separate(k - 1, from);
    } else {
        int to  = target;
        int aux = 6 - from - to;

        // 1. Убираем верхние k-1 слоев на aux, используя to.
        hanoi(k - 1, from, aux, to);

        // 2. Переносим нижний слой блока на его целевую тарелку.
        moveLayer(from, to);

        // 3. Теперь k-1 слоёв лежат на aux — рекурсивно их разбираем.
        separate(k - 1, aux);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> s;

    output.reserve(1 << n);
    separate(n, 1);

    cout << output;
    return 0;
}
