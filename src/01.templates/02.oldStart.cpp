// C++17 or newer

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <typename T>
using vec = vector<T>;

void ppi(bool& first) {
    if (!first) { cout << ", "; }
    first = false;
}

template <typename T>
void printCont(const T& x) {
    cout << '[';
    bool first = true;
    for (const auto& e : x) {
        ppi(first), cout << e;
    }
    cout << "]\n";
}

template <typename T>
void printPair(const T& x) {
    cout << '[';
    bool first = true;
    for (const auto& [ff, ss] : x) {
        ppi(first), cout << '(' << ff << ", " << ss << ')';
    }
    cout << "]\n";
}

template <typename T>
void showgrid(const T& x) {
    for (int i = 0; i < x.size(); ++i) {
        cout << i << ' ', printCont(x[i]);
    }
}

#ifdef LOCAL
    #define debug(x) do { cout << #x << " = ", \
    cout << x << '\n'; } while(0)
#else
    #define debug(x) ((void)0)
    #define printCont(x) ((void)0)
    #define printPair(x) ((void)0)
    #define showgrid(x) ((void)0)
#endif // LOCAL

bool MULTITESTS = false;
void solve() {
    // ...
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    if (MULTITESTS) { cin >> t; }
    while (t--) { solve(); }
}
//
