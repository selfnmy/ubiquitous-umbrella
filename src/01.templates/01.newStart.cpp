// C++20 or newer

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
void print(const T& x) {
    if constexpr (requires{ cout << x; }) {
        cout << x;
    } else if constexpr (requires{ tuple_size<T>::value; }) {
        cout << '(';
        bool first = true;
        apply([&](const auto&... es) { ((ppi(first), print(es)), ...); }, x);
        cout << ')';
    } else if constexpr (requires{ x.begin(), x.end(); }) {
        cout << '[';
        bool first = true;
        for (const auto& e : x) { ppi(first), print(e); }
        cout << ']';
    } else {
        cout << "[non-printable]";
    }
}

template <typename... Ts>
void print(const Ts&... xs) {
    bool first = true;
    ((ppi(first), print(xs)), ...);
}

template <typename T>
void showgrid(const T& x) {
    for (int i = 0; i < x.size(); ++i) {
        cout << i << ' ', print(x[i]), cout << '\n';
    }
}

#ifdef LOCAL
    #define debug(...) do { cout << #__VA_ARGS__ << " = ", \
    print(__VA_ARGS__), cout << '\n'; } while(0)
#else
    #define debug(...) ((void)0)
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
