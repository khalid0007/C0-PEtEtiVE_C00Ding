#include<bits/stdc++.h>
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

// Implementated according to CLRS
#define NILL -1
#define _INFINITY_ INT32_MAX
enum Color : unsigned char {White, Gray, Black}; // Color Assigned to nodes

class Graph{
public:
    vector<int>* Adj;
    int n;
    bool directed;
    
    Graph(int n, bool directed = false) : n(n), directed(directed){
        Adj = new vector<int>[n];
    }

    ~Graph(){delete[] Adj;}


    void connect(int u, int v)
    {
        Adj[u].emplace_back(v);

        if(!directed) Adj[v].emplace_back(u);
    }

    void connect() {
        int u, v; cin >> u >> v;
        // comment it out when needed
        u--; v--;
        Adj[u].emplace_back(v);

        if(!directed) Adj[v].emplace_back(u);
    }
};

class DFS_Graph: public Graph{
public:
    static int time;
    static int topological_indx;
    int* d; // Discovery time array
    int* f; // finish time array
    int* pi; // parent vertex
    int* tpsorted;
    Color* colors;

    DFS_Graph(int n, bool directed = false) : Graph(n, directed) {
        d = new int[n];
        f = new int[n];
        pi = new int[n];
        tpsorted = NULL;
        colors = new Color[n];
    }

    ~DFS_Graph() {
        delete[] d; delete[] f; delete[] pi; delete[] colors;
        if(!tpsorted) delete[] tpsorted;
    }

    void Visit(int u)
    {
        d[u] = ++(DFS_Graph::time);
        colors[u] = Gray;

        for(auto v: Adj[u]){
            if(colors[v] == White){
                pi[v] = u;
                Visit(v);
            }
        }

        if(directed) tpsorted[--(DFS_Graph::topological_indx)] = u;

        colors[u] = Black;
        f[u] = ++(DFS_Graph::time);
        
    }

    void DFS(){
        DFS_Graph::time = 0;
        for(int i = 0; i < n; i++) {
            colors[i] = White;
            pi[i] = NILL;
        }
        
        if(directed)
        {
            tpsorted = new int[n];
            DFS_Graph::topological_indx = n;
        }

        for(int i = 0; i < n; i++) if(colors[i] == White) Visit(i);
    }

};
int DFS_Graph::time = 0;
int DFS_Graph::topological_indx = 0;
