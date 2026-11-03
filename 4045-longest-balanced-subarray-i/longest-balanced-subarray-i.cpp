class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        
        // Since nums[i] <= 10^5, a fixed array acts as a perfect O(1) tracker.
        // We use 100005 to safely cover the maximum possible value.
        vector<int> seenVersion(100005, 0);
        int version = 0;
        
        for (int i = 0; i < n; i++) {
            version++; // Increment version to "reset" tracking for the new window
            int distinctEvens = 0;
            int distinctOdds = 0;
            
            for (int j = i; j < n; j++) {
                int val = nums[j];
                
                // If the value hasn't been seen in the CURRENT version (i.e., this specific outer loop)
                if (seenVersion[val] != version) {
                    seenVersion[val] = version;
                    
                    if (val % 2 == 0) {
                        distinctEvens++;
                    } else {
                        distinctOdds++;
                    }
                }
                
                // Update max length if distinct counts are perfectly balanced
                if (distinctEvens == distinctOdds) {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
        
        return maxLength;
    }
};