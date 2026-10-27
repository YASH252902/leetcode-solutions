class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0 ;
        int sum = 0 ;
        int length = INT_MAX ;
        for(int right = 0 ; right < nums.size() ; right++){
            sum += nums[right] ;
            while(sum >= target){
                
                    length = min (length , right-left+1) ;
            sum -= nums[left] ;
            left ++ ;
            }
        
        }
        return length == INT_MAX ? 0 : length ;
        
        
    }
};