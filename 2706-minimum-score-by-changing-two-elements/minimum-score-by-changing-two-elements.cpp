class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        
        // high score of an array is the max absolute difference between arr[i] and arr[j]
        // or high score can be calculated as difference between the max element of an array to min element of an array 
        // highScore = abs(nums[max] - nums[min])
        int n = nums.size();
        int lowScore = INT_MAX;
        int highScore = INT_MIN; 
        int totalScore = 0;

        // Pehle array ko sort kar dete hain taaki min aur max elements aasani se mil jayein
        sort(nums.begin(), nums.end());

        // Kyunki humein 2 elements change karne hain, hum unhe kisi existing element ke barabar kar sakte hain
        // Isse minimum absolute difference (lowScore) hamesha 0 ho jayega
        lowScore = 0;

        // Ab highScore (max - min) ko minimize karne ke liye 3 cases possible hain:
        // Case 1: 2 sabse chhote elements change kar do -> bacha hua min nums[2], max nums[n-1]
        int case1 = nums[n - 1] - nums[2];

        // Case 2: 2 sabse bade elements change kar do -> bacha hua min nums[0], max nums[n-3]
        int case2 = nums[n - 3] - nums[0];

        // Case 3: 1 sabse chhota aur 1 sabse bada change kar do -> bacha hua min nums[1], max nums[n-2]
        int case3 = nums[n - 2] - nums[1];

        // Teeno cases mein se jo sabse chhota difference de, wahi hamara minimum highScore hoga
        highScore = min({case1, case2, case3});

        totalScore = lowScore + highScore;
        return totalScore;
    }
};