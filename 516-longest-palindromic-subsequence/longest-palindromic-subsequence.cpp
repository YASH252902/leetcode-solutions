// now we move toward the tabulation method
class Solution {
public:
    int solveMemo(string& s, int findex, int lindex, vector<vector<int>>& dp) {
        // Base Case 1: Pointers crossed each other (empty substring)
        if (findex > lindex) {
            return 0;
        }
        // Base Case 2: Pointers are at the same single character
        if (findex == lindex) {
            return 1;
        }
        if (dp[findex][lindex] != -1) {
            return dp[findex][lindex];
        }

        int includeAns = 0;
        int excludeAns = 0;

        if (s[findex] == s[lindex]) {
            includeAns = 2 + solveMemo(s, findex + 1, lindex - 1, dp);
        } else {
            excludeAns = 0 + max(solveMemo(s, findex + 1, lindex, dp),
                                 solveMemo(s, findex, lindex - 1, dp));
        }

        int finalAns = max(includeAns, excludeAns);
        dp[findex][lindex] = finalAns;
        return finalAns;
    }
    int solveTabulation(string s) {
          int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
      
        for (int findex = n-1; findex >= 0; findex--) {
            dp[findex][findex] = 1 ;
            for (int lindex = findex+1; lindex < n; lindex++) {
                int includeAns = 0;
                int excludeAns = 0;

                if (s[findex] == s[lindex]) {
                    includeAns = 2 + dp[findex+1][lindex-1];
                } else {
                    excludeAns = 0 + max(dp[findex+1][lindex], dp[findex][lindex-1]);
                }

                int finalAns = max(includeAns, excludeAns);
                dp[findex][lindex] = finalAns;
            }
        }
        return dp[0][n-1] ;
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int findex = 0;
        int lindex = n - 1;
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // int ans = solveMemo(s, findex, lindex, dp);
        // return ans;
        int ans = solveTabulation(s) ;
        return ans ;
    }
};