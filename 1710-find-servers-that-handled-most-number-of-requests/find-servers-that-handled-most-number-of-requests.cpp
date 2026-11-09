#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // Keeps track of available servers sorted by ID
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        // Min-heap to track busy servers: stores {endTime, serverId}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        
        // Tracks the number of requests handled by each server
        vector<int> count(k, 0);
        
        for (int i = 0; i < arrival.size(); ++i) {
            int arrTime = arrival[i];
            int duration = load[i];
            
            // 1. Free up servers that finished their tasks before or exactly at current arrival time
            while (!busy.empty() && busy.top().first <= arrTime) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            // 2. If no servers are available, the request is dropped
            if (available.empty()) {
                continue; 
            }
            
            // 3. Find the first available server >= (i % k)
            auto it = available.lower_bound(i % k);
            
            // 4. Wrap around if no server >= (i % k) is available
            if (it == available.end()) {
                it = available.begin(); 
            }
            
            // 5. Assign task to the server
            int serverId = *it;
            available.erase(it);
            busy.push({arrTime + duration, serverId});
            count[serverId]++;
        }
        
        // 6. Find the server(s) with the maximum handled requests
        int maxRequests = *max_element(count.begin(), count.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == maxRequests) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
