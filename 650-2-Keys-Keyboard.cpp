class Solution {
    vector<vector<int>> dp;
    int solve(int len, int num, int clipboard) {

        if (len == num)
            return 0;

        if (len > num)
            return 1e9;

        if (dp[len][clipboard] != -1)
            return dp[len][clipboard];

        int copy = 2 + solve(2 * len, num, len);
        int paste = 1 + solve(len + clipboard, num, clipboard);

        return dp[len][clipboard] = min(copy, paste);
    }

public:
    int minSteps(int n) {

        // TC : O(sqrt(n)) || o(n) in worst case(prime))
        if (n == 1) return 0;
        
        int steps = 0;
        int factor = 2;
        
        while (n > 1) {
            while (n % factor == 0) {
                steps += factor;
                n /= factor;
            }
            factor++;
        }
        
        return steps;

        // For DP Solution : TC O(n2)
        // dp.resize(n, vector<int>(n, -1));
        // return n == 1 ? 0 : 1 + solve(1, n, 1);
    }
};