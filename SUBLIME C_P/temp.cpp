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
#define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.ff << " " << x.ss << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

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
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 1e9 + 7;
const int INF = LONG_LONG_MAX;

bool isPoss(vector<int> v,vector<int> liya,int mid) {
    rep(i,mid) v.push_back(100);
    int start = v.size()/4;
    
    vector<int> temp(mid,0);
    rep(i,liya.size()) temp.push_back(liya[i]);
    
    int sum1 = accumulate(v.begin() + start,v.end(),0);
    int sum2 = accumulate(temp.begin() + start,temp.end(),0);
    return sum1 >= sum2;
}

void solve() {
    int n; cin>>n;
    vector<int> v(n),liya(n); for(auto &x : v) cin>>x;
    for(auto &x : liya) cin>>x;
    sort(all(v));
    sort(all(liya));
    
    int lo = 0;
    int hi = 1e5;
    int ans = 0;
    while(lo <= hi) {
        int mid = lo + (hi - lo)/ 2;
        if(isPoss(v,liya,mid)) ans = mid , hi = mid - 1;
        else lo = mid + 1;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    clock_t z = clock();

    int t = 1,i = 1;
    cin >> t;
    while (t--){  
          // cout<<"Case #"<<i++<<": "; 
          solve();    
    }

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}