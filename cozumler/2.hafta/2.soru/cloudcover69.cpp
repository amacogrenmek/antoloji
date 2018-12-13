class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        // Sort: 1 1 2 2 3 7
        sort(A.begin(), A.end());
        int incs = 0;
        for (int i = 1; i < A.size(); ++i) {
            // Increment each element so that it's at least +1 before prev
            int diff = A[i-1] + 1 - A[i];
            if (diff >= 1) {
                A[i] += diff;
                incs += diff;
            }
        }
        return incs;
    }
};
