class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
        int n = A.size(), beg = -1, end = -2,
         mn = A[n - 1], mx = A[0];
         //start from 1st index
        for (int i = 1; i < n; i++) {
            mx = max(mx, A[i]);
            mn = min(mn, A[n - 1 - i]);
            //take the min value from left which is less than the max value till now
            if (A[i] < mx)
                end = i;
        //take max value from right which is greater than the min value till now
            if (A[n - 1 - i] > mn)
                beg = n - 1 - i;
        }
        return end - beg + 1;
    }
};

// At the first glance I thought it's a bit confusing given that "end" is updated from the left and "start" is updated from the right. It could be understood more easily in this way:
// It's not difficult to understand that the max value of the subarray need to be smaller than the min of the rightmost sorted subarray, and the min value of the subarray need to be larger than the max of the leftmost sorted subarray. Therefore we care about the max value counted from the left (and the min value counted from the right).

// The other important fact is that whenever we come across a value A[i] that is smaller than the current max, we know that the unsorted subarray AT LEAST needs to end here. Similarly, whenever we come across a value A[n-1-i] that is larger than the current min, we know that the unsorted subarray AT LEAST needs to start here.