//

#include <iostream>
#include <queue>
#include <vector>

struct Graph {
    Graph(int _vnum) : vnum(_vnum), is_bipartite(true) {
        adj.resize(vnum);
        color.resize(vnum, 'w');
        parent.resize(vnum, -1);
        bp_color.resize(vnum, '0');
    }
    int vnum;
    std::vector<std::vector<int>> adj;
    std::vector<char> color;
    std::vector<int> parent;
    std::vector<char> bp_color;
    bool is_bipartite;
};

void InsertEdge(Graph& g, int src, int tgt) {
    g.adj[src - 1].push_back(tgt - 1);
    g.adj[tgt - 1].push_back(src - 1);
}

void BFS(Graph& g, int s) {
    std::queue<int> q;  // Invariant: queue holds gray vertices
    g.color[s] = 'g';
    q.push(s);
    g.bp_color[s] = 'r';  // Paint when pushing
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        g.color[v] = 'b';
        for (size_t i = 0; i < g.adj[v].size(); i++) {
            int n = g.adj[v][i];
            if (g.color[n] == 'w') {
                g.color[n] = 'g';
                q.push(n);
                g.parent[n] = v;
                g.bp_color[n] = g.bp_color[v] == 'r' ? 'b' : 'r';
            } else {
                bool is_parent = g.parent[v] == n;
                bool is_same_bp_color = g.bp_color[v] == g.bp_color[n];
                if (!is_parent && is_same_bp_color) {
                    g.is_bipartite = false;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    {
        Graph g(4);
        InsertEdge(g, 1, 2);
        InsertEdge(g, 1, 3);
        InsertEdge(g, 2, 4);
        std::cout << "Expecting: yes" << std::endl;
        BFS(g, 0);
        std::cout << g.is_bipartite << std::endl;
    }
    {
        Graph g(3);
        InsertEdge(g, 1, 2);
        InsertEdge(g, 1, 3);
        InsertEdge(g, 2, 3);
        std::cout << "Expecting: no" << std::endl;
        BFS(g, 0);
        std::cout << g.is_bipartite << std::endl;
    }
    {
        Graph g(5);
        InsertEdge(g, 1, 2);
        InsertEdge(g, 2, 3);
        InsertEdge(g, 3, 4);
        InsertEdge(g, 4, 5);
        InsertEdge(g, 5, 1);
        std::cout << "Expecting: no" << std::endl;
        BFS(g, 0);
        std::cout << g.is_bipartite << std::endl;
    }
    {
        Graph g(4);
        InsertEdge(g, 1, 2);
        InsertEdge(g, 2, 3);
        InsertEdge(g, 3, 4);
        InsertEdge(g, 4, 1);
        std::cout << "Expecting: yes" << std::endl;
        BFS(g, 0);
        std::cout << g.is_bipartite << std::endl;
    }
    {
        Graph g(3);
        InsertEdge(g, 1, 2);
        InsertEdge(g, 2, 3);
        InsertEdge(g, 3, 1);
        std::cout << "Expecting: no" << std::endl;
        BFS(g, 0);
        std::cout << g.is_bipartite << std::endl;
    }
    {
        Graph g(8);
        InsertEdge(g, 1, 2);
        InsertEdge(g, 1, 6);
        InsertEdge(g, 2, 3);
        InsertEdge(g, 2, 7);
        InsertEdge(g, 2, 8);
        InsertEdge(g, 3, 4);
        InsertEdge(g, 4, 5);
        InsertEdge(g, 5, 1);
        std::cout << "Expecting: no" << std::endl;
        BFS(g, 0);
        std::cout << g.is_bipartite << std::endl;
    }
    {
        Graph g(7);
        InsertEdge(g, 1, 2);
        InsertEdge(g, 1, 6);
        InsertEdge(g, 2, 3);
        InsertEdge(g, 2, 7);
        InsertEdge(g, 3, 4);
        InsertEdge(g, 4, 5);
        InsertEdge(g, 5, 1);
        std::cout << "Expecting: no" << std::endl;
        BFS(g, 0);
        std::cout << g.is_bipartite << std::endl;
    }
    {
        Graph g(6);
        InsertEdge(g, 1, 2);
        InsertEdge(g, 1, 3);
        InsertEdge(g, 2, 3);
        InsertEdge(g, 4, 5);
        InsertEdge(g, 4, 6);
        InsertEdge(g, 5, 6);
        std::cout << "Expecting: no" << std::endl;
        BFS(g, 0);
        std::cout << g.is_bipartite << std::endl;
    }
    return 0;
}
