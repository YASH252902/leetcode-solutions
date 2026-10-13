class Solution {
public:
    int MOD = 1e9 + 7;
    int solveUsingMemo(int n, int k, int target, vector<vector<int>>& dp) {
        // base cases
        if (n < 0 || target < 0) {
            return 0;
        }
        if (n == 0 && target == 0) {
            return 1;
        }
        if (n == 0 && target != 0) {
            return 0;
        }
        if (n != 0 && target == 0) {
            return 0;
        }
        // State is based on n and target, not k
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        
        int ans = 0;
        for (int val = 1; val <= k; val++) {
            ans = (ans + solveUsingMemo(n - 1, k, target - val, dp)) % MOD;
        }
        dp[n][target] = ans;
        return ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int ans = solveUsingMemo(n, k, target, dp);
        return ans;
    }
};