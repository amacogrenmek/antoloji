bool operator> (vector<int> const & a, vector<int> const & b) {
    if (a.empty() && b.empty()) return false;
    if (a.empty()) return false;
    if (b.empty()) return true;
    static vector<int> multipliers = {10*60, 60, 10, 1};
    int aSum = 0;
    int bSum = 0;
    for (int i = 0; i < 4; ++i) {
        aSum += a[i] * multipliers[i];
        bSum += b[i] * multipliers[i];
    }
    return aSum > bSum;
}

// Using backtracking
class Solution1 {
public:
    string largestTimeFromDigits(vector<int>& A) {
        auto res = backtrack(vector<int>{}, A);
        if (res.empty()) return {};
        ostringstream os;
        os << res[0] << res[1] << ":" << res[2] << res[3];
        return os.str();
    }
    
    // Note: Could use a `used` set instead of erasing from vector,
    // but nums is too small to worry about this
    vector<int> backtrack(vector<int> hr, vector<int> nums) {
        if (nums.empty()) {
            if (hr.size() == 4) return hr;
            return {};
        }
        
        int lim;
        if (hr.size() == 0) {
            lim = 2;
        } else if (hr.size() == 1) {
            lim = (hr[0] < 2) ? 9 : 3;
        } else if (hr.size() == 2) {
            lim = 5;
        } else {
            lim = 9;
        }
        
        vector<int> res;
        for (int n: nums) {
            if (n <= lim) {
                // Erase n from nums
                auto nums2 = nums;
                nums2.erase(find(nums2.begin(), nums2.end(), n));
                // Add n to hr
                auto hr2 = hr;
                hr2.emplace_back(n);
                // recurse
                auto res2 = backtrack(hr2, nums2);
                // ignore if invalid
                if (res2.size() != 4) continue;
                // pick best
                if (res2 > res) res = res2;
            }
        }
        return res;
    }
};

// Brute force
class Solution2 {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> res;
        
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (i == j) continue;
                for (int k = 0; k < 4; ++k) {
                    if (i == k || j == k) continue;
                    for (int l = 0; l < 4; ++l) {
                        if (i == l || j == l || k == l) continue;
                        int hr = A[i]*10 + A[j];
                        if (hr > 23) continue;
                        int min = A[k]*10 + A[l];
                        if (min > 59) continue;
                        
                        vector<int> candidate{A[i], A[j], A[k], A[l]};
                        if (candidate > res) res = candidate;
                    }
                }
            }
        }
        
        if (res.empty()) return {};
        ostringstream os;
        os << res[0] << res[1] << ":" << res[2] << res[3];
        return os.str();
    }
};


// STL
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> res;
        vector<int> candidate = A;
        
        // must be sorted for next_permitation to work
        sort(candidate.begin(), candidate.end());
        do {
            int hr = candidate[0]*10 + candidate[1];
            if (hr > 23) continue;
            int min = candidate[2]*10 + candidate[3];
            if (min > 59) continue;
            if (candidate > res) res = candidate;
        } while (next_permutation(candidate.begin(), candidate.end()));
        
        if (res.empty()) return {};
        ostringstream os;
        os << res[0] << res[1] << ":" << res[2] << res[3];
        return os.str();
    }
};
