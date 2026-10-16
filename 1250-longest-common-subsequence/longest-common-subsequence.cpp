// now we try to do the same ques but with tabulation method  step 1 initialize
// dp we already handle the 0 case now we take a look for any clash in looping
// variable when we reverse them but firslt we change the loop directions

class Solution {
public:
    int solveMemo(string& text1, string& text2, int i, int j,
                  vector<vector<int>>& dp) {
        if (i == text1.length() || j == text2.length()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (text1[i] == text2[j]) {
            ans = 1 + solveMemo(text1, text2, i + 1, j + 1, dp);
        } else {
            ans = 0 + max(solveMemo(text1, text2, i + 1, j, dp),
                          solveMemo(text1, text2, i, j + 1, dp));
        }
        dp[i][j] = ans;
        return ans;
    }
    int solveTab(string text1, string text2 , int i , int j) {
  
        vector<vector<int>> dp(text1.length() + 1,
                               vector<int>(text2.length() + 1, 0));
        for (int i = text1.length()-1; i >= 0; i--) {
            for (int j = text2.length()-1; j >= 0; j--) {
                int ans = 0;
                if (text1[i] == text2[j]) {
                    ans = 1 + dp[i+1][j+1];
                } else {
                    ans = 0 + max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0] ;
    }

    int solveTabSpaceOptimization(string text1, string text2 , int i , int j) {
  
       // vector<vector<int>> dp(text1.length() + 1,
                              // vector<int>(text2.length() + 1, 0));
                              vector<int>curr( text2.length()+1 , 0) ;
                              vector<int>next( text2.length()+1 , 0) ;
        for (int i = text1.length()-1; i >= 0; i--) {
            for (int j = text2.length()-1; j >= 0; j--) {
                int ans = 0;
                if (text1[i] == text2[j]) {
                    ans = 1 + next[j+1];
                } else {
                    ans = 0 + max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr ;
        }
        return next[0] ;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        // vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        // int ans = solveMemo(text1, text2, i, j, dp);
        // return ans;
        int ans = solveTabSpaceOptimization(text1 , text2 , i , j ) ;
        return ans ;
    }
};