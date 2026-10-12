#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // DFS function jo ek island ka area return karega
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base case: Agar boundary ke bahar hain ya paani ('0') hai, toh area 0 hai
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        
        // Node ko visit kar liya, isliye '0' bana do taaki dobara visit na ho
        grid[i][j] = 0; 
        
        // 1 (current node) + baaki chaaron directions ka area
        // LC 200 MEIN: Hum yahan kuch return nahi karte, bas chaaron taraf void DFS call kar dete hain.
        return 1 + dfs(grid, i+1, j) 
                 + dfs(grid, i-1, j) 
                 + dfs(grid, i, j+1) 
                 + dfs(grid, i, j-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        // LC 200 MEIN: Yahan `int island_count = 0;` hota
        
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Agar zameen ('1') milti hai, toh us island ka area nikalo
                if (grid[i][j] == 1) {
                    int current_area = dfs(grid, i, j);
                    max_area = max(max_area, current_area);
                    
                    // LC 200 MEIN: DFS call karne ke baad bas `island_count++;` karte.
                }
            }
        }
        
        return max_area;
    }
};