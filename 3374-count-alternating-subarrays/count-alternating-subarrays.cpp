class Solution {
public:
    long long solve(vector<int>& nums, int index, vector<long long>& dp) {
        // Base case: The first element forms 1 subarray (itself)
        if (index == 0) {
            return 1;
        }
        
        // If we've already calculated this index, return the stored value
        if (dp[index] != -1) {
            return dp[index];
        }
        
        long long result = 0;
        
        // If it alternates, extend the previous sequences + 1 for itself
        if (nums[index] != nums[index - 1]) {
            result = 1 + solve(nums, index - 1, dp);
        } 
        // If the pattern breaks, only the element itself is valid
        else {
            result = 1;
        }
        
        // Store the result in our memoization array before returning
        dp[index] = result;
        return result;
    }
    
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize the dp array here, sized to n, filled with -1
        vector<long long> dp(n, -1);
        
        long long totalSubarrays = 0;
        
        // We calculate the subarrays ending at EVERY index and sum them up
        for (int i = 0; i < n; i++) {
            totalSubarrays += solve(nums, i, dp);
        }
        
        return totalSubarrays;
    }
};