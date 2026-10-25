// let the function f(x) be unimodal
// and defined on the interval [left, right]

int left = ... , right = ... ;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (f(mid) < f(mid + 1)) {
        right = mid;
    } else {
        left = mid + 1;
    }
}
int ans = f(left); // local min
