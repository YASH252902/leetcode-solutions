#include <vector>
#include <string>

using namespace std;

class Solution {
    int timer;
    vector<int> tin, tout, depth, val;
    vector<vector<int>> up;
    vector<int> bit;
    int n;

    // Precompute LCA table and Euler Tour entry/exit times
    void dfs(int u, int p, int d, const vector<vector<int>>& adj) {
        tin[u] = ++timer;
        up[u][0] = p;
        for (int i = 1; i < 20; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        depth[u] = d;
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, adj);
            }
        }
        tout[u] = ++timer;
    }

    // Update Fenwick Tree (XOR)
    void add(int idx, int v) {
        for (; idx <= 2 * n; idx += idx & -idx) {
            bit[idx] ^= v;
        }
    }

    // Prefix XOR query from Fenwick Tree
    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res ^= bit[idx];
        }
        return res;
    }

    // Get Lowest Common Ancestor using Binary Lifting
    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        
        for (int i = 0; i < 20; ++i) {
            if (diff & (1 << i)) u = up[u][i];
        }
        if (u == v) return u;
        
        for (int i = 19; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n_nodes, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = n_nodes;
        timer = 0;
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        val.assign(n, 0);
        up.assign(n, vector<int>(20, 0));
        bit.assign(2 * n + 1, 0);

        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        if (n > 0) {
            dfs(0, 0, 0, adj);
        }

        // Initialize Fenwick Tree with initial node characters
        for (int i = 0; i < n; ++i) {
            val[i] = 1 << (s[i] - 'a');
            add(tin[i], val[i]);
            add(tout[i], val[i]);
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        
        for (const string& q : queries) {
            // Fast string parsing
            int i = 0;
            while (q[i] != ' ') i++; // Skip "update" or "query"
            i++; 
            
            int u = 0;
            while (q[i] != ' ') {
                u = u * 10 + (q[i] - '0');
                i++;
            }
            i++;
            
            if (q[0] == 'u') { // "update u c"
                char c = q[i];
                int new_val = 1 << (c - 'a');
                int diff = val[u] ^ new_val;
                
                if (diff != 0) {
                    add(tin[u], diff);
                    add(tout[u], diff);
                    val[u] = new_val;
                }
            } else { // "query u v"
                int v = 0;
                while (i < q.size()) {
                    v = v * 10 + (q[i] - '0');
                    i++;
                }
                
                int lca = get_lca(u, v);
                int mask = query(tin[u]) ^ query(tin[v]) ^ val[lca];
                
                // True if mask has at most 1 bit set
                ans.push_back(mask == 0 || (mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};