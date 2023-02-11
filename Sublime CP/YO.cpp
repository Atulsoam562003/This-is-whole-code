#include <bits/stdc++.h>
#define int                long long int
#define ff                 first
#define ss                 second
#define pb                 push_back
#define py                 cout<<"YES\n"
#define pn                 cout<<"NO\n"
#define pimp               cout<<"IMPOSSIBLE\n"
#define pm                    cout<<"-1\n"
#define rep(i,n)           for (int i = 0;i < n;i++)
#define repi(i,x,n)        for (int i = x;i < n;i++)
#define repl(i,n,x)        for (int i = n; i >= x; i--)
#define spi                set <pii>
#define endl               "\n"
#define gcd                __gcd
#define pi                 3.141592653589793238
#define rall(p)            p.end() , p.begin()
#define sz(x)              ((int) x.size())
#define all(p)             p.begin(), p.end()
#define double             long double
#define que_max            priority_queue <int>
#define que_min            priority_queue <int, vector<int>, greater<int>>
#define setbits(x)         __builtin_popcountll(x) 
#define zerobits(x)        __builtin_ctzll(x)
using namespace std;

class DisjointSet {
    vector<int> rank,parent,size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1,0);
        parent.resize(n + 1);
        size.resize(n + 1,1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findUPar(int node) {
        if(node == parent[node]) 
            return node;
        return parent[node] = findUPar(parent[node]); // this is path commpression.
    }
    
    void unionByRank(int u,int v) {
        int ulp_u = parent[u];
        int ulp_v = parent[v];
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) 
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }            
    }
    
    void unionBySize(int u,int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
/*
use :-
    DisjointSet ds(7);
    ds.unionBySize(1,2);
*/  

class Graph {
    vector<vector<int> > edgelist;  
    int V;
public:
    Graph(int V) {
        this->V = V;
    }
    void addEdge(int x,int y,int wt) {
        edgelist.push_back({wt,x,y}); // recommended that wt is in 1st as default sorting easy.
    }
    
    int kruskal_mst() {
        sort(all(edgelist));
        
        DisjointSet ds(V);
        
        int ans = 0;
        for(auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            
            // take that edge in mst if if doesnot form cycle.
            if(ds.findUPar(x) != ds.findUPar(y)) {
                ds.unionBySize(x,y);
                ans += w;
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
        int x,y,wt; cin>>x>>y>>wt;
        g.addEdge(x,y,wt);
    }    
    cout<<g.kruskal_mst()<<endl;
    return 0;
}