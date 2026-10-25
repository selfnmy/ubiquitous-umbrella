bool is_convex(const vec<Point>& a) {
    const int n = a.size();
    // if (n < 3) { return false; }

    int sign = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        int k = (i + 2) % n;

        double cr = cross_product(a[i], a[j], a[j], a[k]);
        if (abs(cr) < EPS) { continue; } // break

        int s = (cr > 0 ? 1 : -1);
        if (sign == 0) { sign = s; }
        if (sign != s) { return false; }
    }
    return true; // sign != 0
}