class Solution {
public:
    int ansUsingRec(int n, vector<int>& dp) {
        // 1. Base case
        if (n == 0 || n == 1) {
            return n;
        }
        
        // 2. Check cache
        if (dp[n] != -1) {
            return dp[n];
        }
        
        // 3. Calculate, STORE in dp[n], and return
        dp[n] = ansUsingRec(n - 1, dp) + ansUsingRec(n - 2, dp);
        return dp[n];
    }
    
    int fib(int n) {
        vector<int> dp(n + 1, -1); // Semicolon added here
        return ansUsingRec(n, dp);
    }
};