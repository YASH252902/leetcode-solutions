#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int min_price = INT_MAX;
        int max_factor = 0;

        for (const auto& item : items) {
            max_factor = max(max_factor, item[0]);
            min_price = min(min_price, item[1]);
        }

        // Count occurrences of each factor
        vector<int> factor_cnt(max_factor + 1, 0);
        for (const auto& item : items) {
            factor_cnt[item[0]]++;
        }

        // Sieve-style loop: mult_cnt[f] = total items whose factor is divisible by f
        vector<int> mult_cnt(max_factor + 1, 0);
        for (int f = 1; f <= max_factor; ++f) {
            if (factor_cnt[f] > 0) {
                for (int m = f; m <= max_factor; m += f) {
                    mult_cnt[f] += factor_cnt[m];
                }
            }
        }

        // Map of {price -> total bonus-eligible copies available at that price}
        map<long long, long long> bonus_copies;
        for (const auto& item : items) {
            long long factor = item[0];
            long long price = item[1];

            // Only worth buying for a freebie if price < 2 * min_price
            if (price < 2LL * min_price) {
                // Exclude the item itself (j != i)
                long long available_freebies = mult_cnt[factor] - 1;
                if (available_freebies > 0) {
                    bonus_copies[price] += available_freebies;
                }
            }
        }

        long long total_items = 0;
        long long rem_budget = budget;

        // Greedily buy cheapest 2-for-1 bonus deals first
        for (const auto& [price, count] : bonus_copies) {
            if (rem_budget < price) break;
            long long buy = min(count, rem_budget / price);
            total_items += buy * 2;
            rem_budget -= buy * price;
        }

        // Spend leftover budget on the cheapest item
        total_items += rem_budget / min_price;

        return static_cast<int>(total_items);
    }
};
