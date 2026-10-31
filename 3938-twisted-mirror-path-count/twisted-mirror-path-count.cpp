#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;
        
        // Edge case: if start and end are the same cell
        if (m == 1 && n == 1) return 1;
        
        // If the destination is a mirror, any path reaching it will be 
        // immediately reflected out of bounds, making all paths invalid.
        if (grid[m-1][n-1] == 1) return 0;
        
        // R[i][j] tracks paths arriving at (i, j) moving Right
        vector<vector<int>> R(m, vector<int>(n, 0));
        // D[i][j] tracks paths arriving at (i, j) moving Down
        vector<vector<int>> D(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 1. Handle the start cell (0, 0)
                if (i == 0 && j == 0) {
                    if (j + 1 < n) R[0][1] = 1;
                    if (i + 1 < m) D[1][0] = 1;
                    continue;
                }
                
                // 2. Base case: Target reached
                if (i == m - 1 && j == n - 1) {
                    return (R[i][j] + D[i][j]) % MOD;
                }
                
                // 3. Process current cell
                if (grid[i][j] == 0) {
                    // Empty cell: robot decides to branch Right or Down
                    long long arrivals = (R[i][j] + D[i][j]) % MOD;
                    
                    if (j + 1 < n) {
                        R[i][j+1] = (R[i][j+1] + arrivals) % MOD;
                    }
                    if (i + 1 < m) {
                        D[i+1][j] = (D[i+1][j] + arrivals) % MOD;
                    }
                } else {
                    // Mirror cell: deterministic reflection
                    long long r_in = R[i][j]; // Arrived moving Right
                    long long d_in = D[i][j]; // Arrived moving Down
                    
                    // Moving Right into mirror -> turns Down
                    if (i + 1 < m) {
                        D[i+1][j] = (D[i+1][j] + r_in) % MOD;
                    }
                    // Moving Down into mirror -> turns Right
                    if (j + 1 < n) {
                        R[i][j+1] = (R[i][j+1] + d_in) % MOD;
                    }
                }
            }
        }
        
        return 0;
    }
};