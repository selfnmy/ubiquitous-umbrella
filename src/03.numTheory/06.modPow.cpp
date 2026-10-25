ll mod_pow(ll base, int exp, ll mod) {
    if (mod == 1) { return 0; }
    base %= mod;

    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
