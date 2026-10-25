int n, m; // assigned
using edge = pair<ll, int>;

// pack: [ u: (w, v) ]
// one component! no cycle!
vector<vector<edge>> graph(n);

vector<char> visited(n, false);
priority_queue<edge, vector<edge>, greater<>> pq;

int start_v = 0;
pq.push({ 0, start_v });

ll total_cost = 0;
while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();

    if (visited[v]) {
        continue;
    }

    visited[v] = true;
    total_cost += d;

    for (const auto& e : graph[v]) {
        pq.push(e);
    }
}
