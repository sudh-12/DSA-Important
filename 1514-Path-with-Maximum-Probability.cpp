class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<pair<int, double>> adj[n];
        int i=0; 
        //create undirected adj list with edge weight
        for(auto it: edges){
            adj[it[0]].push_back({it[1],succProb[i]});
            adj[it[1]].push_back({it[0],succProb[i]});
            i+=1;
        }

        vector<double> prob(n,0.0);
        set<pair<double,int>> st;

        prob[start_node] = 1.0;
        st.insert({1.0,start_node});

        while(!st.empty()){
            // take maximum element
            auto it= (st.end());
            --it;
            double dist = it->first;
            int node = it->second;
            st.erase(it);

            for(auto x: adj[node]){
                int new_node = x.first;
                double new_dist = x.second;

                if(dist*new_dist>prob[new_node]){
                prob[new_node] = dist*new_dist;
                st.insert({prob[new_node], new_node});
                }

            }
        }

        return prob[end_node];
    }
};