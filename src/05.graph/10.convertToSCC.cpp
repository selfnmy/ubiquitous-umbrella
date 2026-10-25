vec<vec<int>> graph, graph_t;
vec<bool> visited, visited_t;
vec<int> order, colored;
int curr_color = 0;

void order_dfs(int v) {
	visited[v] = true;
	for (int nv : graph[v]) {
		if (!visited[nv]) {
			order_dfs(nv);
		}
	}
	order.push_back(v);
}

void color_dfs(int v) {
	visited_t[v] = true;
	colored[v] = curr_color;
	for (int nv : graph_t[v]) {
		if (!visited_t[nv]) {
			color_dfs(nv);
		}
	}
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    graph_t.resize(n);
    visited.assign(n, false);
    visited_t.assign(n, false);
    colored.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph_t[v].push_back(u);
    }

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            order_dfs(v);
        }
    }
    reverse(order.begin(), order.end());
    for (int v : order) {
        if (!visited_t[v]) {
            color_dfs(v);
            ++curr_color;
        }
    }

    set<pair<int, int>> edges;
    for (int v = 0; v < n; ++v) {
        int c1 = colored[v];
        for (int nv : graph[v]) {
            int c2 = colored[nv];
            if (c1 != c2) {
                edges.insert({ c1, c2 });
            }
        }
    }

    const int k = curr_color;
    vec<vec<int>> new_graph(k);

    for (const auto& [c1, c2] : edges) {
        new_graph[c1].push_back(c2);
    }
    // new graph is ans
}
