class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> RevAdj[n];
        vector<int> indegree(n,0);
        queue<int> q;

        for(int i=0; i<n; ++i){
            for(auto it: graph[i]){
                RevAdj[it].push_back(i);
            }
        }

        for(int i=0; i<n; ++i){
            for(auto it: RevAdj[i]){
                indegree[it]+=1;
            }
        }

        for(int i=0; i<n; ++i){
            if(indegree[i]==0)
            q.push(i);
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for (auto it: RevAdj[node]){
                indegree[it]-=1;

                if(indegree[it]==0)
                q.push(it);
            }
        }

        sort(topo.begin(), topo.end());

        return topo;

    }
};