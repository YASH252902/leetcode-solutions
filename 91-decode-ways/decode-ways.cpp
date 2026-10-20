class Solution {
public:
    int solveMemo(string& s, int index, vector<int>& dp) {
        if (index == s.size()) {
            return 1;
        }
        if (s[index] == '0') {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int ways = solveMemo(s, index + 1, dp);
        if (index + 1 < s.size()) {
            int n = (s[index] - '0') * 10 + (s[index + 1] - '0');
            if (n >= 10 && n <= 26)
                ways = ways + solveMemo(s, index + 2, dp);
        }
        dp[index] = ways;
        return ways;
    }

    int solveUsingTab(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        
        for (int index = n - 1; index >= 0; index--) {
            if (s[index] == '0') {
                dp[index] = 0;
            } else { // Fixed brace here
                int ways = dp[index + 1];
                if (index + 1 < s.length()) {
                    int num = (s[index] - '0') * 10 + (s[index + 1] - '0'); // Renamed to 'num' to avoid shadowing 'n'
                    if (num >= 10 && num <= 26) {
                        ways = ways + dp[index + 2];
                    }
                }
                dp[index] = ways; // Moved inside the else block
            }
        }
        
        return dp[0];
    }

    int numDecodings(string s) {
        // vector<int> dp(n + 1, -1);
        // int ans = solveMemo(s, 0, dp);
        // return ans;
        int ans = solveUsingTab(s);
        return ans;
    }
};