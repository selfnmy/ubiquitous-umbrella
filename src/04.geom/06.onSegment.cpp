bool on_segment(
    const Point& p, const Point& q,
    const Point& k
) {
    return (
        on_line(p, q, k) &&
        min(p.x, q.x) <= k.x && k.x <= max(p.x, q.x) &&
        min(p.y, q.y) <= k.y && k.y <= max(p.y, q.y)
    );
}