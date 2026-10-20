class Solution {
public:
    vector<bool> visit;
    vector<vector<int>> adj;
    int countComponents(int n, vector<vector<int>>& edges) {
        visit.assign(n, false);
        adj.assign(n, {});
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        for (int node = 0; node < n; ++node) {
            if (!visit[node]) {
                dfs(node);
                res++;
            }
        }
        return res;
    }
    void dfs(int node) {
        visit[node] = true;
        for (int nei : adj[node]) {
            if (!visit[nei]) {
                dfs(nei);
            }
        }
    }
};
