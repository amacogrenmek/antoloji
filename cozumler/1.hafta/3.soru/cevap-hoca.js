/**
 * @param {number} N
 * @param {number[][]} dislikes
 * @return {boolean}
 */
var possibleBipartition = function(N, d) {
  var graph = {},
    color = {};
  for (var i = 0; i < d.length; i++) {
    if (!graph[d[i][0]]) {
      graph[d[i][0]] = [];
    }
    graph[d[i][0]].push(d[i][1]);

    if (!graph[d[i][1]]) {
      graph[d[i][1]] = [];
    }
    graph[d[i][1]].push(d[i][0]);
  }
  for (var i = 1; i <= N; i++) {
    if (!color[i] && !dfs(i, 0)) {
      return false;
    }
  }

  function dfs(node, c) {
    if (color[node] != undefined) return color[node] === c;
    color[node] = c;
    if (graph[node]) {
      for (var i = 0; i < graph[node].length; i++) {
        if (graph[node][i] && !dfs(graph[node][i], c ^ 1)) {
          return false;
        }
      }
    }
    return true;
  }

  return true;
};
