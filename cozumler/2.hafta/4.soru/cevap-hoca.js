/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
  var r = nums[0],
    max = r,
    min = r;

  for (var i = 1; i < nums.length; i++) {
    if (nums[i] < 0) {
      var temp = max;
      max = min;
      min = temp;
    }
    max = Math.max(nums[i], max * nums[i]);
    min = Math.min(nums[i], min * nums[i]);
    r = Math.max(r, max);
  }
  return r;
};
