var largestTimeFromDigits = function(A) {
  var res = "00:00",
    used = new Array(A.length);

  A = A.sort((a, b) => a - b);
  helper([], used);

  return res === "00:00" && A.join("") != "0000" ? "" : res;

  function helper(temp, used) {
    if (temp.length === A.length) {
      var t = isCorrectFormat(res, temp);
      res = t === "" ? res : t;
    } else {
      for (var i = 0; i < A.length; i++) {
        if (used[i]) continue;

        if (i > 0 && A[i - 1] == A[i] && !used[i - 1]) continue;

        used[i] = true;
        temp.push(A[i]);
        helper(temp, used);
        used[i] = false;
        temp.pop();
      }
    }
  }
};

function isCorrectFormat(res, temp) {
  var newRes = "";
  var hr = temp[0].toString() + temp[1].toString();
  var mn = temp[2].toString() + temp[3].toString();

  if (hr >= "24" || mn > "59") return "";

  if (hr >= res.split(":")[0]) {
    newRes += hr + ":";
  } else {
    return "";
  }
  if (newRes != "" || mn >= res.split(":")[1]) {
    newRes += mn;
  } else {
    return "";
  }
  return newRes;
}
