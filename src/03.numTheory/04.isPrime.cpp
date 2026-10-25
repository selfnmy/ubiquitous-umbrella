bool is_prime(ll num) {
    if (num < 2) {
        return false;
    }
    for (ll d = 2; d * d <= num; ++d) {
        if (num % d == 0) {
            return false;
        }
    }
    return true;
}
