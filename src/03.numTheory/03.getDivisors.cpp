set<ll> get_divisors(ll num) {
    set<ll> res{ 1, num };
    for (ll d = 1; d * d <= num; ++d) {
        if (num % d == 0) {
            res.insert(d);
            res.insert(num / d);
        }
    }
    return res;
}
