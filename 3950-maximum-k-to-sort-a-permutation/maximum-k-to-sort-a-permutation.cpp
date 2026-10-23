class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            // Check if the element is not in its sorted position
            if (nums[i] != i) {
                ans &= nums[i];
            }
        }
        
        // If the array was already sorted, ans remains -1, so we return 0.
        return max(ans, 0);
    }
};