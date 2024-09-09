class Solution {

    bool dfs(int node, vector<int>& ans, vector<int> adj[], vector<int>& visi,
             int parent) {
        visi[node] = 1;
        ans.push_back(node);

        for (auto x : adj[node]) {
            if (visi[x] == 0) {
                if (dfs(x, ans, adj, visi, node) == true)
                    return true;
            } else if (x != parent)
                return true;
        }

        return false;
    }

public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int> adj[num];
        vector<int> ans;
        vector<int> indegree(num, 0);
        queue<int> q;

        for (auto it : pre) {
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < num; ++i) {
            for (auto it : adj[i])
                indegree[it] += 1;
        }

        for (int i = 0; i < num; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (auto it : adj[node]) {
                indegree[it] -= 1;

                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        if (ans.size() != num)
            return {};

        return ans;
    }
};