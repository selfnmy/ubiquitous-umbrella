int n, m; // assigned
using edge = pair<ll, int>;

// pack: [ u: (w, v) ]
vec<vec<edge>> graph(n); // assigned

const ll neutral = 1e18;
vec<ll> dist(n, neutral);

int start_v = 0;
priority_queue<edge, vec<edge>, greater<>> pq;

pq.push({ 0, start_v });
dist[start_v] = 0;

while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();

    if (dist[v] < d) {
        continue;
    }

    for (const auto& [w, nv] : graph[v]) {
        if (dist[nv] > dist[v] + w) {
            dist[nv] = dist[v] + w;
            pq.push({ dist[nv], nv });
        }
    }
}
