#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long int
#define len(s) s.length()
#define endl  '\n'
#define rep(i,n) for (int i=0;i<n;i++)
#define repi(i,x,n) for (int i=x;i<n;i++)
#define br cout<<endl
#define pb push_back
#define endl '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;

bool isVowel(char ch){
    return ch == 'a' ||ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u';
}
vector<string> subsets(string s){
    int sz = (1<<s.size());
    vector<string> ans;
    rep(mask,sz){
        string subset;
        rep(bit,s.size()){
            if(mask & (1<<bit)) subset.push_back(s[bit]);
        }
        if(subset.size())ans.push_back(subset);
    } 
    return ans;
}

void solve(){
   int n; cin>>n;
   string str[n];
   
   rep(i,n) cin>>str[i];
   
   unordered_map<string,int> hsh;
   rep(i,n){
      set<char> distinct_vow;
      // for character ch in str of I
      for(char ch : str[i]){
          if(isVowel(ch)){
            distinct_vow.insert(ch);
          }
      }
      string vowel_str;
      for(char ch : distinct_vow){
        vowel_str.push_back(ch);
      }
      vector<string>all_subsets = subsets(vowel_str);
      for(string vowel_subset : all_subsets){
        hsh[vowel_subset]++;
      }
       // for(auto pr : hsh){
       //    cout<<pr.first<<' '<<pr.second<<endl;
       // }
     } 
          ll ans = 0;
            for(auto &pr :hsh){
                if(pr.second < 3) continue;
                ll ct = pr.second;
                ll ways = ct * (ct-1) * (ct-2) / 6;
                if(pr.first.size() % 2 == 0) ans -= ways;
                else ans += ways;
            }
        cout<<ans<<endl;
}

int main(){
        fastio;  
    int t; cin>>t;
    while(t--){
    solve();
    }
}   
