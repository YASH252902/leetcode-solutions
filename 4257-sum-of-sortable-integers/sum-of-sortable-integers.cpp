#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int sum_k = 0;
        
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;
            
            bool valid_k = true;
            int prev_max = -1; 
            
            for (int i = 0; i < n; i += k) {
                int current_min = nums[i];
                int current_max = nums[i];
                int drops = 0;
                
                for (int j = i; j < i + k - 1; ++j) {
                    current_min = min(current_min, nums[j + 1]);
                    current_max = max(current_max, nums[j + 1]);
                    
                    if (nums[j] > nums[j + 1]) {
                        drops++;
                    }
                }
                
                if (drops > 1 || (drops == 1 && nums[i + k - 1] > nums[i])) {
                    valid_k = false;
                    break;
                }
                
                if (i > 0 && current_min < prev_max) {
                    valid_k = false;
                    break;
                }
                
                prev_max = current_max;
            }
            
            if (valid_k) {
                sum_k += k;
            }
        }
        
        return sum_k;
    }
};