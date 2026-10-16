// now we use 2D dp as the two parameters are changing so we use the 2D dp
// now e do the same question with the tabulation method
// step 1 inititalize dp
// step 2 we manage the base case if the base case is of zero we simply fill the
// dp with zeroes
//

class Solution {
public:
    int solveUsingMemo(int start, int end, vector<vector<int>>& dp) {
        if (start >= end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans, i + max(solveUsingMemo(start, i - 1, dp),
                                   solveUsingMemo(i + 1, end, dp)));
        }
        dp[start][end] = ans;
        return ans;
    }

    int solveUsingTabulation(int n) {
        // step 1 is to initialize dp
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // step 2 is changing the loop or flow of the parameters that are
        // changing the value in 2D dp the parameters are start and end so we
        // make the loop of start and end
        for (int start = n; start >= 1; start--) {
            for (int end = 1; end <= n; end++) {
                // now copy the content of memorization method but take care of
                // the base case if any violatiing
                if (start == end) {
                    continue;
                } else {
                    
                    int ans = INT_MAX;
                    for (int i = start; i <= end; i++) {
                        ans = min(ans, i + max(dp[start][i - 1] ,
                                               dp[i + 1][end]));
                    }
                    dp[start][end] = ans;
                }
            }
        }
        return dp[1][n] ;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = solveUsingMemo(1, n, dp);
        return ans;
    }
};