// now we use 2D dp as the two parameters are changing so we use the 2D dp

class Solution {
public:
int solveUsingMemo( int start , int end , vector<vector<int>>& dp) {
    if(start >= end){
        return 0 ;
    }
    if(dp[start][end] != -1){
        return dp[start][end] ;
    }
    int ans = INT_MAX ;
    for(int i = start ; i <=end ; i++){
        ans = min(ans , i + max (solveUsingMemo(start , i - 1 , dp) , solveUsingMemo(i +1 , end , dp ))) ;
        
    }
    dp[start][end] = ans ;
    return ans ;
}
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1)) ;
        int ans = solveUsingMemo( 1 , n , dp) ;
        return ans ;
        
    }
};