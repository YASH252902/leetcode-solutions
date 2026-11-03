class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        
        // Check every possible starting point
        for (int i = 0; i < n; i++) {
            unordered_set<int> distinctEvens;
            unordered_set<int> distinctOdds;
            
            // Expand the subarray ending at j
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    distinctEvens.insert(nums[j]);
                } else {
                    distinctOdds.insert(nums[j]);
                }
                
                // If distinct counts match, update maxLength
                if (distinctEvens.size() == distinctOdds.size()) {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
        
        return maxLength;
    }
};