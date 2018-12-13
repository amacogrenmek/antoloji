/**
 * @param {number[]} A
 * @return {number}
 */
var peakIndexInMountainArray = function(A) {
  var high = A.length - 1,
    low = 0,
    mid;
  while (low <= high) {
    var mid = Math.ceil(low + (high - low) / 2);
    if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
      return mid;
    }
    if (A[mid] < A[mid - 1]) high = mid - 1;
    else low = mid + 1;
  }
};
