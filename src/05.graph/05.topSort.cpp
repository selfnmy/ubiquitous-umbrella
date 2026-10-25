vec<vec<int>> graph; // assigned
vec<char> visited; // assigned (n, false)
vec<int> order; // empty

void dfs(int v) {
    visited[v] = true;
    for (int nv : graph[v]) {
        if (!visited[nv]) {
            dfs(nv);
        }
    }
    order.push_back(v);
}