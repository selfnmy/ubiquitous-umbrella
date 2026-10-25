tuple<int, int, int> xgcd(int a, int b) {
    if (b == 0) {
        return { a, 1, 0 };
    }
    auto [g, x, y] = xgcd(b, a % b);
    return { g, y, x - (a / b) * y };
}

/*
    Inverse element modulo
    Condition of existence: gcd(a, MOD) = 1

    inv_a * a = 1 (mod MOD)
    python alt: inv_a = pow(a,-1, MOD)

    Inverse element modulo
    gcd(a, MOD) = 1, MOD - odd number
    inv_a = a^(MOD- 2) (mod MOD)

    Solutions of a linear equation: ax + by = c
    Condition of existence: c % gcd(a, b) = 0

    g, x, y = xgcd(a, b)
    k = c / g
    ax + by = c <=> kax + kby = kg

    * Base solution:
    x0 = k * x
    y0 = k * y

    * All solutions:
    { x_t = x0 + (b/g) * t
    { y_t = y0- (a/g) * t
    where t in Z
*/
