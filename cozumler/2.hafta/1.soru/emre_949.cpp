//
//  main.cpp
//  lc_949_Largest Time for Given Digits
//
//  Created by Emre Biyikli on 12/8/18.
//  Copyright © 2018 Emre Biyikli. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isLegal(vector<int>& A) {
        if (10*A[0]+A[1] > 23) return false;
        if (10*A[2]+A[3] > 59) return false;
        return true;
    }
    
    string largestTimeFromDigits(vector<int>& A) {
        int best = -1;
        vector<int> bestVec;
        sort(A.begin(),A.end());
        do {
            if (isLegal(A)) {
                int temp = 1000*A[0]+100*A[1]*10*A[2]+A[3];
                best = max(best,temp);
                bestVec = A;
            }
        } while (std::next_permutation(A.begin(),A.end()));
        if (best == -1) {
            return std::string();
        } else {
            return to_string(bestVec[0]) + to_string(bestVec[1]) + ":" + to_string(bestVec[2]) + to_string(bestVec[3]);
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution sln;
    vector<int> v = {1,2,3,4};
    cout << sln.largestTimeFromDigits(v) << endl;
    v = {5,5,5,5};
    cout << sln.largestTimeFromDigits(v) << endl;
    v = {5,9,3,2};
    cout << sln.largestTimeFromDigits(v) << endl;
    v = {0,0,1,0};
    cout << sln.largestTimeFromDigits(v) << endl;
    v = {0,0,0,0};
    cout << sln.largestTimeFromDigits(v) << endl;
    return 0;
}
