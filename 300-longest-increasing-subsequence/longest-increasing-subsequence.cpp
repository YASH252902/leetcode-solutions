class Solution {
public:
    int solveUsingMemo(vector<int>& nums, int prev, int curr, vector<vector<int>>& dp) {
        // base case 
        if (curr >= nums.size()) {
            return 0;
        }
        if(dp[prev + 1][curr] != -1) {
            return dp[prev + 1][curr];
        }
        
        int includeAns = 0;
        // Correction: Compare nums[curr] with nums[prev], not nums[prev+1]
        if (prev == -1 || nums[curr] > nums[prev]) {
            includeAns = 1 + solveUsingMemo(nums, curr, curr + 1, dp);
        }
        
        int excludeAns = solveUsingMemo(nums, prev, curr + 1, dp);
        int finalAns = max(includeAns, excludeAns);
        dp[prev + 1][curr] = finalAns;
        return finalAns;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        int curr = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = solveUsingMemo(nums, prev, curr, dp);
        return ans;
    }
};