#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num % 10;
            num /= 10; // Fixed: added missing semicolon
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size(); // Fixed: typo szie()
        
        // Key: {digitSum, originalValue} -> Value: originalIndex
        // The map automatically sorts by digitSum first, then originalValue!
        map<pair<int, int>, int> mapist; 
        
        for(int i = 0; i < n; i++) { // Fixed: loop syntax
            mapist[{getDigitSum(nums[i]), nums[i]}] = i;
        }
        
        // Extract the sorted original indices from the map
        vector<int> targetIndices;
        for(auto const& [key, originalIndex] : mapist) {
            targetIndices.push_back(originalIndex);
        }
        
        // Calculate minimum swaps using cycle detection
        int swaps = 0;
        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; i++) {
            // Skip if already in the correct place or already visited in a cycle
            if(visited[i] || targetIndices[i] == i) {
                continue;
            }
            
            int cycle_size = 0;
            int j = i;
            
            // Follow the cycle
            while(!visited[j]) {
                visited[j] = true;
                j = targetIndices[j]; 
                cycle_size++;
            }
            
            // Add the swaps needed for this cycle
            if(cycle_size > 0) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};