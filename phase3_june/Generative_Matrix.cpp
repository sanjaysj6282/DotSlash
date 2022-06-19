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
ll n, m, k, t;
string s, s1, s2;

ll Sum(ll n)
{
    ll c=2;
    ll ans=0;
    while(n>1)
    {
        if(n%c==0){
            // cout<<c<<" ";
            ans++;
            n/=c;
        }
        else c++;
    }

    return ans;
}

void solve(){
    cin >> n >> m;

    ll ans=0;
    rep(i, 1, n+1){
        rep(j, 1, m+1){
            cout << i+j << " ";
            cout << Sum(i+j) << " ";
            ans+=Sum(i+j);
            cout << ans << endl;
        }    
    }
}

int32_t main() {
    FAST;

    t=1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}