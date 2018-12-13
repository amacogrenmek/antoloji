/**
 * Insert interval
 */
/**
 * Definition for an interval.
 * function Interval(start, end) {
 *     this.start = start;
 *     this.end = end;
 * }
 */
/**
 * @param {Interval[]} intervals
 * @param {Interval} newInterval
 * @return {Interval[]}
 */
var insert = function(is, ni) {
  is.push(ni);
  return merge(is);

  function merge(i) {
    if (i.length === 0) return [];
    if (i.length === 1) return i;

    i = i.sort((a, b) => a.start - b.start);

    var res = [],
      start = i[0].start,
      end = i[0].end;

    for (var j = 1; j < i.length; j++) {
      if (i[j].start <= end && i[j].start >= start) {
        end = Math.max(i[j].end, end);
      } else if (i[j].start >= end) {
        res.push(new Interval(start, end));
        start = i[j].start;
        end = i[j].end;
      }
    }

    res.push(new Interval(start, end));

    return res;
  }
};
