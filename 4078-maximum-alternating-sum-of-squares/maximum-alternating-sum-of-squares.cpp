class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();

        vector<long long> square(n);
        for (int i = 0; i < nums.size(); i++) {
            square[i] = (long long)nums[i] * nums[i] ;
        }
        sort(square.begin(), square.end());
        long long max_square = 0;
        long long m = n / 2;
        for (int i = 0; i < m; i++) {
            max_square -= square[i];
        }
        for (int i = m; i < n; i++) {

            max_square += square[i];
        }
        return max_square;
    }
};