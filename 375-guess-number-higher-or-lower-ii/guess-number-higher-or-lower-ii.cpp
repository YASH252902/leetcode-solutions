class Solution {
public:
    int solveUsingTabulation(int n) {
        // Step 1: Initialize DP with size (n + 2) so i + 1 never goes out of bounds when i == n
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Step 2: Loop through changing parameters
        for (int start = n; start >= 1; start--) {
            for (int end = 1; end <= n; end++) {
                // Base case: both start > end and start == end must stay 0
                if (start >= end) {
                    continue;
                } else {
                    int ans = INT_MAX;
                    for (int i = start; i <= end; i++) {
                        ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                    }
                    dp[start][end] = ans;
                }
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        return solveUsingTabulation(n);
    }
};