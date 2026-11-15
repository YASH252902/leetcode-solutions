#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int odd_count = 0;
        int even_count = 1; // The initial prefix sum before any elements is 0 (which is even)
        long long current_prefix_sum = 0;
        long long result = 0;
        
        for (int num : arr) {
            current_prefix_sum += num;
            
            // If the current prefix sum is even
            if (current_prefix_sum % 2 == 0) {
                result = (result + odd_count) % MOD;
                even_count++;
            } 
            // If the current prefix sum is odd
            else {
                result = (result + even_count) % MOD;
                odd_count++;
            }
        }
        
        return result;
    }
};