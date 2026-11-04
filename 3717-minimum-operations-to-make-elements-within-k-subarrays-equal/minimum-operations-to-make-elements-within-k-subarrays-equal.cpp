#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        // C[i] will store the minimum operations to make nums[i ... i+x-1] all equal
        vector<long long> C(n - x + 1, 0);
        
        // Two multisets to maintain the median dynamically
        multiset<long long> low, high;
        long long sum_low = 0, sum_high = 0;
        
        // Balances the two sets so that `low` always holds exactly ceil(current_elements / 2)
        auto balance = [&]() {
            int target_low = (low.size() + high.size() + 1) / 2;
            
            while (low.size() > target_low) {
                long long val = *low.rbegin();
                low.erase(prev(low.end()));
                sum_low -= val;
                high.insert(val);
                sum_high += val;
            }
            while (low.size() < target_low) {
                long long val = *high.begin();
                high.erase(high.begin());
                sum_high -= val;
                low.insert(val);
                sum_low += val;
            }
        };
        
        auto add = [&](long long val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sum_low += val;
            } else {
                high.insert(val);
                sum_high += val;
            }
            balance();
        };
        
        auto remove = [&](long long val) {
            auto it = high.find(val);
            if (it != high.end()) {
                high.erase(it);
                sum_high -= val;
            } else {
                it = low.find(val);
                low.erase(it);
                sum_low -= val;
            }
            balance();
        };
        
        // Phase 1: Slide window of size x and compute costs
        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            
            // If the window exceeds size x, remove the oldest element
            if (i >= x) {
                remove(nums[i - x]);
            }
            
            // If we have formed a valid window of size x, calculate the cost
            if (i >= x - 1) {
                long long cost;
                // Cost = sum(greater half) - sum(smaller half) + adjustment for odd sized windows
                if (x % 2 == 1) {
                    cost = *low.rbegin() - sum_low + sum_high;
                } else {
                    cost = sum_high - sum_low;
                }
                C[i - x + 1] = cost;
            }
        }
        
        // Phase 2: Dynamic Programming
        // dp[i][j] = minimum cost to select j non-overlapping subarrays from the prefix nums[0 ... i-1]
        const long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0; // Cost to select 0 subarrays is always 0
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                // Option 1: Do not start a subarray ending at index i-1
                dp[i][j] = dp[i - 1][j];
                
                // Option 2: Take the subarray of length x ending at index i-1
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + C[i - x]);
                }
            }
        }
        
        return dp[n][k];
    }
};