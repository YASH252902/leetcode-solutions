class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& memo, int& max_len) {
        // Base case: out of bounds
        if (i == nums1.size() || j == nums2.size()) {
            return 0;
        }
        
        // Return precomputed result
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        // Explore branching paths to ensure all combinations of (i, j) are visited
        solve(nums1, nums2, i + 1, j, memo, max_len);
        solve(nums1, nums2, i, j + 1, memo, max_len);
        
        int match = 0;
        
        // If current elements match, the streak continues from the next indices
        if (nums1[i] == nums2[j]) {
            match = 1 + solve(nums1, nums2, i + 1, j + 1, memo, max_len);
        }
        
        // Update the global maximum length found so far
        max_len = max(max_len, match);
        
        // Save to memo and return the streak starting strictly at (i, j)
        return memo[i][j] = match;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int max_len = 0;
        
        // Initialize 2D memoization table with -1
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        solve(nums1, nums2, 0, 0, memo, max_len);
        
        return max_len;
    }
};