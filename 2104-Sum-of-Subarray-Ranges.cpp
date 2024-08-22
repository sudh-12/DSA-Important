class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        vector<int> prev_small(n,-1);
        vector<int> next_small(n,n);
        vector<int> prev_large(n,-1);
        vector<int> next_large(n,n);
        stack<int> st;
        long long ans=0;

// find next smallest element index
        for(int i=0; i<n; ++i){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                next_small[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty())
        st.pop();

        // find prev smallest element index
        for(int i=n-1; i>=0; --i){
            while(!st.empty() && arr[i]<arr[st.top()]){
                prev_small[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

         while(!st.empty())
        st.pop();

        // find next large element index

        for(int i=0; i<n; ++i){
            while(!st.empty() && arr[i]>=arr[st.top()]){
                next_large[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

         while(!st.empty())
        st.pop();

        // find prev large element index

        for(int i=n-1; i>=0; --i){
            while(!st.empty() && arr[i]>arr[st.top()]){
                prev_large[st.top()]=i;
                st.pop();
            }

            st.push(i);
        }

        for(int i=0; i<n; ++i){
            long long prev_large_dist = i-prev_large[i];
            long long next_large_dist = next_large[i]-i;
            long long prev_small_dist = i-prev_small[i];
            long long next_small_dist = next_small[i]-i;
            ans+=((prev_large_dist)*(next_large_dist)- (prev_small_dist) *(next_small_dist))*arr[i];
        }

        return ans;
    }
};