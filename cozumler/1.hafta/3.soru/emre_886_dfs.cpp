//
//  main.cpp
//  lc_886_Possible Bipartition
//
//  Created by Emre Biyikli on 12/5/18.
//  Copyright © 2018 Emre Biyikli. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

namespace {
    struct Graph {
        Graph(int _vnum) : vnum(_vnum), time(0), is_possible_bipartition(true) {
            adj.resize(vnum);
            color.resize(vnum, 'w');
            parent.resize(vnum, -1);
            visit_time.resize(vnum, std::vector<int>(2, -1));
        }
        int vnum;
        std::vector<std::vector<int>> adj;
        std::vector<char> color;
        std::vector<int> parent;
        std::vector<std::vector<int>> visit_time;
        int time;
        bool is_possible_bipartition;
    };

    void InsertEdge(Graph& g, int src, int tgt) {
        g.adj[src - 1].push_back(tgt - 1);
        g.adj[tgt - 1].push_back(src - 1);
    }

    void InsertEdges(Graph& g, vector<vector<int>>& edges) {
        for (size_t i = 0; i < edges.size(); i++) {
            InsertEdge(g, edges[i][0], edges[i][1]);
        }
    }

    void DSFRecur(Graph& g, int v) {
        g.visit_time[v][0] = ++g.time;
        g.color[v] = 'g';
        for (size_t i = 0; i < g.adj[v].size(); i++) {
            int n = g.adj[v][i];
            if (g.color[n] == 'w') {
                g.parent[n] = v;
                DSFRecur(g, n);
            } else if (g.color[n] == 'g') {
                bool is_parent = g.parent[v] == n;
                bool is_cycle_even = (g.visit_time[v][0] - g.visit_time[n][0]) % 2 == 0;
                if (!is_parent && is_cycle_even) {
                    g.is_possible_bipartition = false;
                }
            }
        }
        g.visit_time[v][1] = ++g.time;
        g.color[v] = 'b';
    }

    void DFS(Graph& g) {
        for (size_t i = 0; i < g.adj.size(); i++) {
            if (g.color[i] == 'w') {
                DSFRecur(g, static_cast<int>(i));
            }
        }
    }
}

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        Graph g(N);
        InsertEdges(g, dislikes);
        DFS(g);
        return g.is_possible_bipartition;
    }
};

int main(int argc, const char * argv[]) {
    Solution sln;
    {
        int N = 4;
        vector<vector<int>> dislikes = {{1,2},{1,3},{2,4}};
        cout << sln.possibleBipartition(N, dislikes) << endl;
    }
    {
        int N = 3;
        vector<vector<int>> dislikes = {{1,2},{1,3},{2,3}};
        cout << sln.possibleBipartition(N, dislikes) << endl;
    }
    {
        int N = 5;
        vector<vector<int>> dislikes = {{1,2},{2,3},{3,4},{4,5},{1,5}};
        cout << sln.possibleBipartition(N, dislikes) << endl;
    }
    {
        int N = 4;
        vector<vector<int>> dislikes = { {1,2},{2,3},{3,4},{4,1} };
        cout << sln.possibleBipartition(N, dislikes) << endl;
    }
    {
        int N = 3;
        vector<vector<int>> dislikes = { {1,2},{2,3},{3,1} };
        cout << sln.possibleBipartition(N, dislikes) << endl;
    }
    {
        int N = 8;
        vector<vector<int>> dislikes = { {1,2},{1,6},{2,3},{2,7},{2,8},{3,4},{4,5},{5,1} };
        cout << sln.possibleBipartition(N, dislikes) << endl;
    }
    {
        int N = 7;
        vector<vector<int>> dislikes = { {1,2},{1,6},{2,3},{2,7},{3,4},{4,5},{5,1} };
        cout << sln.possibleBipartition(N, dislikes) << endl;
    }
    {
        int N = 6;
        vector<vector<int>> dislikes = { {1,2},{1,3},{2,3},{4,5},{4,6},{5,6} };
        cout << sln.possibleBipartition(N, dislikes) << endl;
    }
    return 0;
}
