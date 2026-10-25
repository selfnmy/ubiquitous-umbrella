vec<vec<int>> graph; // assigned
vec<char> visited; // assigned (n, false)

void dfs(int v) {
    visited[v] = true;
    for (int nv : graph[v]) {
        if (!visited[nv]) {
            dfs(nv);
        }
    }
}
