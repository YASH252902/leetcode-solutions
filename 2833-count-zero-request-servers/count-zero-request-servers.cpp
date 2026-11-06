#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // 1. Sort logs chronologically based on timestamps (column 1)
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int q = queries.size();
        // 2. Store original indices of queries before sorting them
        // pair: {query_time, original_index}
        vector<pair<int, int>> sorted_queries(q);
        for (int i = 0; i < q; i++) {
            sorted_queries[i] = {queries[i], i};
        }
        
        // Sort queries by time so we can slide the window forward monotonically
        sort(sorted_queries.begin(), sorted_queries.end());
        
        vector<int> ans(q);
        unordered_map<int, int> server_counts; // Tracks {server_id : active_requests}
        int active_servers = 0;
        
        int left = 0;
        int right = 0;
        int num_logs = logs.size();
        
        // 3. Process each query using the sliding window
        for (int i = 0; i < q; i++) {
            int current_time = sorted_queries[i].first;
            int original_index = sorted_queries[i].second;
            
            // Expand window to include logs up to the current query's end time
            while (right < num_logs && logs[right][1] <= current_time) {
                int server_id = logs[right][0];
                if (server_counts[server_id] == 0) {
                    active_servers++; // A new server became active
                }
                server_counts[server_id]++;
                right++;
            }
            
            // Shrink window to remove logs older than current_time - x
            while (left < right && logs[left][1] < current_time - x) {
                int server_id = logs[left][0];
                server_counts[server_id]--;
                if (server_counts[server_id] == 0) {
                    active_servers--; // A server has no more active requests in this window
                }
                left++;
            }
            
            // Inactive servers = total servers (n) - active servers
            ans[original_index] = n - active_servers;
        }
        
        return ans;
    }
};