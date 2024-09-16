class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end());
        vector<vector<int>> ans;
        int n = inter.size();
        int i =0;

        while(i<n){
            int s = inter[i][0];
            int e = inter[i][1];
            int j = i+1;
            int max_end= e;
            while(j<n && inter[j][0]<=max_end){
                max_end = max(max_end,inter[j][1]);
                j+=1;
            }
            ans.push_back({s,max_end});
            i=j;
        }

        return ans;
    }
};