vector<vector<int>> graph; // assigned
vector<int> colored; // assigned (n, 0)
vector<int> parent; // assigned (n, -1)

bool dfs(int v) {
	colored[v] = 1;
	for (int nv : graph[v]) {
		if (colored[nv] == 0) {
			parent[nv] = v;
			if (dfs(nv)) {
				return true;
			}
		}
		else if (colored[nv] == 1) {
            		return true;
		}
	}
	colored[v] = 2;
	return false;
}