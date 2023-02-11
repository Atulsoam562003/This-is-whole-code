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
#define M 3
#define N 4


class Node {
public:
    char s;
    unordered_map<char,Node *> children;
    string word; // at each terminal char we form the final word which is formed.
    bool isTerminal;
    
    Node(char s) {
        this->s = s;
        isTerminal = false;
        word = "";
    }
};

class Trie {
public:
    Node * root;
    
    Trie() {
        root = new Node('\0');
    }
    void addWord(string word) {
        Node * temp = root;
        for(auto ch : word) {
            if(!temp->children.count(ch)) 
                temp->children[ch] = new Node(ch);
            temp = temp->children[ch];            
        }
        // now we are at last node.
        temp->isTerminal = true;
        temp->word = word;
    }
};

// main algorithm.(8 ways DFS + trie guided search)
void dfs(char board[M][N],Node*node,int i,int j,bool visited[][N],unordered_set<string>&output) {
    // base case.
    char ch = board[i][j];
    if(!node->children.count(ch)) 
        return;
    //other wise trie this node.
    visited[i][j] = true;
    node = node->children[ch];
    
    // if it is a termianl node in the trie.
    if(node->isTerminal) 
        output.insert(node->word);
    
    // explore the neighbours.
    int dx[] = {0,1,1,1,0,-1,-1,-1};
    int dy[] = {-1,-1,0,1,1,1,0,-1};
    
    for(int k = 0; k < 8; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        
        // if it is in bounds and not visited.
        if(ni >= 0 and nj >= 0 and ni < M and nj < N and !visited[ni][nj]) 
            dfs(board,node,ni,nj,visited,output);        
    }
    // last step. => backtracking.
    visited[i][j] = false;    
}


void solve() {    
    string words[] = {"SNAKE" , "FOR" , "QUEZ" , "SNACK" , "SNACKS", "GO" , "TUNES" ,"CAT"};
    
    char board[M][N] = {
        {'S','E' ,'R', 'T'},
        {'U' , 'N' ,'K' , 'S'},
        {'T' , 'C' , 'A' , 'T'} };
        
    //1. make trie.
    Trie t;
    for(auto word : words) 
        t.addWord(word);
    
    //2. take a container to store words un dfs search.
    unordered_set<string> output; // we don't want dublicates.
    
    //3. 8 way dfs seach from every sell.
    bool visited[M][N] = {0}; // we can initialize like this.
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            dfs(board,t.root,i,j,visited,output);
            //reset the visited array after each call. => in BACKTRACKING.
        }
    }
    //4. just print the output.
    for(auto word : output)
        cout<<word<<endl;
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