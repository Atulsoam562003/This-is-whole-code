#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long int
#define len(s) s.length()
#define rep(i,n) for (int i=0;i<n;i++)
#define repi(i,x,n) for (int i=x;i<n;i++)
#define br cout<<endl
#define pb push_back
#define endl '\n'
#define INF 1e18
#define mod 1e9+7
#define py cout<<"YES\n";
#define pn cout<<"NO\n";
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;

ll n,ans; string s;
vector<ll> root;
vector<bool> check;
vector<vector<ll>> graph;
    
pair<ll,ll>dfs(ll root){
    if(check[root]){
        return {0,0};
    }
    check[root] = true;
    ll b = 0,w = 0;
    if(s[root - 1] == 'B'){
        b++;
    }else w++;
    
    rep(i,graph[root].size()){
        if(check[graph[root][i]] == false){
            pair<ll,ll> temp = dfs(graph[root][i]);
            b += temp.ff;
            w += temp.ss;
        }
    }
    if(b == w){
        ans++;
    }
    return {b,w};
}

void solve(){
    cin>>n;
    root.resize(n+1,0);
    graph.resize(n+1,vector<ll>());
    check.resize(n+1,false);
    root[1] = 1;
    
    repi(i,2,n+1){
        cin>>root[i];
        graph[root[i]].push_back(i);
        graph[i].push_back(root[i]);
    }
    cin>>s;
    ans = 0;
    dfs(1);
    
    cout<<ans<<endl;
    s.clear();
    ans = n = 0;
    graph.clear() , root.clear(), check.clear();
}

int main(){
        fastio;  
    int t; cin>>t;
    while(t--){
    solve();
    }
}   