/**
 * @param {string} A
 * @param {string} B
 * @return {boolean}
 */
var buddyStrings = function(A, B) {
  var a = [],
    b = [],
    map = {};
  if (A === B) {
    for (var i = 0; i < A.length; i++) {
      if (map[A[i]]) return true;
      map[A[i]] = 1;
    }
    return false;
  }
  for (var i = 0; i < A.length; i++) {
    if (A[i] != B[i]) {
      a.push(A[i]);
      b.push(B[i]);
    }
  }
  if (a.length === 2 && a[0] === b[1] && a[1] === b[0]) return true;
  else return false;
};
