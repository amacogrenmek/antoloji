//
//  main.cpp
//  lc_859_Buddy Strings
//
//  Created by Emre Biyikli on 12/4/18.
//  Copyright © 2018 Emre Biyikli. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() < 2 || B.size() < 2 || A.size() != B.size()) return false;
        int diff_count = 0;
        char a_diff = '0', b_diff = '0';
        for (size_t i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                diff_count++;
                if (diff_count == 1) {
                    a_diff = A[i];
                    b_diff = B[i];
                } else if (diff_count == 2) {
                    if (!(A[i] == b_diff && B[i] == a_diff)) return false;
                } else {
                    return false;
                }
            }
        }
        if (diff_count == 0) {
            if (A.size() > 26) return true;
            vector<int> bins(26,0);
            for (size_t i = 0; i < A.size(); i++) {
                if (++bins[A[i]-97] > 1) return true;
            }
        }
        return diff_count == 2 ? true : false;
    }
};

int main(int argc, const char * argv[]) {
    Solution sln;
    cout << sln.buddyStrings(string("ab"), string("ba")) << endl;
    cout << sln.buddyStrings(string("ab"), string("ab")) << endl;
    cout << sln.buddyStrings(string("aa"), string("aa")) << endl;
    cout << sln.buddyStrings(string("aaaaaaabc"), string("aaaaaaabc")) << endl;
    cout << sln.buddyStrings(string("aaaaaaaaa"), string("aaaaaaaaa")) << endl;
    cout << sln.buddyStrings(string(""), string("aa")) << endl;
    return 0;
}
