class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& pr) {

        vector<int> indg(V,0);

        int n= pr.size();

        vector<int> adj[V];

        for (int i=0; i<n; ++i){
            // adj[pr[i][0]].push_back(pr[i][1]);
            adj[pr[i][1]].push_back(pr[i][0]);
        }
    for(int i=0; i<V; ++i){
        for (auto &x: adj[i]){
            indg[x]++;
        }
    }

        queue<int> q;

        for (int i=0; i<V; ++i){
            if (indg[i]==0)
            q.push(i);
        }

 int cnt=0;
        while (!q.empty()){
            int node= q.front();
            q.pop();
           cnt++;

            // vector<int> ans;

            for (auto &x: adj[node]){
                indg[x]--;
                if(indg[x]==0)
                q.push(x);
            }
        }

        return cnt==V;
        
    }
};