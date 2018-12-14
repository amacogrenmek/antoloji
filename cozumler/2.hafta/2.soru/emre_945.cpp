//
//  main.cpp
//  lc_945_Minimum Increment to Make Array Unique
//
//  Created by Emre Biyikli on 12/9/18.
//  Copyright © 2018 Emre Biyikli. All rights reserved.
//

#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int lim = 50000;
    int minIncrementForUnique(vector<int>& A) {
        vector<int> bin(lim,0);
        for (auto & a : A) {
            bin[a]++;
        }
        int move = 0;
        for (int i = 0; i < lim ; i++) {
            if (bin[i] > 1) {
                bin[i+1] += bin[i]-1;
                move += bin[i]-1;
            }
        }
        return move;
    }
};

int main(int argc, const char * argv[]) {
    Solution sln;
    {
        vector<int> A = {1,2,2};
        cout << sln.minIncrementForUnique(A) << endl;
        cout << "Expected: 1" << endl;
    }
    {
        vector<int> A = {3,2,1,2,1,7};
        cout << sln.minIncrementForUnique(A) << endl;
        cout << "Expected: 6" << endl;
    }
    {
        vector<int> A = {};
        cout << sln.minIncrementForUnique(A) << endl;
        cout << "Expected: 0" << endl;
    }
    {
        vector<int> A = {1,1,1,1,1};
        cout << sln.minIncrementForUnique(A) << endl;
        cout << "Expected: 10" << endl;
    }
    return 0;
}
