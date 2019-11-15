#include<bits/stdc++.h>
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

// Implementated according to CLRS
#define NILL -1
#define _INFINITY_ INT32_MAX
class BFS_Graph{
public:
    vector<int>* Adj; // Adjacency List
    int* d; // Distance from s(source)
    int* pi; // parent of certain node as appears in BFS search
    char* color; // Color of node during BFS (It can be White(w), Gray(g), Black(b))
    int searched_from;
    int n;
    bool directed;

    BFS_Graph(int n, int directed = false): n(n), directed(directed)
    {
        Adj = new vector<int>[n];
        d = new int[n];
        pi = new int[n];
        color = new char[n + 1];
        color[n] = '\0';
        searched_from = -1;
    }

    ~BFS_Graph()
    {
        delete[] Adj; // De-allocate all memories
        delete[] d;
        delete[] pi;
        delete[] color;
    }

    void connect(int u, int v)
    {
        Adj[u].emplace_back(v);

        if(!directed) Adj[v].emplace_back(u);
    }

    void connect() {
        int u, v; cin >> u >> v;
        // comment it out when needed\
        u--; v--;
        Adj[u].emplace_back(v);

        if(!directed) Adj[v].emplace_back(u);
    }

    void BFS(int source) // s is source
    {
        if(searched_from == source) return;
        if(source >= sizeof(Adj));

        for(int i = 0; i < n; i++) {
            *(color + i) = 'w';
            pi[i] = NILL;
            d[i] = _INFINITY_;
        }

        color[source] = 'g';
        queue<int> q;
        q.push(source);
        d[source] = 0;

        while(!q.empty()){
            int node = q.front(); q.pop();

            for(auto it: Adj[node])
            {
                if(color[it] == 'w'){
                    color[it] = 'g';
                    d[it] = d[node] + 1;
                    pi[it] = node;
                    q.push(it);
                }
            }

            color[node] = 'b';
        }

        searched_from = source;
    }

    void Print_Path(int source, int destination, int system_called = false)
    {
        if(source == destination) {
            if(system_called) cout << destination << " -> ";
            else cout << destination << endl;
        }

        else if(pi[destination] == NILL) cout << "No path from " << source << " to " << destination << " exits.\n";

        else{
            Print_Path(source, pi[destination], true);
            if(system_called) cout << destination << " -> ";
            else cout << destination << endl;
        }
    }
};

int main()
{
    BFS_Graph a(8);

    for(int i = 0; i < 10; i++) a.connect();

    a.BFS(0);

    a.Print_Path(0, 6);

    return 0;
}
