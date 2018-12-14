//
//  main.cpp
//  lc_852_Peak Index in a Mountain Array
//
//  Created by Emre Biyikli on 12/4/18.
//  Copyright © 2018 Emre Biyikli. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0;
        int u = static_cast<int>(A.size())-1;
        while (true) {
            if (u == l) return u;
            if (u-l == 1) {
                if (A[l] < A[u]) {
                    return u;
                } else {
                    return l;
                }
            }
            int m = (u+l)/2;
            if (A[m] < A[m+1]) {  // m will never be equal to u
                l = m;
            } else {
                u = m;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution sln;
    vector<int> in1 = {0, 1, 0};
    cout << sln.peakIndexInMountainArray(in1) << endl;
    vector<int> in2 = {0, 2, 1, 0};
    cout << sln.peakIndexInMountainArray(in2) << endl;
    vector<int> in3 = {0, 1, 2, 3, 4};
    cout << sln.peakIndexInMountainArray(in3) << endl;
    vector<int> in4 = {5, 3, 1};
    cout << sln.peakIndexInMountainArray(in4) << endl;
    return 0;
}
