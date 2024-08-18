class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes={2,3,5};
        unordered_set<long long> st;
        priority_queue<long, vector<long> , greater<long>> pq;
        pq.push(1);
        st.insert(1);

        long long cur=1;

        for(int i=0; i<n; ++i){
            cur=pq.top();
            pq.pop();

            for( int prime: primes){
                long long ugly= cur * prime;

                if(st.find(ugly)==st.end()){
                    st.insert(ugly);
                    pq.push(ugly);
                }
            }
        }

        return (int)cur;
    }
};