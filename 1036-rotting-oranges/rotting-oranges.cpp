#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_count = 0;
        
        // Step 1: Push all initially rotten oranges to the queue and count fresh oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }
        
        // If there are no fresh oranges, it takes 0 minutes
        if (fresh_count == 0) return 0;
        
        int minutes = 0;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Step 2: Perform level-order BFS
        while (!q.empty()) {
            int size = q.size();
            bool rotted_this_minute = false;
            
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                
                for (auto dir : dirs) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;
                    
                    // Check bounds and if the adjacent cell has a fresh orange
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Rot the orange
                        q.push({nr, nc});
                        fresh_count--;
                        rotted_this_minute = true;
                    }
                }
            }
            // Increment time only if at least one orange rotted during this step
            if (rotted_this_minute) {
                minutes++;
            }
        }
        
        // Step 3: If any fresh oranges remain, return -1. Otherwise, return elapsed minutes.
        return fresh_count == 0 ? minutes : -1;
    }
};