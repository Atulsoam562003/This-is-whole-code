/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/

#include <bits/stdc++.h>
using namespace std;

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
#define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.ff << " " << x.ss << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int lcm(int a,int b) {return (a/gcd(a,b)*b);}
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return a.ss < b.ss;}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return a.ss > b.ss;}

string decToBinary(int n){
    string s="";int i=0;while(n>0){s = to_string(n % 2)+ s; n /= 2;i++;}
    return s;}

int binaryToDecimal(string n){
    string num = n;int dec_value = 0;int base = 1;int len = num.length();
    for(int i = len - 1; i >= 0; i--){
    if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

bool isPrime(int n) {
    if(n <= 1)return false; if(n<=3)return true; if(n%2==0||n%3==0)return false; 
    for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
    
bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}
    return false; }
    
bool isPowerOfTwo(int n){
    if(n==0)return false;
    return (ceil(log2(n)) == floor(log2(n)));}

inline int power(int a, int b, int m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res % m;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 1e9 + 7;
const int INF = LONG_LONG_MAX;

void solve() {
    int n,m; cin>>n>>m;

    vector<string> vs;
    vector<vector<char>> v(n,vector<char>(m));
    vector<vector<int>> vis(n,vector<int>(m,0));
    rep(i,n) {
        string s; cin>>s;
        vs.push_back(s);
    }
    rep(i,n) {
        rep(j,m) {
            v[i][j] = vs[i][j];
        }
    }
    int x,y,a,b;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            if(v[i][j] == 'A') x = i,y = j;
            else if(v[i][j] == 'B') a = i,b = j;
            else if(v[i][j] == '#') vis[i][j] = 1;
    
    queue<pair<int,int>> q;
    vector<vector<pair<int,int>>> path;
    path.resize(n);
    rep(i,n) path[i].resize(m);

    rep(i,n) rep(j,m) path[i][j] = {-1,-1};


    int dx[] = {-1,0,+1,0};
    int dy[] = {0,-1,0,+1};
    q.push({x,y});
    int cnt = 0;
    while(!q.empty()) {
        auto node = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int x = node.ff + dx[i];
            int y = node.ss + dy[i];
            if(x >= 0 and y >= 0 and x < n and y < m and !vis[x][y]) {
                q.push({x,y});
                vis[x][y] = 1;
                path[x][y] = {dx[i],dy[i]};
            }
        }
    }
    if(vis[a][b]) {
        vector<pair<int,int>> ans;
        pair<int,int> end = {a,b};
        while(end.ff != x or end.ss != y) {
            ans.push_back(path[end.ff][end.ss]);
            end.ff -= ans.back().ff;
            end.ss -= ans.back().ss;
        }
        cout<<ans.size()<<endl;
        reverse(all(ans));
        for(auto x : ans) {
            if(x.ff == 1) cout<<'D';
            else if(x.ff == -1) cout<<'U';
            else if(x.ss == 1) cout<<'R';
            else cout<<'L';
        }

    } else pn;
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