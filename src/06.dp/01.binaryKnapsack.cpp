#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> items(n);
	for (int i = 0; i < n; ++i) {
		cin >> items[i].first >> items[i].second;
	}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> trace(n + 1, vector<int>(m + 1, -1));

	for (int i = 1; i <= n; ++i) {
		const auto& [w, v] = items[i - 1];

		for (int j = 1; j <= m; ++j) {
			if (0 <= j - w) {
				int dont_take = dp[i - 1][j];
				int take = dp[i - 1][j - w] + v;

				if (dont_take > take) {
					dp[i][j] = dont_take;
					trace[i][j] = j;
				}
				else {
					dp[i][j] = take;
					trace[i][j] = j - w;
				}
			}
			else {
				dp[i][j] = dp[i - 1][j];
				trace[i][j] = j;
			}
		}
	}

	cout << dp[n][m] << '\n';
	int curr_j = m, prev_j = trace[n][curr_j];
	for (int i = n; i != 0; --i) {
		if (curr_j != prev_j) {
			cout << i << ' ';
		}
		curr_j = prev_j;
		prev_j = trace[i - 1][prev_j];

		if (prev_j == -1) {
			break;
		}
	}
}
