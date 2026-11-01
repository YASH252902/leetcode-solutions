class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Sort to easily find and fix the minimum element at index 0
        sort(nums.begin(), nums.end());
        
        int start = 0;
        int end = nums.size() - 1;
        int moves = 0;
        
        // Keep start fixed at the minimum element
        // Move the end pointer backwards to calculate differences
        while(start < end) {
            moves += (nums[end] - nums[start]);
            end--;
        }
        
        return moves;
    }
};