//leetcode 547 

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;
        for (auto i : adj[node]) {
            if (vis[i] != 1) {
                dfs(i, adj, vis); // Fixing the recursive call to pass the correct node
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i); // This line is not necessary as adj[j] is already checked in the outer loop
                }
            }
        }
        
        int ans = 0;
        vector<int> vis(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (vis[i] != 1) {
                ans++;
                dfs(i, adj, vis);
            }
        }
        
        return ans;
    }
};
