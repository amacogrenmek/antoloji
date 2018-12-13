// Brute
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        // c'mon
        if (nums.size() == 1) return nums[0];
        // init to smallest finite value
        int res = numeric_limits<int>::min();
        // [i,j]
        for (int i = 0; i < nums.size(); ++i) {
            int runningProduct = 1;
            for (int j = i; j < nums.size(); ++j) {
                runningProduct *= nums[j];
                if (runningProduct > res) res = runningProduct;
            }
        }
        return res;
    }
};

// Gentle
// See: https://leetcode.com/problems/maximum-product-subarray/discuss/203013/C%2B%2B-O(N)-time-O(1)-space-solution-with-explanation
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Return early if empty
        if (nums.empty()) return 0;
        
        int best = INT_MIN;
        // Running products
        int maxProd = 1;
        int minProd = 1;
        
        for (int n: nums) {
            if (n < 0) {
                // Flip max and min
                swap(maxProd, minProd);
            }
            // Reset to current value if smaller or larger than it
            // (intuitively means that we start considering a new sub-array)
            maxProd = max(maxProd*n, n);
            minProd = min(minProd*n, n);
            // Update the best
            best = max(best, maxProd);
        }
        
        return best;
    }
};

// If just positives, product of the entire array
// If also has zeros, sub-array with the largest product
// If also negatives, can flip from max to min, min to max
