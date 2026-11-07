#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // min-heap for free servers: {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        
        // min-heap for busy servers: {time_becomes_free, server_index}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyServers;
        
        int n = servers.size();
        for (int i = 0; i < n; ++i) {
            freeServers.push({servers[i], i});
        }
        
        int m = tasks.size();
        vector<int> ans(m);
        long long currentTime = 0;
        
        for (int j = 0; j < m; ++j) {
            // Fast-forward time to task arrival if we are ahead of it
            currentTime = max(currentTime, (long long)j);
            
            // If no free servers, jump to the time the next busy server finishes
            if (freeServers.empty()) {
                currentTime = busyServers.top().first;
            }
            
            // Free up all servers that have finished their tasks by currentTime
            while (!busyServers.empty() && busyServers.top().first <= currentTime) {
                int serverIndex = busyServers.top().second;
                busyServers.pop();
                // Push back to freeServers using its original weight
                freeServers.push({servers[serverIndex], serverIndex});
            }
            
            // Assign the task to the best available server
            auto bestServer = freeServers.top();
            freeServers.pop();
            
            int serverIndex = bestServer.second;
            ans[j] = serverIndex;
            
            // Send the server to work; it will be busy until (currentTime + task duration)
            busyServers.push({currentTime + tasks[j], serverIndex});
        }
        
        return ans;
    }
};