class Solution {
    private:
    int cntpairs(int x, vector<int> &nums){
        int left=0, right=1;
        int n=nums.size();
        int cnt=0;

        while(right<n){
            if(nums[right]-nums[left]<=x){
            cnt+=right-left;
            right++;
            }
            else {
                left++;
            }
        }

        return cnt;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[n-1]-nums[0];

        while(low<high){
            int mid= low +(high-low)/2;
            if(cntpairs(mid,nums)<k)
            low=mid+1;
            else
            high=mid;
        }
        return high;
    }
};