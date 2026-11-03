class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = 0;
        int sum = 0;
        int n = nums.size();
        
        // Find the maximum element and the sum of the array
        for (int num : nums) {
            max_val = max(max_val, num);
            sum += num;
        }
        
        // Calculate the difference between the target state and current state
        return (max_val * n) - sum;
    }
};