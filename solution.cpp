#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt") 
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define vvl vector<vector<ll>>
#define al vector<vll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define pci pair<char,int>
#define mi map<int,int>
#define mll map<ll,ll>
#define mci map<char,int>
#define fori(i, n) for(ll i=0; i<n; i++)
#define for1(i, n) for(ll i=1; i<n; i++)
#define forr(i,n) for(ll i=n-1; i>=0; i--)
#define forv(i,j,n) for(ll i=j; i<n; i++)
#define rep(i,j,n,k) for(ll i=j; i<n; i+=k)
#define repr(i,j,n) for(ll i=j; i>n; i--)
#define inputv(v,n) vll v(n); fori(i, n){ cin >> v[i];}
#define input1(v,n) vll v(n + 1); for1(i, n+1){ cin >> v[i];}
const int N = 1e5 + 5;
const int mod = 1e9;
#define MOD 998244353
const ll INF = 1e15;

void solve() {
    ll n;
    string s;
    cin >> n >> s;
    
    // Find the connected components in the string
    vector<ll> components;
    ll current_length = 1;
    
    // Process each position starting from the second character
    for (ll i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            // Continuing the same component
            current_length++;
        } else {
            // Found a boundary, store the length of the component
            components.push_back(current_length);
            current_length = 1;
        }
    }
    // Don't forget to add the last component
    components.push_back(current_length);
    
    // Calculate the number of possible arrangements
    ll result = 1;
    for (ll i = 0; i < components.size(); i++) {
        // If this is not the last component
        if (i < components.size() - 1) {
            // For each boundary between different runs (0s and 1s),
            // we can have 2 states (original or swapped)
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