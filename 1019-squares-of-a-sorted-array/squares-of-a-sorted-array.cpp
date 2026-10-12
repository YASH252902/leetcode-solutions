class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // we can done this question using two pointers the one pointer we take
        // is l and one pointer we take is of r
        
        int n = nums.size();
        vector<int> result(n) ;
        int l = 0;
        int r = n - 1;
        int i = n - 1;
        while (l <= r) {
            int leftSquare = nums[l] * nums[l];
            int rightSquare = nums[r] * nums[r];
            if (leftSquare > rightSquare) {
                result[i] = leftSquare;
                l++;
            }
            else {
                result[i] = rightSquare;
                r--;
            }
            i--;
        }
        return result;
    }
};