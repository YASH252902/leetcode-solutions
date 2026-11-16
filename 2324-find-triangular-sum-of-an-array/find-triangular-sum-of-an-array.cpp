class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        // 1. The while loop wraps around ALL the work.
        // As long as we have more than 1 element, we keep doing rounds.
        while (nums.size() > 1) {
            
            // 2. Create the new smaller array for this specific round
            vector<int> newNums(nums.size() - 1);
            
            // 3. Fill the new array
            for (int i = 0; i < newNums.size(); i++) {
                newNums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            
            // 4. THIS IS THE CRUCIAL STEP! 
            // Overwrite 'nums' with 'newNums' so the next round uses the smaller array.
            nums = newNums;
        }
        
        // 5. Once the while loop is completely finished, nums.size() will be 1.
        // We just return that single remaining element.
        return nums[0];
    }
};