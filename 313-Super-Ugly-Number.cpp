class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k=primes.size();
        vector<long long int> idx(k, 0), ugly(n, INT_MAX);
        ugly[0] = 1;
        for(int i=1; i<n; i++) {
            for(int j=0; j<k; j++) {
                ugly[i] = min(ugly[i], ugly[idx[j]]*primes[j]);
            }
            for(int j=0; j<k; j++) {
                idx[j] += ugly[i]==(ugly[idx[j]]*primes[j]);
            }
        }
        return ugly[n-1];
    }
};