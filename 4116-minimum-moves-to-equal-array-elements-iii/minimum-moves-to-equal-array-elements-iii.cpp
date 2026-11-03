class Solution {
public:
    int minMoves(vector<int>& nums) {
        int start = 0; 
        int end = nums.size() - 1;
        int minMoves = 0;
        
        // Corrected syntax to sort the array in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        
        while(start <= end){
            minMoves += abs(nums[end] - nums[start]);
           
            end--;
        }
        return minMoves;
    }
};