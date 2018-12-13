// Using event points
class Solution1 {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        
        vector<int> startTimes;
        vector<int> endTimes;
        int depth = 0;
        
        for (auto const & iv: intervals) {
            startTimes.emplace_back(iv.start);
            endTimes.emplace_back(iv.end);
        }
        
        startTimes.emplace(lower_bound(startTimes.begin(), startTimes.end(), newInterval.start), newInterval.start);
        endTimes.emplace(lower_bound(endTimes.begin(), endTimes.end(), newInterval.end), newInterval.end);
        
        int i = 0, j = 0;
        int curStart = 0;
        int curEnd = 0;
        while(true) {
            
            if (startTimes[i] <= endTimes[j]) {
                // Start an interval
                // Note: This also handles point events or back-to-back events
                if (depth == 0) curStart = startTimes[i];
                ++i;
                ++depth;
            } else if (startTimes[i] > endTimes[j]) {
                // End an interval
                if (depth == 1) curEnd = endTimes[j];
                ++j;
                --depth;
            }
            
            if (depth == 0) {
                // Output
                res.emplace_back(curStart, curEnd);
            }
            
            if (i == startTimes.size()) {
                // Exhausted start times but still in an interval
                if (depth != 0) res.emplace_back(curStart, *endTimes.rbegin());
                break;
            }
        }
        
        return res;
    }
};

// Just iteration and comparison
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        bool inserted = false;
        
        for (int i = 0; i < intervals.size(); ++i) {
            auto const & iv = intervals[i];
            if (iv.end < newInterval.start) {
                // Before new
                res.emplace_back(iv);
            } else if (iv.start > newInterval.end) {
                // After new
                if (!inserted) {
                    res.emplace_back(newInterval);
                    inserted = true;
                }
                res.emplace_back(iv);
                continue;
            } else {
                // Overlapping interval, extend newInterval to swallow this one
                newInterval.start = min(iv.start, newInterval.start);
                newInterval.end = max(iv.end, newInterval.end);
            }
        }
        if (!inserted) res.emplace_back(newInterval);
        
        return res;
    }
};
