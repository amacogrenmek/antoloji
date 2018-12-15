class Solution {
public:
  int minIncrementForUnique(vector<int>& A) {
    array<int,40000> counts; 
    counts.fill(0);
    for (auto e : A) {
      counts[e] += 1;
    }
    
    int c, incr = 0; 
    queue<int> multi;
    for (size_t i = 0; i < counts.size(); i++) {
      c = counts[i];
      if (c == 1)
	continue;
      
      if (c > 1) {
	multi.emplace(i);
      }
      
      if (c == 0 && !multi.empty()) {
	int f = multi.front();
	counts[i]++;
	incr += i - f; 
	if (--counts[f] == 1)
	  multi.pop();
      }
    }
    
    return incr; 
  }
};
