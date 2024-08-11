class Solution {

    int dfs(int node, int parent, vector<int> adj[], vector<int>& size) {

        int cnt = 1;

        for (auto it : adj[node]) {
            if (it != parent)
                cnt += dfs(it, node, adj, size);
        }
        size[node] = cnt;
        return cnt;
    }

public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n + 1];

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> size(n + 1, 0);
        dfs(0, -1, adj, size);
        int ans = 0;

        for (int i = 0; i < n + 1; ++i) {
            int prev = 0;
            int f = 0;
            for (auto it : adj[i]) {
                if (size[it] < size[i]) {
                    if (prev != 0 && size[it] != prev) {
                        f = 1;
                        break;
                    } else if (prev == 0) {
                        prev = size[it];
                    }
                }
            }
            if (f == 0)
                ans += 1;
        }
        return ans;
    }
};