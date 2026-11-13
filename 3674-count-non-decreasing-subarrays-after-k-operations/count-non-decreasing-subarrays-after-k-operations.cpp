class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        long long cost = 0;
        
        // Deque stores indices where adjusted values are non-increasing.
        deque<int> dq;
        
        // i expands the window to the left, j shrinks it from the right
        for (int i = nums.size() - 1, j = nums.size() - 1; i >= 0; --i) {
            
            // If the newly added left element is greater than the blocks to its right,
            // push those right-side elements up to nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                int l = dq.back();
                dq.pop_back();
                int r = dq.empty() ? j + 1 : dq.back();
                
                // Add the cost to raise the segment [l, r-1] up to nums[i]
                cost += 1LL * (r - l) * (nums[i] - nums[l]);
            }
            dq.push_back(i);
            
            // If total operations exceed k, we must shrink the window from the right
            while (cost > k) {
                // The rightmost element j is currently being pushed up to the highest 
                // block's value in the window, which sits at the front of the deque.
                cost -= nums[dq.front()] - nums[j];
                
                // If the block governing j only contains j itself, remove it
                if (dq.front() == j) {
                    dq.pop_front();
                }
                --j;
            }
            
            // Valid subarrays starting at `i` can end anywhere from `i` to `j`
            ans += (j - i + 1);
        }
        
        return ans;
    }
};