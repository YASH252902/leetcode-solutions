#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        
        // Queue to store {row, col, steps}
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        
        // Start cell ko visited mark kar do (usko wall '+' bana do)
        maze[entrance[0]][entrance[1]] = '+';
        
        // 4 directions: Up, Down, Left, Right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            
            int r = current.first.first;
            int c = current.first.second;
            int steps = current.second;
            
            // Exit check: Agar boundary par hain aur start point nahi hai
            if ((r != entrance[0] || c != entrance[1]) && 
                (r == 0 || r == m - 1 || c == 0 || c == n - 1)) {
                return steps;
            }
            
            // Chaaron taraf check karo
            for (auto dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                
                // Agar naya cell grid ke andar hai aur khali rasta ('.') hai
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == '.') {
                    // Queue mein dalo aur steps 1 badha do
                    q.push({{nr, nc}, steps + 1});
                    
                    // Visited mark kar do taaki dobara is cell par na aayein
                    maze[nr][nc] = '+'; 
                }
            }
        }
        
        // Agar saare raste dekh liye par exit nahi mila
        return -1;
    }
};