class Solution {
    private:

    bool check (vector<int> &nums, int d, int diff){
        long long prev = nums[0] ;

        for(int i=1; i<nums.size(); ++i){
            long long next =  max(prev + diff, (long long)nums[i]);
            if(next>nums[i]+d )
            return false;
            prev=next;
        }

        return true;
    }
public:
    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        sort(start.begin(), start.end());
        long long low = 0;
        long long high = (start[n-1] + d - start[0]);
        long long ans = 0;

        while(low<=high){
            long long mid = low + (high -low)/2;

            if(check(start, d, mid)==true)
            {
                ans = mid;
                low = mid +1;
            }
            else {
                high = mid -1;
            }
        }

        return (int)ans;
    }
};