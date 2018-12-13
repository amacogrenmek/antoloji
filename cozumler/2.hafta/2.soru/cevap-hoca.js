/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
  var A = A.sort((a, b) => a - b);
  var res = 0;
  for (var i = 0; i < A.length; i++) {
    if (A[i] <= A[i - 1]) {
      res += A[i - 1] - A[i] + 1;
      A[i] = A[i - 1] + 1;
    }
  }
  return res;
};
