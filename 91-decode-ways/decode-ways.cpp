class Solution {
public:
int solveMemo( string& s , int index , vector<int>& dp){
    if(index == s.size()){
        return 1 ;
    }
    if(s[index] == '0'){
        return 0 ;
    }
    if(dp[index] != -1){
        return dp[index] ;
    }
    int ways = solveMemo(s , index+1 , dp) ;
    if(index+1 < s.size()){
        int n = (s[index] - '0') * 10 + (s[index+1] - '0') ;
        if( n >= 10 && n <= 26)
        ways = ways + solveMemo(s , index+2 , dp ) ;

    }
    dp[index] = ways ;
    return ways ;
}
    int numDecodings(string s) {
        int n = s.length() ; 
        vector<int>dp(n+1 , -1) ;
        int ans = solveMemo( s , 0 , dp) ;
        return ans ;
    
        
    }
};