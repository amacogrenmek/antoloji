#include <math.h>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <utility>
#include <memory>

using namespace std;

struct Range {
  int begin; 
  int end; 
    
  Range(int b, int e) : begin(b), end(e) {}
    
  bool operator==(const Range& other) const {
    return ((begin == other.begin) && (end == other.end));
  }
};

struct hashRange {
  size_t operator()(const Range& r) const {
    return ((hash<int>()(r.begin) << sizeof(int)) ^ hash<int>()(r.end));
  }
};

class Solution {
  unordered_map<Range, int, hashRange> memo;
public:
  int maxProduct(vector<int>& nums) {
        
    for(int i = 0; i < nums.size(); ++i) {
      for(int j = nums.size() - 1; j >= i; --j) {
	Range range(i, j);
	int res = getProd(range, nums);
	memo[range] = res;
      }
    }
        
    int max = INT_MIN;
    for (auto e : memo) {
      if (e.second > max)
	max = e.second;
    }
        
    return max;
  }
    
  int getProd(Range& r, vector<int>& A) {
    if (memo.find(r) != memo.end()) {
      return memo[r];
    }
    else if (r.end - r.begin == 0) {
      memo[r] = A[r.begin];
      return A[r.begin];
    }
    else {
      Range next(r.begin + 1, r.end);
      memo[r] = A[r.begin] * getProd(next, A);
      return memo[r];
    }
  }
};
