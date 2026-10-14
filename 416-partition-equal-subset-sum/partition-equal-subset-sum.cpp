class Solution {
public:
    bool solveMem(vector<int>& nums, int index, int target, vector<vector<int>>& dp) {
        // Base cases
        if (target == 0) return true;
        if (index >= nums.size() || target < 0) return false;

        // Return cached result if already computed
        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        bool includeAns = solveMem(nums, index + 1, target - nums[index], dp);
        bool excludeAns = solveMem(nums, index + 1, target, dp);

        return dp[index][target] = (includeAns || excludeAns);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        // Fixed: use '<' instead of '<='
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }

        // Fixed: if total sum is odd, we cannot partition into two equal subsets
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        int n = nums.size();
        
        // DP table initialized with -1
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solveMem(nums, 0, target, dp);
    }
};