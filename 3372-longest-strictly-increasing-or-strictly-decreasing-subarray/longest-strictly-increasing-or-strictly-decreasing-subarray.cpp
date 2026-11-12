class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // A single element is a sequence of length 1, so start at 1 instead of 0
        int increasingCount = 1; 
        int decreasingCount = 1;
        
        // We need a variable to store the overall maximum answer
        int maxAnswer = 1;
        
        int i = 0;
        int j = n - 1;
        
        // Condition changed to i < j so nums[i+1] doesn't go out of bounds at the end
        while(i < j) {
            if(nums[i] < nums[i+1]) {
                increasingCount++;
                decreasingCount = 1; // Reset the other streak!
            }
            else if(nums[i] > nums[i+1]) {
                decreasingCount++;
                increasingCount = 1; // Reset the other streak!
            }
            else {
                // If elements are equal, reset both
                increasingCount = 1;
                decreasingCount = 1;
            }
            
            // Track the maximum value found during the loop
            maxAnswer = max({maxAnswer, increasingCount, decreasingCount});
            
            // Crucial step you missed: move the pointer forward!
            i++; 
        }
        
        return maxAnswer;
    }
};