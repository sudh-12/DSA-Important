class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> next_greater(n,-1);
        stack<int> st;

        for(int i=0; i<n; ++i){
            q.push(nums[i]);
            while(!st.empty() && nums[i]>nums[st.top()]){
                next_greater[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }
        
        for(int i=0; i<n; ++i){
            while(!st.empty() && nums[i]>nums[st.top()]){
                next_greater[st.top()]=nums[i];
                st.pop();
            }
        }

        return next_greater;
    }
};