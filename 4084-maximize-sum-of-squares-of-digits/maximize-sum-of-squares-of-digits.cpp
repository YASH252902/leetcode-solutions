#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // 1. Check if it's impossible to achieve the target sum
        if (sum > 9LL * num) {
            return "";
        }
        
        // 2. Pre-allocate string with '0's of size `num`
        string ans(num, '0');
        
        // 3. Greedily place the largest possible digit (up to 9) from left to right
        for (int i = 0; i < num && sum > 0; ++i) {
            int digit = min(9, sum);
            ans[i] = '0' + digit;
            sum -= digit;
        }
        
        return ans;
    }
};