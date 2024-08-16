class Solution {

    // int ans=

    int max_money(int idx, vector<int> & dp, vector<int> & nums){
        if(idx<0)
        return 0;

        if(dp[idx]!=-1)
        return dp[idx];

        int pick = nums[idx] + max_money(idx-2, dp, nums);

        int not_pick = max_money(idx-1, dp, nums);
        
        return dp[idx]=max(pick, not_pick);

    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
        return nums[0];
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);

vector<int> temp(nums.begin()+1, nums.end());
        nums.pop_back();
            

        return max(max_money(n-2, dp1, nums), max_money(n-2, dp2, temp));
    }
};