//
//  main.cpp
//  lc_152_Maximum Product Subarray
//
//  Created by Emre Biyikli on 12/8/18.
//  Copyright © 2018 Emre Biyikli. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int ThreeMax(int a, int b, int c) {
        return (max(max(a,b),c));
    }
    
    int middleCrossing(vector<int>& nums, int l, int m, int r) {
        if (nums[m] == 0) return 0;
        int mmax = 0;
        int lhp = nums[m-1];
        int lhn = nums[m-1];
        int prod = nums[m-1];
        for (int i = m-2; i >= l; i--) {
            prod *= nums[i];
            if (prod > lhp) lhp = prod;
            if (prod < lhn) lhn = prod;
        }
        int rhp = nums[m];
        int rhn = nums[m];
        prod = nums[m];
        for (int i = m+1; i < r; i++) {
            prod *= nums[i];
            if (prod > rhp) rhp = prod;
            if (prod < rhn) rhn = prod;
        }
        mmax = lhp*rhp;
        if (lhn*rhn > mmax) mmax = lhn*rhn;
        return mmax;
    }
    
    int maxProductRecur(vector<int>& nums, int l, int r) {
        if (r-l == 1) return nums[l];
        if (r-l == 2) {
            return ThreeMax(nums[l],nums[r-1],nums[l]*nums[r-1]);
        }
        //
        int m = (l+r)/2;
        int lmax = maxProductRecur(nums,l,m);
        int rmax = maxProductRecur(nums,m,r);
        //
        int mmax = middleCrossing(nums, l, m, r);
        //
        return ThreeMax(lmax, rmax, mmax);
    }
    
    int maxProduct(vector<int>& nums) {
        return maxProductRecur(nums, 0, nums.size());
    }
};

int main(int argc, const char * argv[]) {
    Solution sln;
    {
        vector<int> nums = {0,-2,0};
        int actual = sln.maxProduct(nums);
        cout << actual << " 0" << endl;
    }
    {
        vector<int> nums = {2,3,-2,4};
        int actual = sln.maxProduct(nums);
        cout << actual << " 6" << endl;
    }
    {
        vector<int> nums = {-2,0,-1};
        int actual = sln.maxProduct(nums);
        cout << actual << " 0" << endl;
    }
    {
        vector<int> nums = {-2,-4,0,-1};
        int actual = sln.maxProduct(nums);
        cout << actual << " 8" << endl;
    }
    {
        vector<int> nums = {-2,-4,-3,0,-1};
        int actual = sln.maxProduct(nums);
        cout << actual << " 12" << endl;
    }
    {
        vector<int> nums = {-2,-4,-3,0,-1,-30};
        int actual = sln.maxProduct(nums);
        cout << actual << " 30" << endl;
    }
    {
        vector<int> nums = {2};
        int actual = sln.maxProduct(nums);
        cout << actual << " 2" << endl;
    }
    {
        vector<int> nums = {1,1,2,4};
        int actual = sln.maxProduct(nums);
        cout << actual << " 8" << endl;
    }
    {
        vector<int> nums = {2,4,1,1};
        int actual = sln.maxProduct(nums);
        cout << actual << " 8" << endl;
    }
    return 0;
}
