class Solution {
public:
    int solveUsingMemo(int amount, vector<int>& coins , vector<int>& dp) {
        // Base case 1: If amount becomes 0, 0 coins are needed
        if (amount == 0) {
            return 0;
        }
        // Base case 2: If amount becomes negative, it's an invalid path
        if (amount < 0) {
            return INT_MAX - 1;
        }
        if(dp[amount] != -1){
            return dp[amount] ;
        }
        
        int minAns = INT_MAX - 1;
        
        // Try picking every coin available
        for (int i = 0; i < coins.size(); i++) {
            // Recursively solve for the remaining amount
            int ans = solveUsingMemo(amount - coins[i], coins , dp);
            
            // If the recursive call returned a valid answer, update our minimum
            if (ans != INT_MAX - 1) {
                minAns = min(minAns, 1 + ans);
            }
        }

        dp[amount] = minAns ;
        return minAns;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = amount ;
        vector<int> dp(n+100 , -1) ;
        int ans = solveUsingMemo(amount, coins , dp);
        
        if (ans >= INT_MAX - 1) {
            return -1;
        }
        return ans;
    }
};