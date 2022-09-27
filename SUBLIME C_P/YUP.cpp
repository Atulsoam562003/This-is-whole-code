#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long int
#define len(s) s.length()
#define rep(i,n) for (int i=0;i<n;i++)
#define repi(i,x,n) for (int i=x;i<n;i++)
#define br cout<<endl
#define pb push_back
#define endl '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;

const int N = 1e5 + 10;
vector<bool> isPrime(N,1);
vector<int> lp(N,0),hp(N,0);

// for storing divisors
// ith vector will store all divisors of i
vector<int> divisors[N];// array of vectors

void solve(){

    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < N; i++){
        if(isPrime[i]){
            lp[i] = hp[i] = i;
             for(int j = 2*i; j < N; j+=i){
                isPrime[j] = false;
                hp[j] = i;
                if(lp[j] == 0){
                    lp[j] = i;
                }
            }
        }
    }
    // // lowest prime and heighst prime
    // for(int i = 1; i < 100; i++){
    //     cout<<lp[i]<<' '<<hp[i]<<endl;
    // }
    int num; cin>>num;
    unordered_map<int,int> prime_factors;
    // O(log(n))
    /*
    so this is most prefered as compare to root n , as just preocompute and then find primes  in logN complexity :)
    */
    while(num > 1){
        int prime_factor = hp[num];
        while(num % prime_factor == 0){
            num /= prime_factor;
            prime_factors[prime_factor]++;
        }
    }
    for(auto factors : prime_factors){
        // first one is prime number and second one is count
        cout<<factors.first<<' '<<factors.second<<endl;
    }
    
    //* NOW DEAL WITH DIVISORS :)
    // it will not run for N = 1e7+10 but easily run for 
    // 1e5 + 10
    
    //* T => O(N(logN))
    for(int i = 2; i < N; i++){
             for(int j = i; j < N; j+=i){
                divisors[j].push_back(i);
            }
    }
    for(int i = 0; i <= 10; i++){
        for(int div : divisors[i]){
            cout<<div<<' ';
        }
        cout<<endl;
    }
    
}

int main(){
      fastio;
      solve();
}