class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int mx_jump = 0;
        int jump = 0;

        if (n == 1)
            return 0;

        for (int i = 0; i < n; ++i) {
            mx_jump = i + nums[i];
            if (mx_jump >= n - 1)
                return jump + 1;
            int pos = 0;
            int mir = 0;
            for (int j = i + 1; j <= i + nums[i]; ++j) {
                if (j + nums[j] > mir) {
                    mir = j + nums[j];
                    pos = j;
                }
            }
            i = pos - 1;
            jump += 1;
        }

        return n - 1;
    }
};