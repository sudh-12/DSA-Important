class Solution {

    int solve(int idx, string s, unordered_set<string> st, vector<int>& dp) {
        if (idx >= s.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        string temp = "";
        int extra = INT_MAX;

        for (int i = idx; i < s.size(); ++i) {
            temp += s[i];

            if (st.find(temp) != st.end()) {
                extra = min(extra, solve(i + 1, s, st, dp));
            }
        }

        extra = min(extra, 1 + solve(idx + 1, s, st, dp));
        return dp[idx] = extra;
    }

public:
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        unordered_set<string> st;
        vector<int> dp(n, -1);

        for (auto x : dict) {
            st.insert(x);
        }

        return solve(0, s, st, dp);
    }
};