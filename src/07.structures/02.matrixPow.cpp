#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <typename T>
using vec = vector<T>;

// globals
constexpr ll MOD = 1e9 + 7;

vec<vec<ll>> matrix_multi(
	const vec<vec<ll>>& a,
	const vec<vec<ll>>& b
) {
	const int n1 = a.size(), m1 = a[0].size();
	const int n2 = b.size(), m2 = b[0].size();
	if (m1 != n2) { cout << "warn! [ m1 != n2 ]\n"; }

	vec<vec<ll>> c(n1, vec<ll>(m2, 0));
	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < m2; ++j) {
			for (int k = 0; k < n2; ++k) {
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	return c;
}

vec<vec<ll>> matrix_pow(
	vec<vec<ll>> base,
	ll exp
) {
	const int n = base[0].size(), m = base.size();
	if (n != m) { cout << "warn! [ n != m ]\n"; }

	vec<vec<ll>> res(n, vec<ll>(m, 0));
	for (int i = 0; i < n; ++i) {
		res[i][i] = 1;
	}

	while (exp) {
		if (exp % 2 == 1) {
			res = matrix_multi(res, base);
		}
		base = matrix_multi(base, base);
		exp /= 2;
	}
	return res;
}
