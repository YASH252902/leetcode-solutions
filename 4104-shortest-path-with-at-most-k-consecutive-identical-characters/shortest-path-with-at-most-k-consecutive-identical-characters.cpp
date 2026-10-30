#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Create adjacency list where adj[u] contains {v, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        // dist[u][c] = min distance to reach node u with a suffix of length c 
        // consisting of identical characters (equal to labels[u])
        // Initialize distances to 1e9 (acting as infinity)
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        dist[0][1] = 0;
        
        // Min-heap priority queue: {current_distance, node, consecutive_count}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            auto [d, u, cur] = pq.top();
            pq.pop();
            
            // Reached destination
            if (u == n - 1) {
                return d;
            }
            
            // Skip stale states
            if (d > dist[u][cur]) {
                continue;
            }
            
            // Explore neighbors
            for (const auto& [v, w] : adj[u]) {
                int nxt_cur = (labels[v] == labels[u]) ? cur + 1 : 1;
                
                // Only proceed if it doesn't violate the constraint and offers a strictly shorter path
                if (nxt_cur <= k && d + w < dist[v][nxt_cur]) {
                    dist[v][nxt_cur] = d + w;
                    pq.push({d + w, v, nxt_cur});
                }
            }
        }
        
        // Return -1 if no valid path reaches the end node
        return -1;
    }
};