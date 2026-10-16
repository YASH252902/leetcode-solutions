// now we move towards the top down memorization approach 
class Solution {
public:
int solveMemo(string& word1 , string& word2 , int i , int j , vector<vector<int>>& dp){
  if (i == word1.length()) {
            return word2.length() - j;
        }
        // If word2 is exhausted, we must delete the remaining characters of word1
        if (j == word2.length()) {
            return word1.length() - i;
        }
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
    // there are threre cases case one to insert case two to delete and case three to replace the character 
    int ans  = 0  ;
    if(word1[i] == word2[j]){
        ans = 0 + solveMemo(word1 , word2 , i+1 , j+1 , dp ) ;
    }
    else{
        ans = 1 + min(solveMemo(word1 , word2 , i+1 , j , dp ) , min (solveMemo(word1 , word2 , i , j+1 , dp) , solveMemo(word1 , word2 , i+1 , j+1 , dp ))) ;
    }
    dp[i][j] = ans ;
    return ans ;
}
    int minDistance(string word1, string word2) {
        int i = 0 ;
        int j = 0 ; 
        vector<vector<int>>dp(word1.length() + 1 , vector<int>(word2.length() + 1 , -1)) ;
        int ans =  solveMemo(word1 , word2 , i , j , dp);
        return ans ;
        
    }
};