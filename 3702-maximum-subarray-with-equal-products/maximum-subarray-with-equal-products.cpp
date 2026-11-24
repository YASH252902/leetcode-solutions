#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Upper bound for lcm(arr) * gcd(arr):
        // Since elements are <= 10, lcm of all numbers <= 10 is 2520, 
        // and max gcd is 10, so prod cannot validly exceed 25200.
        int max_limit = 25200;

        for (int i = 0; i < n; ++i) {
            int prod = 1;
            int g = 0;
            int l = 1;

            for (int j = i; j < n; ++j) {
                prod *= nums[j];
                
                // Prune early if product grows beyond possible lcm * gcd
                if (prod > max_limit) {
                    break;
                }

                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
