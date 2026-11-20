#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        // Sort the array to process elements in non-decreasing order
        sort(nums.begin(), nums.end());
        
        // dp[x] stores the max length of a consecutive sequence ending at x
        unordered_map<int, int> dp;
        int max_len = 0;
        
        for (int num : nums) {
            // Update dp[num + 1] first (case: increment num by 1)
            dp[num + 1] = dp[num] + 1;
            
            // Update dp[num] second (case: keep num unchanged)
            dp[num] = dp[num - 1] + 1;
            
            // Track the overall maximum length found
            max_len = max({max_len, dp[num], dp[num + 1]});
        }
        
        return max_len;
    }
};
