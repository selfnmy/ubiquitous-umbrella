ll gcd(ll a, ll b) {
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// globals
const ll MOD = 1e9 + 7;

ll mod_fix(ll v) {
    return ((v % MOD) + MOD) % MOD;
}
