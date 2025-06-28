#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353

void solve() {
    ll n; string s;
    cin >> n >> s;
    
    vector<ll> components;
    ll current_length = 1;
    
    for (ll i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            current_length++;
        } else {
            components.push_back(current_length);
            current_length = 1;
        }
    }
    components.push_back(current_length);
    
    ll result = 1;
    for (ll i = 0; i < components.size(); i++) {
        if (i < components.size() - 1) {
            result = (result * 2) % MOD;
        }
    }
    
    cout << result << "\n";
}

int main() {
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
} 