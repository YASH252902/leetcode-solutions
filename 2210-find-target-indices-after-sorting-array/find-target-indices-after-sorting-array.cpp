class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result; // Create a vector to store the matching indices
        
        sort(nums.begin(), nums.end());
        
        // Use strictly less than (<) to avoid out-of-bounds errors
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                result.push_back(i); // Add the index to the result list
            }
        } 
        
        return result; // Return the entire list of indices at the end
    }
};