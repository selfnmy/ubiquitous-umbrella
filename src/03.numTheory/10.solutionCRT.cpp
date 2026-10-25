#include <bits/stdc++.h>
using namespace std;
using ll = long long;

tuple<ll, ll, ll> xgcd(ll a, ll b) {
	if (b == 0) {
		return { a, 1 ,0 };
	}
	auto [g, x, y] = xgcd(b, a % b);
	return { g, y, x - a / b * y };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<ll> r(n), m(n);
	for (int i = 0; i < n; ++i) {
		cin >> r[i] >> m[i];
	}

	ll M = 1;
	for (int i = 0; i < n; ++i) {
		M *= m[i];
	}

	/*
		x = sum[i = 1, i -> k](
			b[i] * M_i * M_i^(-1)(mod m[i]) (mod M)
		)

		(1) M = prod[i = 1, i -> k]( m[i] )
		(2) M_i = M / m[i]
		(3) M_i * M_i^(-1) = 1 (mod M)
	*/

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		ll m_i = M / m[i];

		auto [g, x, y] = xgcd(m_i, m[i]);
		x = (x % m[i] + m[i]) % m[i]; // mod_fix(v)

		res += r[i] * m_i * x;
		res %= M;
	}

	// res is ans
	cout << res;
}
