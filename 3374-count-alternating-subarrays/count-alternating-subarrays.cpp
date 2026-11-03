
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();

        long long count = 1;
        long long ans = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i-1]) {
                count++;
            }
            else {
                count = 1;
            }
            ans += count;
        }

        return ans;
    }
};