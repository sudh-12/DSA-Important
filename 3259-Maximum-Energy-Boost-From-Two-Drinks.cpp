class Solution {
    private:
    long long solve(vector<int>& a, vector<int>& b, int idx, int curr,
                    vector<vector<long long>>& dp) {
        if (idx >= a.size())
            return 0;

        if (dp[idx][curr] != -1)
            return dp[idx][curr];

        long long ans = 0;

        if (curr) {
            ans = max(a[idx] + solve(a, b, idx + 1, curr, dp),
                      solve(a, b, idx + 1, !curr, dp));
        } else
            ans = max(b[idx] + solve(a, b, idx + 1, curr, dp),
                      solve(a, b, idx + 1, !curr, dp));

        return dp[idx][curr] = ans;
    }

    public:
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        int n = A.size();
        // memoization dp
        // vector<vector<long long>> dp(n, vector<long long>(2, -1));
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));

        for(int i=n-1; i>=0; --i){
            dp[i][0] = max(B[i] + dp[i + 1][0], dp[i + 1][1]);
            dp[i][1] = max(A[i] + dp[i + 1][1], dp[i + 1][0]);
        }

        return max(dp[0][0], dp[0][1]);
        // return max(solve(A, B, 0, 0, dp), solve(A, B, 0, 1, dp));
    }
};