// let the function f(x) be monotonic
// and defined on the interval [left, right]

int left = ... , right = ... , ans = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    int cost = f(mid);

    if (cost <= target) {
        ans = mid;
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
debug(ans); // achievable max 