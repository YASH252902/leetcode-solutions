class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int closedIslands = 0;

        // DFS to sink the island (turn 0s into 1s)
        auto dfs = [&](auto& self, int r, int c) -> void {
            // Out of bounds or already water
            if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 1) {
                return;
            }
            
            grid[r][c] = 1; // Mark as visited by sinking it
            
            // Explore all 4 directions
            self(self, r + 1, c);
            self(self, r - 1, c);
            self(self, r, c + 1);
            self(self, r, c - 1);
        };

        // Step 1: Sink all islands connected to the boundary
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // If it's a boundary cell and is land (0)
                if ((r == 0 || c == 0 || r == rows - 1 || c == cols - 1) && grid[r][c] == 0) {
                    dfs(dfs, r, c);
                }
            }
        }

        // Step 2: Count and sink the remaining closed islands
        for (int r = 1; r < rows - 1; ++r) {
            for (int c = 1; c < cols - 1; ++c) {
                if (grid[r][c] == 0) {
                    closedIslands++;
                    dfs(dfs, r, c);
                }
            }
        }

        return closedIslands;
    }
};
        
    
