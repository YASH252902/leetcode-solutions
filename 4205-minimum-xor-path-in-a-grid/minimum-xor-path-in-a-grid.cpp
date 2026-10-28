class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[j] will store all unique XOR sums to reach the current row's j-th column
        // We use a 1D array of vectors to optimize space, keeping only the necessary states.
        vector<vector<int>> dp(n);
        
        // Initialize the starting cell (0, 0)
        dp[0].push_back(grid[0][0]);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Skip the starting cell as it's already initialized
                if (i == 0 && j == 0) continue;
                
                vector<int> current_xors;
                
                // Transition from the cell directly above (i - 1, j)
                if (i > 0) {
                    for (int val : dp[j]) {
                        current_xors.push_back(val ^ grid[i][j]);
                    }
                }
                
                // Transition from the cell directly to the left (i, j - 1)
                if (j > 0) {
                    for (int val : dp[j - 1]) {
                        current_xors.push_back(val ^ grid[i][j]);
                    }
                }
                
                // Sort and remove duplicates to prevent combinatorial explosion of states
                sort(current_xors.begin(), current_xors.end());
                current_xors.erase(unique(current_xors.begin(), current_xors.end()), current_xors.end());
                
                // Update the state for the current cell
                dp[j] = current_xors;
            }
        }
        
        // The bottom-right cell is dp[n - 1]. Since it was sorted in the loop,
        // the minimum possible XOR path sum is simply the first element[cite: 1].
        return dp[n - 1][0];
    }
};