class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum = INT_MAX;
        int n = nums.size();
        
        // i represents the start index of the subarray
        for (int i = 0; i < n; ++i) {
            int currentSum = 0;
            
            // j represents the end index of the subarray
            for (int j = i; j < n; ++j) {
                currentSum += nums[j];
                int length = j - i + 1;
                
                // If the length is within bounds and the sum is positive, check if it's the minimum
                if (length >= l && length <= r && currentSum > 0) {
                    minSum = min(minSum, currentSum);
                }
            }
        }
        
        // If minSum wasn't updated, no valid subarray was found
        return minSum == INT_MAX ? -1 : minSum;
    }
};