// for example

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 20;  // 2^20 > 2*10^5; for N up to 10^6 use 21-22

int up[LOG][MAXN];  // up[i][v] — 2^i-th ancestor of vertex v
int depth[MAXN];
vector<int> adj[MAXN];
int n;

// ---------- Build the table ----------
void build(int root) {
    up[0][root] = root;  // the root is its own ancestor
    depth[root] = 0;

    vector<char> vis(n + 1, false);
    vis[root] = true;

    stack<int> st;
    st.push(root);
    while (!st.empty()) {
        int v = st.top(); st.pop();
        for (int to : adj[v]) {
            if (vis[to]) continue;
            vis[to] = true;
            up[0][to] = v;
            depth[to] = depth[v] + 1;
            st.push(to);
        }
    }

    // Fill the jump table
    for (int i = 1; i < LOG; i++)
        for (int v = 1; v <= n; v++)
            up[i][v] = up[i - 1][up[i - 1][v]];
}

// ---------- k-th ancestor (k steps up) ----------
int kth_ancestor(int v, int k) {
    for (int i = 0; i < LOG; i++)
        if (k & (1 << i))
            v = up[i][v];
    return v;
}

// ---------- LCA (lowest common ancestor) ----------
int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = kth_ancestor(a, depth[a] - depth[b]);  // equalize depths
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }
    return up[0][a];
}

// ---------- Distance between two vertices ----------
int dist(int a, int b) {
    int c = lca(a, b);
    return depth[a] + depth[b] - 2 * depth[c];
}

// ---------- k-th vertex on the path a -> b (0-indexed) ----------
int kth_on_path(int a, int b, int k) {
    int c = lca(a, b);
    int da = depth[a] - depth[c];  // length from a to LCA
    if (k <= da) return kth_ancestor(a, k);
    int db = depth[b] - depth[c];  // length from LCA to b
    return kth_ancestor(b, da + db - k);
}

// ---------- Usage example ----------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    build(1); // start 1

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << "LCA(" << a << ", " << b << ") = " << lca(a, b);
        cout << ", dist = " << dist(a, b) << '\n';
    }
}
