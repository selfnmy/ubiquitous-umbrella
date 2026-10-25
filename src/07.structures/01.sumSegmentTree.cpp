#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <typename T>
using vec = vector<T>;

struct Node {
	ll v;
	// push
	ll wv;
	bool wait;
};

Node combain(Node lhs, Node rhs) {
	return { lhs.v + rhs.v, 0, false };
}

// globals
int n, m;
vec<Node> t;

Node common{ 0, 0, false };
Node neutral{ 0, 0, false };

void build(int x, int l, int r) {
	if (r - l == 1) {
		t[x] = (l < n ? common : neutral);
		return;
	}
	int m = (l + r) / 2;
	build(2 * x, l, m);
	build(2 * x + 1, m, r);
	t[x] = combain(t[2 * x], t[2 * x + 1]);
}

void push(int x, int l, int r) {
	if (!t[x].wait) {
		return;
	}
	if (r - l == 1) {
		t[x].wait = false;
		t[x].wv = 0;
		return;
	}
	t[2 * x].v += t[x].wv;
	t[2 * x + 1].v += t[x].wv;

	t[2 * x].wv += t[x].wv;
	t[2 * x + 1].wv += t[x].wv;

	t[2 * x].wait = true; // !!
	t[2 * x + 1].wait = true; // !!
	t[x].wait = false;
	t[x].wv = 0;
}

void mass_oper(
    int sl, int sr, ll v,
    int x, int l, int r
) {
	push(x, l, r);
	if (sl <= l && r <= sr) {
		// self
		t[x].v += v;
		// other
		t[x].wait = true;
		t[x].wv = v;
		push(x, l, r);
		return;
	}
	if (sr <= l || sl >= r) {
		return;
	}
	int m = (l + r) / 2;
	mass_oper(sl, sr, v, 2 * x, l, m);
	mass_oper(sl, sr, v, 2 * x + 1, m, r);
	t[x] = combain(t[2 * x], t[2 * x + 1]);
}

Node index_find(int i, int x, int l, int r) {
	push(x, l, r);
	if (r - l == 1) {
		return t[x];
	}
	int m = (l + r) / 2;
	if (i < m) {
		return index_find(i, 2 * x, l, m);
	}
	else {
		return index_find(i, 2 * x + 1, m, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	int sz = 1;
	while (sz <= n) {
		sz <<= 1;
	}
	t.resize(2 * sz); // !!

	for (int call = 0; call < m; ++call) {
		int mode;
		cin >> mode;

		if (mode == 1) {
			int l, r;
			ll v; // !!
			cin >> l >> r >> v;
			mass_oper(l, r, v, 1, 0, sz);
		}
		else {
			int i;
			cin >> i;
			auto node = index_find(i, 1, 0, sz);
			cout << node.v << '\n';
		}
	}
}
