// here we firstly use the memorization method to solve this question here the two parameters are changing so we use the 2D dp

class Solution {
public:
    int solveMemo(vector<int>& arr, map<pair<int, int>, int>& maxi, int left,
                 int right , vector<vector<int>>& dp) {
        if (left == right) {
            return 0;
        }
        if(dp[left][right] != -1){
            return dp[left][right] ;
        }
        int ans = INT_MAX;
        for (int i = left; i < right; i++) {

            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] +
                               solveMemo(arr, maxi, left, i , dp) +
                               solveMemo(arr, maxi, i + 1, right , dp));
        }
        dp[left][right] = ans ;
        return ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        for(int i = 0 ; i < arr.size() ; i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }
        int n = arr.size() ;
        vector<vector<int>>dp(n+1 , vector<int>( n+100 , -1)) ;
        int ans = solveMemo(arr , maxi , 0 , n-1 , dp) ;
        return ans ;
    }
};