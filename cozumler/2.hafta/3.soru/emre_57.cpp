//
//  main.cpp
//  lc_57_Insert Interval
//
//  Created by Emre Biyikli on 12/8/18.
//  Copyright © 2018 Emre Biyikli. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        // Empty intervals
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        // Out of bounds
        if (newInterval.end < intervals[0].start) {
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        if (newInterval.start > intervals[intervals.size()-1].end) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        // One interval
        if (intervals.size() == 1) {
            return {{min(intervals[0].start,newInterval.start),max(intervals[0].end,newInterval.end)}};
        }
        
        // Find left and right
        int left = -1, right = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval.start >= intervals[i].start) left = i;
            if (newInterval.end > intervals[i].end) right = i+1;
        }
        
        // Remove in between
        vector<Interval> out = intervals;
        if (right - left > 1) {
            auto it = out.erase(out.begin()+left+1, out.begin()+right);
            right = it - out.begin();
        }
        
        // Merge left
        bool is_merge_left = false;
        if (newInterval.start <= out[left].end && newInterval.start >= out[left].start) {
            newInterval.start = out[left].start;
            is_merge_left = true;
        }
        // Merge right
        bool is_merge_right = false;
        if (newInterval.end >= out[right].start && newInterval.end <= out[right].end) {
            newInterval.end = out[right].end;
            is_merge_right = true;
        }
        
        // Erase
        vector<Interval>::iterator it = out.begin()+right;
        if (is_merge_left || is_merge_right) {
            if (left == right) {
                it = out.erase(out.begin()+left, out.begin()+left+1);
            } else {
                int erase_left = is_merge_left ? left : left+1;
                int erase_right = is_merge_right ? right : right-1;
                it = out.erase(out.begin()+erase_left, out.begin()+erase_right+1);
            }
        }
        
        // Insert
        out.insert(it, newInterval);
        
        //
        return out;
    }
};

void PrintIntervals(vector<Interval> intervals, std::string name) {
    cout << name << ": ";
    for (auto& interval : intervals) {
        cout << "{" << interval.start << "," << interval.end << "} ";
    }
    cout << endl;
}

bool IsSame(vector<Interval> actual, vector<Interval> expected) {
    bool is_same = true;
    for (size_t i = 0; i < actual.size(); i++) {
        if (actual[i].start != expected[i].start) is_same = false;
        if (actual[i].end != expected[i].end) is_same = false;
    }
    if (!is_same) {
        cout << "Mismatch!" << endl;
        PrintIntervals(actual, "Actual");
        PrintIntervals(expected, "Expected");
    }
    return is_same;
}

int main(int argc, const char * argv[]) {
    Solution sln;
    {
        vector<Interval> intervals = {{1,3},{6,9}};
        Interval newInterval = {2,5};
        vector<Interval> expected = {{1,5},{6,9}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
        Interval newInterval = {4,8};
        vector<Interval> expected = {{1,2},{3,10},{12,16}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
        Interval newInterval = {2,8};
        vector<Interval> expected = {{1,10},{12,16}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{4,8}};
        Interval newInterval = {5,6};
        vector<Interval> expected = {{4,8}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{4,8}};
        Interval newInterval = {1,3};
        vector<Interval> expected = {{1,3},{4,8}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
        ;
    }
    {
        vector<Interval> intervals = {{4,8}};
        Interval newInterval = {1,4};
        vector<Interval> expected = {{1,8}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{4,8}};
        Interval newInterval = {1,6};
        vector<Interval> expected = {{1,8}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{4,8}};
        Interval newInterval = {9,12};
        vector<Interval> expected = {{4,8},{9,12}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{4,8}};
        Interval newInterval = {8,12};
        vector<Interval> expected = {{4,12}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{4,8}};
        Interval newInterval = {6,12};
        vector<Interval> expected = {{4,12}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{4,8},{12,16}};
        Interval newInterval = {1,3};
        vector<Interval> expected = {{1,3},{4,8},{12,16}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{4,8},{12,16}};
        Interval newInterval = {1,4};
        vector<Interval> expected = {{1,8},{12,16}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{4,8},{12,16}};
        Interval newInterval = {8,10};
        vector<Interval> expected = {{4,10},{12,16}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{4,8},{12,16}};
        Interval newInterval = {9,10};
        vector<Interval> expected = {{4,8},{9,10},{12,16}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{4,8},{12,16}};
        Interval newInterval = {10,12};
        vector<Interval> expected = {{4,8},{10,16}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{4,8},{12,16}};
        Interval newInterval = {16,20};
        vector<Interval> expected = {{4,8},{12,20}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{4,8},{12,16}};
        Interval newInterval = {18,20};
        vector<Interval> expected = {{4,8},{12,16},{18,20}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals;
        Interval newInterval = {5,7};
        vector<Interval> expected = {{5,7}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{1,2}};
        Interval newInterval;
        vector<Interval> expected = {{0,0},{1,2}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{1,5},{6,8}};
        Interval newInterval = {0,9};
        vector<Interval> expected = {{0,9}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    {
        vector<Interval> intervals = {{2,13},{16,21}};
        Interval newInterval = {19,22};
        vector<Interval> expected = {{2,13},{16,22}};
        vector<Interval> actual = sln.insert(intervals, newInterval);
        if (IsSame(actual, expected)) {
            PrintIntervals(actual,"Actual");
        }
    }
    return 0;
}
