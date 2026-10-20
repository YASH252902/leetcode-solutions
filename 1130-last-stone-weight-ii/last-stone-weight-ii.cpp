class Solution {
public:
int totalSum ;
int solveMemo( vector<int>& stones , int index , int sum , vector<vector<int>>& dp){
    if(index == stones.size()){
        if(sum < 0){
            return INT_MAX ;
        }
        return sum ;
    }
    if(dp[index][sum + totalSum] != -1){
        return dp[index][sum + totalSum] ;
    }
    int positiveAns = solveMemo( stones , index + 1 , sum + stones[index] , dp ) ;
    int negativeAns = solveMemo( stones , index + 1 , sum - stones[index] , dp ) ;
    int finalAns = min( positiveAns , negativeAns) ;
    dp[index][sum + totalSum] = finalAns ; 
    return finalAns ;
}

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size() ;
        totalSum = accumulate(stones.begin() , stones.end() , 0) ;
        vector<vector<int>>dp(n+1 , vector<int>(2*totalSum + 1 , -1)) ;
     int ans =  solveMemo( stones , 0 , 0 , dp ) ;
     return ans ;
    }
};