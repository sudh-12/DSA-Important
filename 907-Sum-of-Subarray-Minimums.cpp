class Solution {
public:
    const int M = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl(n, -1);
        vector<int> nsr(n, n);
        stack<int> st;
         int ans = 0;

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                nsl[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = 0; i < n; ++i) {
            // be careful don't use equal to sign again to count twice
            while (!st.empty() && arr[i] < arr[st.top()]) {
                nsr[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for (int i = 0; i < n; ++i) {
            long long left = i - nsl[i];
            long long right = nsr[i] - i;
            long long contribution = (left * right % M) * arr[i] % M;
            ans = (ans + contribution) % M;
        }

        return ans;
    }
};