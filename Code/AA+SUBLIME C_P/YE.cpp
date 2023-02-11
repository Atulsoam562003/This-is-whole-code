#include <bits/stdc++.h>
#define ff                 first
#define ss                 second
using namespace std;

class Graph {
    vector<pair<int, int>>  *l;
    int V;
public :
    Graph(int n) {
        V = n;
        l = new vector<pair<int, int>> [n]; // {node,weight}
    }
    void addEdge(int x,int y,int wt) {
        l[x].push_back({y,wt});
        l[y].push_back({x,wt});
    }
    
    int prim_mst() {
        // this is min heap
        priority_queue<pair<int,int>,vector<pair<int, int>> ,greater<pair<int,int> > > Q;
        
        bool * vis = new bool[V]{0};
        int ans = 0;
        
        Q.push({0,0}); // {weight,node->next}
        while(!Q.empty()) {
            // pick out the edge with min wt.
            auto best = Q.top();
            Q.pop();
            
            int to = best.ss;
            int weight = best.ff; // this PQ is sorted according to wt.
            
            if(vis[to]) continue; // discard it and continue;
            
            // otherwise take the current edge.
            ans += weight;
            vis[to] = 1;
            
            // add the new edges in the queue;
            for(auto x : l[to]) {
                if(!vis[x.ff])
                    Q.push({x.ss,x.ff}); // in queue x.ss is pushing first.
            }            
        }
        return ans;
    }
};

int32_t main()
{
    int n,m; cin>>n>>m;
    Graph g(n);
    
    for(int i = 0; i < m; i++) {
        int x,y,w; cin>>x>>y>>w;
        g.addEdge(x - 1,y - 1,w);
    }
    cout<<g.prim_mst()<<endl;    
}   