class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
        int moves = 0 ;
        int start = 0 ;
        int end = nums.size()-1 ;
        while(start < end){
            moves += abs(nums[end] - nums[start]) ;
            end -- ;
            start ++ ;

        }
        return moves ;
        
    }
};