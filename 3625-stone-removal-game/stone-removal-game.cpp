class Solution {
public:
    bool canAliceWin(int n) {
        int stonesToRemove = 10;
        bool aliceTurn = true;
        
        while (n >= stonesToRemove) {
            n -= stonesToRemove;
            stonesToRemove--;
            aliceTurn = !aliceTurn;
        }
        
        // If it's currently Alice's turn, she couldn't make a move and loses.
        // If it's Bob's turn, Bob couldn't make a move, so Alice wins.
        return !aliceTurn;
    }
};
