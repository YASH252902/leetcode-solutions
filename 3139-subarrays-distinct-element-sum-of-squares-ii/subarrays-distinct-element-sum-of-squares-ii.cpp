#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    long long mod = 1000000007;
    vector<long long> sum;   // Stores sum of distinct counts (x)
    vector<long long> sumSq; // Stores sum of squares of distinct counts (x^2)
    vector<long long> lazy;  // Lazy propagation array

    // Helper function: Kisi node par '+val' update apply karne ke liye
    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        // (x + val)^2 = x^2 + 2*val*x + val^2
        // Sabhi elements ke liye sum karein toh:
        // new_sumSq = sumSq + 2 * val * sum + len * val^2
        long long valSq = (val * val) % mod;
        sumSq[node] = (sumSq[node] + (2 * val % mod) * sum[node] % mod + len * valSq % mod) % mod;
        
        // new_sum = sum + len * val
        sum[node] = (sum[node] + len * val % mod) % mod;
        
        // Lazy tag accumulate karo children ke liye
        lazy[node] = (lazy[node] + val) % mod;
    }

    // Lazy value ko children mein push karne ke liye
    void pushDown(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = l + (r - l) / 2;
            apply(2 * node, l, mid, lazy[node]);
            apply(2 * node + 1, mid + 1, r, lazy[node]);
            lazy[node] = 0;
        }
    }

    // Range [ql, qr] mein har element mein +1 add karne ka function
    void update(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }
        pushDown(node, l, r);
        int mid = l + (r - l) / 2;
        if (ql <= mid) {
            update(2 * node, l, mid, ql, qr);
        }
        if (qr > mid) {
            update(2 * node + 1, mid + 1, r, ql, qr);
        }
        // Children update hone ke baad current node ko update karo
        sum[node] = (sum[2 * node] + sum[2 * node + 1]) % mod;
        sumSq[node] = (sumSq[2 * node] + sumSq[2 * node + 1]) % mod;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum.assign(4 * n, 0);
        sumSq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> lastSeen; // Element last kis index par aaya tha
        long long totalAns = 0;

        for (int i = 0; i < n; i++) {
            // Agar element pehle nahi aaya toh -1, warna uska pichla index
            int prev = lastSeen.count(nums[i]) ? lastSeen[nums[i]] : -1;

            // Range [prev + 1, i] ke sabhi starting indices ke distinct count mein +1 karo
            update(1, 0, n - 1, prev + 1, i);

            // Root node (sumSq[1]) mein ab index 'i' par khatam hone wale 
            // sabhi subarrays ke squares ka sum hai
            totalAns = (totalAns + sumSq[1]) % mod;

            // Current index ko update karo
            lastSeen[nums[i]] = i;
        }

        return totalAns;
    }
};