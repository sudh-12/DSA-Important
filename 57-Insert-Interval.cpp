class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& new_inter) {
        int n = inter.size();
        bool  f = 0;
        vector<vector<int>> ans;
        // int d =0;

        for(int i=0; i<n; ++i){
            if(f==0 && new_inter[0]<=inter[i][1]){
                if(new_inter[1]<inter[i][0]){
                    int s = min(inter[i][0], new_inter[0]);
                    ans.push_back({s, new_inter[1]});
                    f=1;
                    i-=1;
                    continue;
                }
                int s = min(new_inter[0], inter[i][0]);
                int mxe = max(new_inter[1], inter[i][1]);
                i+=1;
                while(i<n && inter[i][0]<=mxe){
                    mxe = max(mxe, inter[i][1]);
                    i+=1;
                }
                ans.push_back({s,mxe});
                f=1;
                i-=1;
                continue;
            }

            ans.push_back({inter[i][0], inter[i][1]});
        }

        if(f==0)
        ans.push_back({new_inter[0], new_inter[1]});

        return ans;

    }
};