double signed_pos(
    const Point& p, const Point& q,
    const Point& k
) {
    return cross_product(p, q, p, k);
}