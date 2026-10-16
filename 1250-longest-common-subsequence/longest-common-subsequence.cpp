class Solution {
public:
int solveMemo( string& text1 , string& text2 , int i , int j , vector<vector<int>>& dp ){
    if(i == text1.length() || j == text2.length()){
        return 0 ;
    }
    if(dp[i][j] != -1){
        return dp[i][j] ;
    }
    int ans = 0 ;
    if(text1[i] == text2[j]){
        ans = 1 + solveMemo( text1 , text2 , i+1 , j+1 , dp) ;
    }
    else{
        ans = 0 + max(solveMemo(text1 , text2 , i+1 , j , dp) , solveMemo(text1 , text2 , i , j+1 , dp)) ;
    }
    dp[i][j] = ans ;
    return ans ;
}
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0 ;
        int j = 0 ;
        vector<vector<int>>dp(text1.length() , vector<int>(text2.length() , -1)) ;
        int ans = solveMemo( text1 , text2 , i , j , dp);
        return ans ;
        
    }
};