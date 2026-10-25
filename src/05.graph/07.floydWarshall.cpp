const int neutral = 1e6; // choose carefully
vec<vec<int>> dp(n, vec<int>(n, neutral));
dp[0][0] = 0; // start assigned

for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
}
