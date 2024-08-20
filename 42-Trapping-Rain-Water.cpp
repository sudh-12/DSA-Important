class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int> ngr(n, -1);
        vector<int> ngl(n, -1);
        stack<int> st;
        int mxl=0,mxr=0;

        for (int i = 0; i < n; ++i) {
           mxl=max(mxl,heights[i]);
           mxr=max(mxr,heights[n-i-1]);
           ngl[i]=mxl;
           ngr[n-i-1]=mxr;
        }

       int ans=0;

       for(int i=0; i<n; ++i){
        int mn=min(ngl[i], ngr[i]);
        if(mn>heights[i])
        ans+=mn-heights[i];
       }

        return ans;
    }
};