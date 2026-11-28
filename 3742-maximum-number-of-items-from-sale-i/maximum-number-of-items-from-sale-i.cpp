#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> dp(budget + 1, 0);
        int min_price = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int factor = items[i][0];
            int price = items[i][1];
            min_price = min(min_price, price);

            // Count 1 (the item itself) + all other items whose factor it divides
            int total_gain = 0;
            for (int j = 0; j < n; ++j) {
                if (items[j][0] % factor == 0) {
                    total_gain++;
                }
            }

            // 0/1 Knapsack: iterate backwards so each item's bonus is triggered at most once
            for (int b = budget; b >= price; --b) {
                dp[b] = max(dp[b], dp[b - price] + total_gain);
            }
        }

        // Spend any remaining budget on the cheapest item
        int max_items = 0;
        for (int b = 0; b <= budget; ++b) {
            max_items = max(max_items, dp[b] + (budget - b) / min_price);
        }

        return max_items;
    }
};
