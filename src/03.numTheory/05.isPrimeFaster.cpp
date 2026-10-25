bool is_prime(ll num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (ll d = 5; d * d <= num; d += 6) {
        if (num % d == 0 || num % (d + 2) == 0) {
            return false;
        }
    }
    return true;
}
