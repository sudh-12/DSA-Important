class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx_index = 0;
        int n = nums.size();

        for(int i=0; i<n; ++i){
            if(i>mx_index)
            return false;

            mx_index = max(mx_index, i+nums[i]);
        }

        return true;
    }
};