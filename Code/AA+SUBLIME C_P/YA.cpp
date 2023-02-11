#include <bits/stdc++.h>
using namespace std;

#define first ff
#define second ss

const int N = 1e9 + 7;
const int INF = INT_MAX;

vector<int> bellman_ford(int V,int src,vector<vector<int>> &edges) {
    vector<int> dist(V + 1,INT_MAX);
    dist[src] = 0;
    
    for(int i = 0; i < V - 1; i++) {
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            if(dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt; // this is relaxatition step.
            }
        }
    }
    // negative wieght cycle detection.
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if(dist[u] + wt < dist[v]) { // again wt is becoming less.
            cout<<"Negative Weight Cycle found!\n";
            exit(0);
        }        
    }
    return dist;
}

void solve() {
    int n,m; cin>>n>>m;
    
    vector<vector<int>> edges;
    
    for(int i = 0; i < m; i++) {
        int u,v,wt; cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    vector<int> distances = bellman_ford(n,1,edges);
    for(int i = 1; i <= n; i++) {
        cout<<"Node "<<i<<" is at dist "<<distances[i]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    clock_t z = clock();

    int t = 1,i = 1;
    // cin >> t;
    while (t--){  
          // cout<<"Case #"<<i++<<": "; 
          solve();    
    }

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}