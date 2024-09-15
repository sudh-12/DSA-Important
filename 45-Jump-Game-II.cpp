class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int mx_jump = 0;
        int jump = 0;

        //if already at last position return 0
        if (n == 1)
            return 0;

    // the idea is to jump at that position from where you can jump farthest to next position
    // because you have to greedly reach the end of array as soon as possible

        for (int i = 0; i < n; ++i) {
            mx_jump = i + nums[i];
            // check if it touches the last position
            if (mx_jump >= n - 1)
                return jump + 1;
            int pos = 0;
            // check max we can go from a particular position in range of current steps
            int max_in_range = 0;
            for (int j = i + 1; j <= mx_jump; ++j) {
                if (j + nums[j] > max_in_range) {
                   max_in_range = j + nums[j];
                    pos = j;
                }
            }
            //i will increment 1 position as per for loop
            i = pos - 1;
            jump += 1;
        }

        // in the worst case it will take n-1 jumps
        return n - 1;
    }
};