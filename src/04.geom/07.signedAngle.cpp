double signed_angle(
    const Point& p, const Point& q,
    const Point& b, const Point& d
) {
    double cr = cross_product(p, q, b, d);
    double dt = dot_product(p, q, b, d);
    return atan2(cr, dt);
}