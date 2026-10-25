#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
// using __uint128_t = unsigned long long;
template <typename T>
using vec = vector<T>;

ull mul_mod(ull a, ull b, ull mod) {
	if (mod == 1) {
		return 0;
	}
	return (ull)((__uint128_t)a * b % mod);
}

ull mod_pow(ull base, ull exp, ull mod) {
	if (mod == 1) {
		return 0;
	}
	base %= mod;
	ull res = 1;
	while (exp) {
		if (exp & 1) {
			res = mul_mod(res, base, mod);
		}
		base = mul_mod(base, base, mod);
		exp >>= 1;
	}
	return res;
}

const vec<ull> bases = {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37
};

bool miller_rabin_test(ull num) {
	if (num <= 1) {
		return false;
	}
	if (num <= 3) {
		return true;
	}
	if (num % 2 == 0) {
		return false;
	}

	ull d = num - 1;
	int s = 0;
	while (!(d & 1)) {
		d >>= 1;
		++s;
	}

	for (const auto& base : bases) {
		if (num <= base) {
			break;
		}
		ull x = mod_pow(base, d, num);
		if (x == 1 || x == num - 1) {
			continue;
		}
		bool flag = false;
		for (int j = 0; j < s; ++j) {
			x = mul_mod(x, x, num);
			if (x == 1) {
				return false;
			}
			if (x == num - 1) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
        ull v;
        cin >> v;
        bool flag = miller_rabin_test(v);
        cout << flag << ' ';
	}
}
