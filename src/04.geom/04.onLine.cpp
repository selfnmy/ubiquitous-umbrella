bool on_line(
    const Point& p, const Point& q,
    const Point& k
) {
    // if (p.x == q.x && p.y == q.y) { return false; }
    return abs(signed_pos(p, q, k)) <= EPS;
}
