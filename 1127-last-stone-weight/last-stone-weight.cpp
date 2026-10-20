#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Initialize a max heap with all the stones
        priority_queue<int> pq(stones.begin(), stones.end());
        
        // Continue smashing while there is more than 1 stone left
        while (pq.size() > 1) {
            int y = pq.top(); 
            pq.pop();
            
            int x = pq.top(); 
            pq.pop();
            
            // If they are not equal, push the remaining weight back
            if (y != x) {
                pq.push(y - x);
            }
        }
        
        // If the queue is empty, all stones were destroyed. Otherwise, return the last stone.
        return pq.empty() ? 0 : pq.top();
    }
};