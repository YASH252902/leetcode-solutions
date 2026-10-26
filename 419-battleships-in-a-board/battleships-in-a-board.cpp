class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If it's empty water, skip it
                if (board[i][j] == '.') continue;
                
                // Check if there is an 'X' above
                if (i > 0 && board[i - 1][j] == 'X') continue;
                
                // Check if there is an 'X' to the left
                if (j > 0 && board[i][j - 1] == 'X') continue;
                
                // If we pass the checks, this is the top-left of a new ship
                count++;
            }
        }
        
        return count;
    }
};