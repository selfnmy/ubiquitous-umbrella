double dot_product(
    const Point& p, const Point& q,
    const Point& b, const Point& d
) {
    Point v1{ q.x - p.x, q.y - p.y };
    Point v2{ d.x - b.x, d.y - b.y };
    return v1.x * v2.x + v1.y * v2.y;
}

double cross_product(
    const Point& p, const Point& q,
    const Point& b, const Point& d
) {
    Point v1{ q.x - p.x, q.y - p.y };
    Point v2{ d.x - b.x, d.y - b.y };
    return v1.x * v2.y - v2.x * v1.y;
}