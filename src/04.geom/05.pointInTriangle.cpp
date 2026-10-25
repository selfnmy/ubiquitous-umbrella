bool point_in_triangle(
    const Point& a, const Point& b, const Point& c,
    const Point& k
) {
    // if (on_line(a, b, c)) { return false; }
    double c1 = cross_product(a, b, a, k);
    double c2 = cross_product(b, c, b, k);
    double c3 = cross_product(c, a, c, k);

    return (
        (c1 >= -EPS && c2 >= -EPS && c3 >= -EPS) ||
        (c1 <=  EPS && c2 <=  EPS && c3 <=  EPS)
    );
}