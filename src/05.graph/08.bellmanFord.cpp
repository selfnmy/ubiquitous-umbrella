int n, m; // assigned
vec<vec<int>> graph(n); // assigned

const ll neutral = 2e18;
vec<ll> dp(n, neutral);
dp[s] = 0;

set<int> updates;
vec<int> parent(n, -1);

for (int step = 1; step <= n; ++step) {
    int last_u = -1;
    for (int u = 0; u < n; ++u) {
        for (const auto& [v, w] : graph[u]) {
            if (dp[u] != neutral && dp[v] > dp[u] + w) {
                dp[v] = max(dp[u] + w, -neutral);
                parent[v] = u;
                last_u = u;
                // negative-weight cycle step
                if (step == n) {
                    updates.insert(u);
                }
            }
        }
    }
    if (last_u == -1) {
        break;
    }
}

// repr of 1 negative-weight cycle
if (!updates.empty()) {
    int y = *updates.begin();

    for (int i = 0; i < n; ++i) {
        y = parent[y];
    }

    vec<int> path;
    int curr = y;
    do {
        path.push_back(curr);
        curr = parent[curr];
    } while (curr != y);

    reverse(path.begin(), path.end());
    // 'path' vec is ans
}
