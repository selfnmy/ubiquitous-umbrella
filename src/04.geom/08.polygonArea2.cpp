struct PointInt {
    ll x, y;
};

ll cross_product(
    const PointInt& p, const PointInt& q,
    const PointInt& b, const PointInt& d
) {
    PointInt v1{ q.x - p.x, q.y - p.y };
    PointInt v2{ d.x - b.x, d.y - b.y };
    return v1.x * v2.y - v2.x * v1.y;
}

ll polygon_area2(const vec<PointInt>& a) {
    const int n = a.size();
    // if (n == 0) { return 0; }
    ll area = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += cross_product(a[0], a[i], a[0], a[j]);
    }
    return abs(area);
}
