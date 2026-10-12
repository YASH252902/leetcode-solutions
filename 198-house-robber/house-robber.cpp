class Solution {
public:
// this is the recursive approach of the question now we apply dp memorizationn top down approach 
    int solveUsingMemo(vector<int>& nums, int index , vector<int>& dp) {
        if (index >= nums.size()) {
            return 0 ;
            
        }
        if(dp[index] != -1){
            return dp[index] ;
        }
        // money ko insert karana pehel index par fir uske bad i+2 index pr jump
        // krna pdega
        int includeAns = nums[index] + solveUsingMemo(nums, index + 2 , dp);
        // exclude ans pehle index ko hinc;lude nahi krengey
        int excludeAns = 0 + solveUsingMemo(nums, index + 1 , dp);
        int finalAns = max(includeAns, excludeAns);
        dp[index] = finalAns ;
        return finalAns ;
    }
    int rob(vector<int>& nums) {
        int index = 0;
        int n = nums.size() ;
        // int ans = solve(nums , index);
        vector<int>dp(n+1 , -1);
        int ans = solveUsingMemo(nums , index , dp ) ;
        return ans;
    }
};