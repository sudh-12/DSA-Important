class Solution {
    vector<vector<int>> dp;
    int solve(int len , int num, int clipboard){

    if(len==num)
        return 0;

        if(len>num)
        return 1e9;

        if(dp[len][clipboard]!=-1)
        return dp[len][clipboard];

        int copy= 2+ solve(2*len, num, len);
        int paste= 1 + solve(len+clipboard, num, clipboard); 

        return dp[len][clipboard]= min(copy, paste);
    }
public:
    int minSteps(int n) {
        
        dp.resize(n,vector<int> (n,-1));
        return n==1 ? 0 : 1 + solve(1, n, 1);
    }
};