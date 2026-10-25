bool in_polygon(
    const vec<Point>& a,
    const Point& k
) {
    const int n = a.size();
    // if (n < 3) { return false; }

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        if (on_segment(a[i], a[j], k)) {
            return true;
        }
    }

    double phi = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        phi += signed_angle(k, a[i], k, a[j]);
    }

    phi = abs(phi);
    return abs(phi - 2 * PI) < EPS;
}