map<ll, int> factorize(ll num) {
    map<ll, int> res;
    for (ll d = 2; d * d <= num; ++d){
        while (num % d == 0) {
            ++res[d];
            num /= d;
        }
    }
    if (num != 1) {
        ++res[num];
    }
    return res;
}
