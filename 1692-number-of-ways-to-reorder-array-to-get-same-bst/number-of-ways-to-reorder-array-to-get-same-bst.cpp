#include <vector>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    long long countWays(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return 1;
        }

        vector<int> left, right;
        int root = nums[0];
        
        // Partition elements into left and right subtrees
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long leftWays = countWays(left);
        long long rightWays = countWays(right);

        // n-1 is the total number of elements excluding the root
        // left.size() is the number of elements in the left subtree
        long long interleavingWays = comb[n - 1][left.size()];
        
        return (((interleavingWays * leftWays) % MOD) * rightWays) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        // Precompute combinations (Pascal's Triangle) up to n
        comb.assign(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            comb[i][0] = 1;
            comb[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
        
        // Subtract 1 because we exclude the original permutation
        return (countWays(nums) - 1 + MOD) % MOD;
    }
};