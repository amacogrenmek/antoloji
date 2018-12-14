class Solution {
  std::array<bool, 4>  used;
public:
  /**
   * Return max number <= to ceil. If found mark the number used.
   *
   * @param A vector to be searched
   * @param ceil the highest val that can be returned
   * @return max value
   */
  int releaseMax(vector<int>& A, int ceil) {
    int max = -1;
    int pos = -1;
    for (size_t i = 0; i < A.size(); i++) {
      if (!used[i] && A[i] > max && A[i] <= ceil) { 
	max = A[i];
	pos = i;
      }
    }
        
    if (pos >= 0)
      used[pos] = true;
        
    return max;
  }
    
    
  string largestTimeFromDigits(vector<int>& A) {
    used.fill(false);
        
    std::string time = "";
        
    array<int, 4> v;
        
    v[0] = releaseMax(A, 2);
    if (v[0] < 0) return "";

    if (v[0] == 2) {
      v[1] = releaseMax(A, 3);
      if (v[1] < 0) return "";
    }
    else {
      v[1] = releaseMax(A, 9);
    }
        
    v[2] = releaseMax(A, 5);
    if (v[2] < 0) {
      // try relaxing first constraint
      used.fill(false);
      v[0] = releaseMax(A, 1);
      v[1] = releaseMax(A, 9);
      v[2] = releaseMax(A, 5);
    }
        
    v[3] = releaseMax(A, 9);       
        
    if (v[0] < 0 || 
            v[1] < 0 ||
            v[2] < 0 ||
	v[3] < 0)
      return "";
        
    time += std::to_string(v[0]);
    time += std::to_string(v[1]);
    time += ":";
    time += std::to_string(v[2]);
    time += std::to_string(v[3]);
        
        
    return time;
  }
};
