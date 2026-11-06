class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size() ;
        // we have to find first smallest element in nums array
        // then we find largest element in nums array
        // then we compare element which is bigger or equal than smallest element and element which are smaller or equal than the larhest element we count that element then we return the count 
        sort(nums.begin() , nums.end()) ;
        int start = 0 ;
        int end = nums.size() - 1 ;
        int minElement = nums[start] ; 
        int maxElement = nums[nums.size() - 1] ;
        int num = 0 ;
        int count = 0 ; 
        for(int i = 0 ; i < nums.size() ; i++){
            if( nums[i] > minElement && nums[i] < maxElement){
                count ++ ;
            }
        }
        return count ;


        
    }
};