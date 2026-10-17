#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to check if cuboid 'a' can be placed on top of cuboid 'b'
    bool check(const vector<int>& a, const vector<int>& b) {
        return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
    }

    int solveUsingTabulation(vector<vector<int>>& cuboids) {
        int n = cuboids.size();

        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        // curr_index goes from n-1 down to 0
        for(int curr_index = n - 1; curr_index >= 0; curr_index--) {
            // prev_index goes from curr_index - 1 down to -1
            for(int prev_index = curr_index - 1; prev_index >= -1; prev_index--) {
                
                int includeAns = 0;
                
                // If there is no previous element, or the previous cuboid fits inside the current one
                if (prev_index == -1 || check(cuboids[prev_index], cuboids[curr_index])) {
                    // Add the height of the current cuboid and move to next state where prev becomes curr
                    includeAns = cuboids[curr_index][2] + next[curr_index + 1];
                }
                
                // Exclude current cuboid, prev remains the same
                int excludeAns = next[prev_index + 1];
                
                // Store max in current DP row (+1 offset to handle prev_index = -1)
                curr[prev_index + 1] = max(includeAns, excludeAns);
            }
            // Move curr row to next for the next iteration
            next = curr;
        } 
        
        // Return the answer for prev_index = -1
        return next[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // Step 1: Sort dimensions of EACH cuboid to make w <= l <= h
        // IMPORTANT: Use auto& to pass by reference, otherwise you are sorting a copy!
        for(auto& cuboid : cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        
        // Step 2: Sort all cuboids based on their dimensions
        sort(cuboids.begin(), cuboids.end());
        
        // Step 3: Run LIS tabulation logic
        return solveUsingTabulation(cuboids);
    }
};