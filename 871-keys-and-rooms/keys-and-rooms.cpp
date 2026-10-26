#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false); // Keep track of rooms we've entered
        stack<int> s;
        
        // Start with room 0
        s.push(0);
        visited[0] = true;
        int visited_count = 1; // We have visited room 0
        
        while (!s.empty()) {
            int current_room = s.top();
            s.pop();
            
            // Go through all the keys found in the current room
            for (int key : rooms[current_room]) {
                if (!visited[key]) {
                    visited[key] = true;
                    s.push(key);
                    visited_count++; // Increment our count of unique rooms visited
                }
            }
        }
        
        // If the number of visited rooms equals total rooms, we unlocked everything
        return visited_count == n;
    }
};