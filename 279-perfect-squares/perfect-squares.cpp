class Solution {
public:
    int solveUsingTabulation(int n, vector<int>& squares) {
        int m = squares.size();
        // Initialize with 1e9 (handles the index >= m base case automatically)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));

        // Base case: target == 0 needs 0 squares
        for (int index = 0; index <= m; index++) {
            dp[index][0] = 0;
        }

        // Fill table bottom-up
        for (int index = m - 1; index >= 0; index--) {
            for (int target = 1; target <= n; target++) {
                int includeAns = 1e9;
                if (squares[index] <= target) {
                    includeAns = 1 + dp[index][target - squares[index]];
                }

                int excludeAns = dp[index + 1][target];

                dp[index][target] = min(includeAns, excludeAns);
            }
        }

        return dp[0][n];
    }

    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        return solveUsingTabulation(n, squares);
    }
};