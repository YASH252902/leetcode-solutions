class Solution {
public:
    int solveUsingMemo(vector<int>& nums, int prev, int curr,
                       vector<vector<int>>& dp) {
        // base case
        if (curr >= nums.size()) {
            return 0;
        }
        if (dp[prev + 1][curr] != -1) {
            return dp[prev + 1][curr];
        }

        int includeAns = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            includeAns = 1 + solveUsingMemo(nums, curr, curr + 1, dp);
        }

        int excludeAns = solveUsingMemo(nums, prev, curr + 1, dp);
        int finalAns = max(includeAns, excludeAns);
        dp[prev + 1][curr] = finalAns;
        return finalAns;
    }
    
    int solveUsingTabulation(vector<int>& nums , int prev_param , int curr_param) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // Fix 1: curr MUST be the outer loop so prev can start from curr-1
        for (int curr = n-1 ; curr >= 0 ; curr -- ){
            for (int prev = curr-1 ; prev >= -1 ; prev--){
                int includeAns = 0;
                
                if (prev == -1 || nums[curr] > nums[prev]) {
                    // Fix 2: Next state has prev = curr, so shifted index is curr + 1
                    includeAns = 1 + dp[curr + 1][curr + 1];
                }

                // Fix 3: Next state has prev = prev, so shifted index is prev + 1
                int excludeAns = dp[prev + 1][curr + 1];
                
                int finalAns = max(includeAns, excludeAns);
                dp[prev + 1][curr] = finalAns;
            }
        }
        
        // Fix 4: To return the answer for prev = -1 and curr = 0, shift prev by +1
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        int curr = 0;
        int ans = solveUsingTabulation(nums , prev , curr ) ;
        return ans ;
    }
};