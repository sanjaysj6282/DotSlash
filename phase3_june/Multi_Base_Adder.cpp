#include <bits/stdc++.h>
using namespace std;

#define FAST {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

#define ll long long int
#define ld long double

#define pb push_back 
#define pi pair<ll, ll>
#define ff first
#define ss second
#define vi vector<ll> 
#define vb vector<bool>
#define vii vector<pi>
#define vvi vector<vi> 
#define mii map<ll, ll>
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define srt(v) sort(v.begin(), v.end())
#define setcnt(n) __builtin_popcount(n) // no of ones(set bits)
#define bitcnt(n) (int)log2(n) // no of bits

#define yy cout<<"YES\n"
#define nn cout<<"NO\n"
#define pre(a) {cout << fixed << setprecision(a);}
#define vect(v, n) {rep(i, 0, n){ll x; cin>>x; v.pb(x);}}

const int M=1e4+3, MOD=1e9+7;

ll gcd(ll a,ll b) {if(b==0) return a; return gcd(b,a%b); }
ll lcm(ll a,ll b) {return a/gcd(a,b)*b; }

// Declaring variables
ll n, base, m, k, t;
string s, s1, s2;


void solve(){
    cin >> base;
    string norep; cin >> norep;

    mii representation;
    rep(i, 0, base){
        representation[norep[i]]=i;
    }

    string n1; string n2;
    cin >> n1; cin >> n2;

    // rep(i, 0, n1.length()){
    //     cout << representation[n1[i]] << " ";
    // }

    
}

int32_t main() {
    FAST;

    t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}