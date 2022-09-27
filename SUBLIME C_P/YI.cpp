#include <bits/stdc++.h>
 
using namespace std;
 
bool solve() {
    int n;
    cin >> n;
    set<int> s;
    int previ;
    cin >> previ;
    s.insert(previ);
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
 
        auto left = s.lower_bound(x), right = s.upper_bound(x);
 
        // special cases when cant dereference the iterator
        if (right == s.end()) {
            auto it = s.find(previ);
            if (next(it) != s.end() && it != s.begin())
                return true;
            s.insert(x);
            previ = x;
            continue;
        }
 
        // symmetrical
        if (left == s.begin() && *left > x) {
            auto it = s.find(previ);
            if (next(it) != s.end() && it != s.begin())
                return true;
            s.insert(x);
            previ = x;
            continue;
        }
 
        // can dereference smaller or bigger
        --left; // smaller than x
        if (previ < *left || *right < previ)
            return true;
 
        s.insert(x);
        previ = x;
    }
 
    return false;
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << (solve() ? "yes" : "no") << "\n";
}