class Solution {
public:
    int solveMemo(int index, int target, vector<int>& squares, vector<vector<int>>& dp) {
        if (target == 0) {
            return 0;
        }
        if (index >= squares.size()) {
            return 1e9;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        // Include: stay at 'index' to allow reusing the same square
        int includeAns = 1e9;
        if (squares[index] <= target) {
            includeAns = 1 + solveMemo(index, target - squares[index], squares, dp);
        }

        // Exclude: move to the next square
        int excludeAns = solveMemo(index + 1, target, squares, dp);

        int finalAns = min(includeAns, excludeAns);
        dp[index][target] = finalAns;
        return finalAns;
    }

    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        int index = 0;
        int target = n;
        vector<vector<int>> dp(squares.size(), vector<int>(n + 1, -1));
        int ans = solveMemo(index, target, squares, dp);
        return ans;
    }
};