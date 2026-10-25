int n, m; // assigned
vec<vec<char>> grid(n, vec<char>(m)); // assigned

// pack: (i, j)
pair<int, int> start_p{ ... , ... };
pair<int, int> end_p{ ... , ... };

const vec<pair<int, int>> directions{
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

queue<tuple<int, int, int>> q;
vec<vec<char>> visited(n, vec<char>(m, false));

// pack: (i, j, step)
q.push({ start_p.first, start_p.second, 0 });
visited[start_p.first][start_p.second] = true;

while (!q.empty()) {
    auto [i, j, step] = q.front();
    q.pop();

    if (i == end_p.first && j == end_p.second) {
        // ans here
        break;
    }

    for (const auto& [di, dj] : directions) {
        int ni = i + di;
        int nj = j + dj;
        if (0 <= ni && ni < n && 0 <= nj && nj < m) {
            if (!visited[ni][nj] && grid[ni][nj] != '#') {
                visited[ni][nj] = true;
                q.push({ ni, nj, step + 1 });
            }
        }
    }
}
